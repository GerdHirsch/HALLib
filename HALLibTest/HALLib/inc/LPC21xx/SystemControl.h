#ifndef __LPC21XX_SYSTEMCONTROL_H__
#define __LPC21XX_SYSTEMCONTROL_H__

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <HAL/MemoryMappedRegister.h>

#include <LPC21xx/Types.h>
#include <LPC21xx/Traits.h>

namespace LPC21xx {
template <class Register, class Hal>
struct SC;
}

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::SystemControl, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProcessorType;
	typedef typename Create<ProcessorType>::type Hal;
	typedef CS<SS<HAL::SystemControl, HAL::Register>, ProcessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type Register;

	typedef LPC21xx::SC<Register, Hal> type;
};
} // namespace Generator

namespace LPC21xx {

namespace SC_Private{

template<class Device, class Hal_>
struct DeviceBit;
} // end namespace SC_Private

template <class Register, class Hal>
struct SC {
	typedef typename Register::Traits Traits;
	typedef typename Traits::ProcessorType ProcessorType;
	typedef typename Traits::RegisterType RegisterType;
	typedef typename Traits::ValueType ValueType;
	//===================================================================
	// PowerControl
	//===================================================================
private:
	// DeviceBit::value Abbildungsfunktion Typ->SystemControl DeviceBit
	template<class Device, class Hal_ = Hal>
	struct DeviceBit : SC_Private::DeviceBit<Device, Hal_>{};
//	template<class Device, class dummy = int>
//	struct DeviceBit;

//	template<class dummy>
//	struct DeviceBit<typename Hal::Timer0, dummy>{
//		enum{value = Bit1};
//	};
public:
		template<class DeviceType>
		static bool isConnectedPCLK(){
			return Register::PCONP::readBit(DeviceBit<DeviceType>::value);
		}
		/*! Note: Clear the PDN bit in the AD0CR before clearing this
		 * bit, and set this bit before setting PDN. */
		template<class DeviceType>
		static void disconnectPCLK(){
			Register::PCONP::clearBit(DeviceBit<DeviceType>::value);
		}

		/*! Note: Clear the PDN bit in the AD0CR before clearing this
		 * bit, and set this bit before setting PDN. */
		template<class DeviceType>
		static void connectPCLK(){
			Register::PCONP::setBit(DeviceBit<DeviceType>::value);
		}



//	enum { Fosc = 14745600 };
/*
 * wird in systemDiagnisticOutputDemo ansatzweise verifiziert
 */
//===================================================================
// Memory Mapping Control (Memory Accelerator Module)
//===================================================================
	// if cclk <= 20 Mhz then MAMTIM=1
	// if cclk 20-40 Mhz then MAMTIM=2
	// if cclk 40-60 Mhz then MAMTIM=3
	// if cclk >= 60 Mhz then MAMTIM=4
	static void activateMAM(){
		const unsigned int MAXFlashAccessFreq = 20000000;
		//switch OFF MAM before adjusting timing
		Register::MAMCR::set(NoneBits);
		if(CCLK() < MAXFlashAccessFreq){
			Register::MAMTIM::set(1);
		} else {
			// MAM-Fetch cycle
			// RegisterType flashFetchCycle;
			for(unsigned int flashFetchCycle = 2; flashFetchCycle <= 7; ++flashFetchCycle){
				if(CCLK()/flashFetchCycle < MAXFlashAccessFreq){
					Register::MAMTIM::set(flashFetchCycle);
					break;
				}
			}
			// TODO: nur activieren wenn notwendig
			// MAMCR = 0 – MAM is OFF (all instructions are read directly from Flash memory)
			// MAMCR = 1 – partially enables MAM (sequential instructions are accessed using MAM
			// 				while branches and constants are accessed directly from Flash)
			// MAMCR = 2 - Activate MAM (all memory fetching from MAM)
			Register::MAMCR::set(Bit1);
		}
	}

	static unsigned int getMAMTIM(){
		return Register::MAMTIM::read();
	}
	static unsigned int getMAMCR(){
		return Register::MAMCR::read();
	}
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
	 * \return Frequency for peripheral devices (is fraction of CCLK; default one fourth)
	 */
	static ValueType PCLK(){
		ValueType pclk = CCLK() / getVPBDIV();
		return pclk;
	}
	/*!
	 * \return Frequency for ARM processor out of Current Controlled Oscillator (CCO)
	 * Equals Fosc if Phase Locked Loop (PLL) is deactivated
	 */
	static ValueType CCLK(){
		ValueType cclk = Fosc();
		if(getPLLE() & getPLLC())
			cclk *= getMSEL();
		return cclk;
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
		feed();
		// activate MAM due to fulfill condition for memory access frequency
		activateMAM();
	}

	static void enableAndConnectPLL(){
		enablePLL();
		connectEnabledPLL();
		activateMAM();
	}
	static void disconnectAndDisablePLL(){
		disconnectPLL();
		disableDisconnectedPLL();
		activateMAM();
	}

	static void enablePLL(){
		Register::PLLCON::setBit(Bit0);
		feed();
		// Wait for the PLL to lock
		while(!Register::PLLSTAT::readBit(Bit10)); // Bit10 = PLOCK
	}
	static void connectEnabledPLL(){
		Register::PLLCON::setBit(Bit0|Bit1);
		feed();
	}

	static void disconnectPLL(){
		Register::PLLCON::setBit(Bit0);
		Register::PLLCON::clearBit(Bit1);
		feed();
	}
	static void disableDisconnectedPLL(){
		Register::PLLCON::clearBit(Bit1|Bit0);
		feed();
		// Wait for the PLL to lock
		while(Register::PLLSTAT::readBit(Bit10)); // Bit10 = PLOCK
	}

	static void feed(){
		ValueType interrupts = Register::IntEnable::read();
		if(interrupts) Register::IntEnClr::set(AllBits);
		Register::PLLFEED::set(0xAA);
		Register::PLLFEED::set(0x55);
		if(interrupts) Register::IntEnable::set(interrupts);
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
	static unsigned int getPLLE(){
		return Register::PLLSTAT::readBit(Bit8) >> 8;
	}
	/*!
	 * \return one if PLL (Phase Locked Loop) is connected
	 */
	static unsigned int getPLLC(){
		return Register::PLLSTAT::readBit(Bit9) >> 9;
	}


//===================================================================
// APB Divider
//===================================================================
	enum { PCLKMAX = 60000000, PCLKMIN = 10000000 };

	/*!
	 * sets periferal clock (PCLK) to one fourth of ARM Core frequency (CCLK)
	 */
	static void setPCLKToOneFourthOfCCLK(){
		if(CCLK()/4 > PCLKMIN){
			Register::VPBDIV::clearBit(Bit1|Bit0);
		} else {
			setPCLKToOneHalfOfCCLK();
		}
	}

	/*!
	 * sets periferal clock (PCLK) to ARM Core frequency (CCLK)
	 */
	static void setPCLKToCCLK(){
		if(CCLK() < PCLKMAX){
			Register::VPBDIV::clearBit(Bit1);
			Register::VPBDIV::setBit(Bit0);
		} else {
			setPCLKToOneHalfOfCCLK();
		}
	}

	/*!
	 * sets periferal clock (PCLK) to one half of core frequency (CCLK)
	 */
	static void setPCLKToOneHalfOfCCLK(){
		if(CCLK()/2 > PCLKMIN){
			Register::VPBDIV::clearBit(Bit0);
			Register::VPBDIV::setBit(Bit1);
		} else {
			setPCLKToCCLK();
		}
	}

	/*!
	 * \return current divider for calculating PCLK aut of CCLK
	 */
	static ValueType getVPBDIV(){
		switch(Register::VPBDIV::readBit(Bit1|Bit0)){
			case Bit0:
				return 1;
			case Bit1:
				return 2;
			default:
				return 4;
		}
	}
};

namespace SC_Private{
template<class Hal>
struct DeviceBit<typename Hal::Timer0, Hal>{
	enum{value = Bit1};
};
template<class Hal>
struct DeviceBit<typename Hal::Timer1, Hal>{
	enum{value = Bit2};
};
template<class Hal>
struct DeviceBit<typename Hal::UART0, Hal>{
	enum{value = Bit3};
};
template<class Hal>
struct DeviceBit<typename Hal::UART1, Hal>{
	enum{value = Bit4};
};
template<class Hal>
struct DeviceBit<typename Hal::PWM, Hal>{
	enum{value = Bit5};
};
//Reserved Bit6
template<class Hal>
struct DeviceBit<typename Hal::I2C0, Hal>{
	enum{value = Bit7};
};
template<class Hal>
struct DeviceBit<typename Hal::SPI, Hal>{
	enum{value = Bit8};
};
template<class Hal>
struct DeviceBit<typename Hal::RTC, Hal>{
	enum{value = Bit9};
};
template<class Hal>
struct DeviceBit<typename Hal::SSP, Hal>{
	enum{value = Bit10};
};
//Reserved Bit11
template<class Hal>
struct DeviceBit<typename Hal::ADC0, Hal>{
	enum{value = Bit12};
};
//Reserved Bit13 bis Bit18
template<class Hal>
struct DeviceBit<typename Hal::I2C1, Hal>{
	enum{value = Bit19};
};
} // end namespace SC_Private

} // namespace LPC21xx


#endif /* __LPC21XX_SYSTEMCONTROL_H__ */
