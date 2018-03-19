#ifndef __LPC214x_PWMn_H_
#define __LPC214x_PWMn_H_

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/MemoryMappedRegister.h>

#include <HAL/Bits.h>

namespace LPC21xx{

template<	class HAL_Traits,
			class CommonPWMRegister,

			typename HAL_Traits::RegisterType pwmMRInterruptBit,
			typename HAL_Traits::RegisterType pwmMRIBit,
			typename HAL_Traits::RegisterType pwmMRRBit,
			typename HAL_Traits::RegisterType pwmMRSBit,
			typename HAL_Traits::RegisterType pwmSelectDoubleEdgedBit,
			typename HAL_Traits::RegisterType pwmEnableBit,
			typename HAL_Traits::RegisterType pwmLatchEnableBit
		> 
struct PWMn;

template<	class HAL_Traits,
			class PWM_MRn_
		>
struct CommonPWMnRegister;

}
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 1>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

    typedef HAL::MemoryMappedRegister<Traits, 0xE001401C> PWM_MRn;

	typedef LPC21xx::CommonPWMnRegister<Traits, PWM_MRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 2>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0014020> PWM_MRn;

	typedef LPC21xx::CommonPWMnRegister<Traits, PWM_MRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 3>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

    typedef HAL::MemoryMappedRegister<Traits, 0xE0014024> PWM_MRn;

	typedef LPC21xx::CommonPWMnRegister<Traits, PWM_MRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 4>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

    typedef HAL::MemoryMappedRegister<Traits, 0xE0014040> PWM_MRn;

	typedef LPC21xx::CommonPWMnRegister<Traits, PWM_MRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 5>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

    typedef HAL::MemoryMappedRegister<Traits, 0xE0014044> PWM_MRn;

	typedef LPC21xx::CommonPWMnRegister<Traits, PWM_MRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 6>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

    typedef HAL::MemoryMappedRegister<Traits, 0xE0014048> PWM_MRn;

	typedef LPC21xx::CommonPWMnRegister<Traits, PWM_MRn> type;
};
//=========================================================
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWM, 1>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef typename Create<CS<NO<HAL::PWMnRegister, 1>, ProzessorType>, ConfigRepository>
		::type PWMRegister;

    typedef 
		LPC21xx::PWMn<Traits, PWMRegister,
			Bit1, Bit3, Bit4, Bit5, Bit1, Bit9,	Bit1
	> type;
};
//=========================================================
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWM, 2>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef typename Create<CS<NO<HAL::PWMnRegister, 2>, ProzessorType>, ConfigRepository>
		::type PWMRegister;

    typedef
		LPC21xx::PWMn<Traits, PWMRegister,
			Bit2, Bit6, Bit7, Bit8, Bit2, Bit10, Bit2
	> type;
};
//=========================================================
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWM, 3>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef typename Create<CS<NO<HAL::PWMnRegister, 3>, ProzessorType>, ConfigRepository>
		::type PWMRegister;

    typedef
		LPC21xx::PWMn<Traits, PWMRegister,
			Bit3, Bit9, Bit10, Bit11, Bit3, Bit11, Bit3
	> type;
};
//=========================================================
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWM, 4>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef typename Create<CS<NO<HAL::PWMnRegister, 4>, ProzessorType>, ConfigRepository>
		::type PWMRegister;

    typedef
		LPC21xx::PWMn<Traits, PWMRegister,
			Bit8, Bit12, Bit13, Bit14, Bit4, Bit12, Bit4
	> type;
};
//=========================================================
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWM, 5>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef typename Create<CS<NO<HAL::PWMnRegister, 5>, ProzessorType>, ConfigRepository>
		::type PWMRegister;

    typedef
		LPC21xx::PWMn<Traits, PWMRegister,
			Bit9, Bit15, Bit16, Bit17, Bit5, Bit13, Bit5
	> type;
};
//=========================================================
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWM, 6>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef typename Create<CS<NO<HAL::PWMnRegister, 6>, ProzessorType>, ConfigRepository>
		::type PWMRegister;

    typedef
		LPC21xx::PWMn<Traits, PWMRegister,
			Bit10, Bit18, Bit19, Bit20, Bit6, Bit14, Bit6
	> type;
};
} // namespace Generator
//=========================================================
namespace LPC21xx{
template<
	class HAL_Traits,
	class PWM_MRn_
>
struct CommonPWMnRegister{
	typedef HAL_Traits Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0014000> PWM_IR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0014014> PWM_MCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE001404C> PWM_PCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0014050> PWM_LER;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0014018> PWM_MR0;

	typedef PWM_MRn_ PWM_MRn;
};

template<
	class HAL_Traits,
	class CommonPWMRegister,

	typename HAL_Traits::RegisterType pwmMRInterruptBit,
	typename HAL_Traits::RegisterType pwmMRIBit,
	typename HAL_Traits::RegisterType pwmMRRBit,
	typename HAL_Traits::RegisterType pwmMRSBit,
	typename HAL_Traits::RegisterType pwmSelectDoubleEdgedBit,
	typename HAL_Traits::RegisterType pwmEnableBit,
	typename HAL_Traits::RegisterType pwmLatchEnableBit
>
struct PWMn
{
	typedef typename CommonPWMRegister::PWM_IR PWM_IR;		//Interrupt Register
	typedef typename CommonPWMRegister::PWM_MCR PWM_MCR; 	//Match Control Register
	typedef typename CommonPWMRegister::PWM_PCR PWM_PCR;	//PWM Control Register (Double/Single Edged)
	typedef typename CommonPWMRegister::PWM_LER PWM_LER;	//Latch Enable Register
	typedef typename CommonPWMRegister::PWM_MR0 PWM_MR0;	//Match Register 0

	typedef typename CommonPWMRegister::PWM_MRn PWM_MRn;	//Match Register n

//****************************************************
// PWM_PCR
// PWM Control Register. Enables PWM outputs and selects PWM channel
// types as either single edge or double edge controlled
//****************************************************	
	static void enablePWMOutput() { // The PWM5 output enabled
	 	PWM_PCR::setBit(pwmEnableBit);
	}
	static void disablePWMOutput() {
	 	PWM_PCR::clearBit(pwmEnableBit);
	}
	static void singleEdgeControlled() {
	 	PWM_PCR::clearBit(pwmSelectDoubleEdgedBit);
	}
	static void doubleEdgeControlled() {
	 	PWM_PCR::setBit(pwmSelectDoubleEdgedBit);
	}
//****************************************************
// PWM_LER
//****************************************************
	//Wird disabled nach der Übertragung ins MatchRegister
	static void enableLatch() {
	 	PWM_LER::setBit(pwmLatchEnableBit);
	}
//****************************************************
// PWM_MCR
//****************************************************
	static void resetTC_OnMatch() {
	 	PWM_MCR::setBit(pwmMRRBit);
	}
//****************************************************
// PWM_MR5
//****************************************************
	static void setPWMHighRate(unsigned long pwmVal) {
		PWM_MRn::set(pwmVal);
	}
//****************************************************
// PWM_MR0 PWM_MR5 mit %
//****************************************************
	static void setPWMDutyRate(unsigned char pwmPercent) {
		unsigned long mr0Rate = PWM_MR0::read();

		unsigned long rate = (mr0Rate * pwmPercent) / 100;
		setPWMHighRate(rate);
	}
};
} // namespace LPC21xx
#endif //__LPC214x_PWMn_H_
