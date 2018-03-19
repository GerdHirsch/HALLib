#ifndef __LPC214x_PWM_H_
#define __LPC214x_PWM_H_

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>

#include <HAL/Bits.h>
#include <LPC21xx/PWMn.h>

//forward declaration
namespace LPC21xx{

template<   class HAL_Traits,
			class PWMRegister
		> struct PWM;

template<
			class HAL_Traits,

			class PWM_IR,
			class PWM_TCR,
			class PWM_TC,
			class PWM_PR,
			class PWM_PC,
			class PWM_MCR,
			class PWM_LER,
			class PWM_MR0
		> struct CommonPWMRegister;
} // namespace LCP21xx

namespace Generator {
//=========================================================
template<class Origin, class ConfigRepository>
struct Component<CS<SS<HAL::PWM, HAL::Register>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0014000> PWM_IR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0014004> PWM_TCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0014008> PWM_TC;
	typedef HAL::MemoryMappedRegister<Traits, 0xE001400C> PWM_PR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0014010> PWM_PC;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0014014> PWM_MCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0014050> PWM_LER;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0014018> PWM_MR0;

	typedef LPC21xx::CommonPWMRegister
	<
		Traits, PWM_IR, PWM_TCR, PWM_TC, PWM_PR, PWM_PC, PWM_MCR, PWM_LER, PWM_MR0
	> type;
};
//=========================================================
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::PWM, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>
		::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;
	typedef typename Create<CS<SS<HAL::PWM, HAL::Register>, ProzessorType>, ConfigRepository>
		::type Register;
    typedef LPC21xx::PWM<Traits, Register>
    	type;
};
} // namespace Generator
//=========================================================
namespace LPC21xx{
template<
			class HAL_Traits,

			class PWM_IR_,
			class PWM_TCR_,
			class PWM_TC_,
			class PWM_PR_,
			class PWM_PC_,
			class PWM_MCR_,
			class PWM_LER_,
			class PWM_MR0_
> struct CommonPWMRegister
{
	typedef HAL_Traits Traits;

	typedef PWM_IR_ PWM_IR;
	typedef PWM_TCR_ PWM_TCR;
	typedef PWM_TC_ PWM_TC;
	typedef PWM_PR_ PWM_PR;
	typedef PWM_PC_ PWM_PC;
	typedef PWM_MCR_ PWM_MCR;
	typedef PWM_LER_ PWM_LER;
	typedef PWM_MR0_ PWM_MR0;
};


template<   class HAL_Traits,
			class PWMRegister
		>
struct PWM{

	typedef typename PWMRegister::PWM_IR PWM_IR;
	typedef typename PWMRegister::PWM_TCR PWM_TCR;
	typedef typename PWMRegister::PWM_TC PWM_TC;
	typedef typename PWMRegister::PWM_PR PWM_PR;
	typedef typename PWMRegister::PWM_PC PWM_PC;
	typedef typename PWMRegister::PWM_MCR PWM_MCR;
	typedef typename PWMRegister::PWM_LER PWM_LER;
	typedef typename PWMRegister::PWM_MR0 PWM_MR0;

	typedef typename HAL_Traits::ProcessorType ProcessorType;

	typedef typename Generator::Create<Generator::CS<Generator::NO<HAL::PWM, 1>, ProcessorType> >
		::type PWM1;
	typedef typename Generator::Create<Generator::CS<Generator::NO<HAL::PWM, 2>, ProcessorType> >
		::type PWM2;
	typedef typename Generator::Create<Generator::CS<Generator::NO<HAL::PWM, 3>, ProcessorType> >
		::type PWM3;
	typedef typename Generator::Create<Generator::CS<Generator::NO<HAL::PWM, 4>, ProcessorType> >
		::type PWM4;
	typedef typename Generator::Create<Generator::CS<Generator::NO<HAL::PWM, 5>, ProcessorType> >
		::type PWM5;
	typedef typename Generator::Create<Generator::CS<Generator::NO<HAL::PWM, 6>, ProcessorType> >
		::type PWM6;
//****************************************************
// PWM_TCR
// PWM Timer Control Register. The PWMTCR is used to control the Timer
// Counter functions. The Timer Counter can be disabled or reset through
// the PWMTCR Bit 1: Counter Enable, Bit 3: PWM mode is enabled
//****************************************************
	static void enablePWM() {
	 	PWM_TCR::setBit(Bit3);
	}
	static void disablePWM() {
	 	PWM_TCR::clearBit(Bit3);
	}
	static void enableCounter() {
	 	PWM_TCR::setBit(Bit0);
	}
	static void disableCounter() {
	 	PWM_TCR::clearBit(Bit0);
	}
	static void resetCounter() {
	 	PWM_TCR::setBit(Bit1);
	}
//****************************************************
// PWM_PR
//****************************************************
	static void setPrescale(unsigned long divisor){
	 	PWM_PR::set(divisor);
	}
//****************************************************
// PWM_LER
//****************************************************
	static void enableLatch() {
	 	PWM_LER::setBit(Bit0);
	}
//****************************************************
// PWM_MCR
//****************************************************
	static void resetTC_OnMatch() {
	 	PWM_MCR::setBit(Bit1);
	}
//****************************************************
// PWM_MR0
//****************************************************
	static void setPWMRate(unsigned long pwmVal) {
	 	PWM_MR0::set(pwmVal);
	}
	static unsigned long getPWMRate() {
	 	return PWM_MR0::read();
	}
//****************************************************
};
}
#endif //__LPC214x_PWM_H_
