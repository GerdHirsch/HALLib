#ifndef __LPC21XX_PLL_H__
#define __LPC21XX_PLL_H__

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <HAL/MemoryMappedRegister.h>

#include <LPC21xx/Types.h>
#include <LPC21xx/Traits.h>

namespace LPC21xx {
template <class Register, class Hal>
struct PLL;
}

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::PhaseLockedLoop, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProcessorType;
	typedef typename Create<ProcessorType>::type Hal;
	typedef CS<SS<HAL::PhaseLockedLoop, HAL::Register>, ProcessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type Register;

	typedef LPC21xx::PLL<Register, Hal> type;
};
} // namespace Generator

namespace LPC21xx {

template <class Register, class Hal>
struct PLL {
	typedef typename Register::Traits Traits;
	typedef typename Traits::ProcessorType ProcessorType;
	typedef typename Traits::RegisterType RegisterType;
	typedef typename Traits::ValueType ValueType;

//===================================================================
// Phase Locked Loop
//===================================================================
	// TODO: Magic number 3689350 ist Abweichung von Fosc der Doku
	// vielleicht durch messung mit rtc bestimmen
	/*!
	 * \return Frequency of pysical oscillator
	 */
	static ValueType Fosc(){
		static ValueType fosc = 14745600/*14745600 + 3689350*/;
		return fosc;
	}

	/*!
	 * sets the pll speed to desired MHz and activates the MAM if required
	 * pll needs to be enabled and connected to run at desiredCCLK
	 * if disabled CCLK equals Fosc
	 */
	static void setPLLSpeedInMHz(unsigned int desiredCCLK){
		double dcclk = desiredCCLK * 1000000.0;

		const unsigned int fosc = Fosc();


		// calculate best fitting multiplier for desired CCLK by dividing by Fosc
		unsigned int m = static_cast<int>((dcclk / fosc) + 0.5 /*TODO:auch aufrunden?*/);
		// TODO: maximaler multiplier als parameter übergeben
		// in practice, the multiplier value cannot be smaller than 1 and higher than 5
		// on the LPC213x due to the upper frequency limit of the CPU
		if(m < 1) m = 1;
		if(m > 5) m = 5;

		// Fcco must be in the range of 156 MHz to 320 MHz controlled by the divider p
		const unsigned int FccoMIN = 156000000;
		const unsigned int FccoMAX = 320000000;
		// p may be set to 2, 4, 8, 16 (2 * (0x1<<i))
		unsigned int p=0;
		// find smallest p fulfilling the condition
		for(unsigned int i = 0; i < 4; ++i){
			unsigned int Fcco = fosc * m * 2 * (0x1<<i);
			if(FccoMIN <= Fcco && Fcco <= FccoMAX){
				p = i;
				break;
			}
		}
		// set calculated values and give the necessary feed command
		Register::PLLCFG::set( (p<<5) | (m - 1) ); // PSEL[6,5],MSEL[4,0]
//		feed();

		// activate MAM due to fulfill condition for memory access frequency
//		activateMAM();
	}

	static void enablePLL(){
		Register::PLLCON::setBit(Bit0);
//		feed();
		// Wait for the PLL to lock
//		while(!Register::PLLSTAT::readBit(Bit10)); // Bit10 = PLOCK
	}
	static void connectEnabledPLL(){
		Register::PLLCON::setBit(Bit0|Bit1);
//		feed();
	}

	static void disconnectPLL(){
		Register::PLLCON::setBit(Bit0);
		Register::PLLCON::clearBit(Bit1);
//		feed();
	}
	static void disableDisconnectedPLL(){
		Register::PLLCON::clearBit(Bit1|Bit0);
//		feed();
		// Wait for the PLL to lock
//		while(Register::PLLSTAT::readBit(Bit10)); // Bit10 = PLOCK
	}

	static void waitForPLLLock(){
		while(Register::PLLSTAT::readBit(Bit10)); // Bit10 = PLOCK
	}
	/*!
	 * während dem feed dürfen keine interrupts ausgelöst werden
	 * Alle Interrupts müssen vorher deaktiviert werden
	 * \see VIC::disableAllInterrupts(), VIC::enableInterrupts
	 * \code
	 * ValueType interrupts = VIC::disabelAllInterrupts();
	 * PLL::feed();
	 * if(interrupts) VIC::enableInterrupts(interrupts);
	 * \endcode
	 */
	static void feed(){
//		ValueType interrupts = Register::IntEnable::read();
//		if(interrupts) Register::IntEnClr::set(AllBits);
		Register::PLLFEED::set(0xAA);
		Register::PLLFEED::set(0x55);
//		if(interrupts) Register::IntEnable::set(interrupts);
	}

	/*!
	 * \return multiplier value for PLL (Phase Locked Loop)
	 */
	static unsigned int getMSEL(){
		//
		return (Register::PLLSTAT::readBit(Bit4|Bit3|Bit2|Bit1|Bit0) + 1);
	}
	/*!
	 * \return divider value for CCO (Current Controlled Oscillator) for specific CCLK
	 */
	static unsigned int getPSEL(){
		return 0x1 << (Register::PLLSTAT::readBit(Bit6|Bit5) >> 5);
	}

	/*!
	 * \return one if PLL (Phase Locked Loop) is enabled
	 */
	static bool isPLLEnabled(){
		return Register::PLLSTAT::readBit(Bit8);
	}
	/*!
	 * \return one if PLL (Phase Locked Loop) is connected
	 */
	static bool isPLLConnected(){
		return Register::PLLSTAT::readBit(Bit9);
	}

};

} // namespace LPC21xx


#endif /* __LPC21XX_PLL_H__ */
