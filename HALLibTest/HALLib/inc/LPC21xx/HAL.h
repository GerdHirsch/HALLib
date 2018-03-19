#ifndef LPC21xxHAL_H
#define LPC21xxHAL_H

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <LPC21xx/Types.h>
#include <LPC21xx/Traits.h>

#include <LPC21xx/Register.h>

#include <LPC21xx/PinConnectBlock.h>
#include <LPC21xx/ADC.h>
#include <LPC21xx/SPI.h>
#include <LPC21xx/PWM.h>
#include <LPC21xx/GPIO.h>
#include <LPC21xx/VIC.h>
#include <LPC21xx/Timer.h>
#include <LPC21xx/RTC.h>
#include <LPC21xx/SystemControl.h>
#include <LPC21xx/PowerControl.h>
#include <LPC21xx/PLL.h>
#include <LPC21xx/ExternalInterrupt.h>

namespace LPC21xx{
/*
 * Diese Komponenten stehen auf allen Prozessoren
 * der Familie LPC213x/4x zur verfügung
 * Komponenten die nur in einer Familie vorhanden sind, sind in den jeweiligen
 * HAL Implementierungen definiert.
 * Die Familie 3x definiert mehr Komponenten als die Familie 4x
 */

template<class ProzessorType_, class ConfigRep_>
struct HAL21x1 {
	typedef ProzessorType_ ProzessorType;
	typedef ConfigRep_ ConfigRep;

	typedef typename Generator::Create<
			Generator::CS<HAL::Traits, ProzessorType> >
	::type Traits;

	typedef typename Generator::Create<
			Generator::CS<HAL::PinConnectBlock, ProzessorType> >
	::type PinConnectBlock;


	typedef typename Generator::Create<
			Generator::CS<HAL::SystemControl, ProzessorType> >
	::type SC;
	typedef typename Generator::Create<
			Generator::CS<HAL::PowerControl, ProzessorType> >
	::type PowerControl;
	typedef typename Generator::Create<
			Generator::CS<HAL::PhaseLockedLoop, ProzessorType> >
	::type PhaseLockedLoop;

	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::GPIO, 0>, ProzessorType> >
	::type GPIO0;
	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::GPIO, 1>, ProzessorType> >
	::type GPIO1;

	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::ADC, 0>, ProzessorType> >
	::type ADC0;

	typedef typename Generator::Create<
			Generator::CS<HAL::ExternalInterrupt, ProzessorType> >
	::type EINT;

	typedef typename Generator::Create<
			Generator::CS<HAL::PWM, ProzessorType> >
	::type PWM;

	typedef typename Generator::Create<
			Generator::CS<HAL::RTC, ProzessorType> >
	::type RTC;

	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::Timer, 0>, ProzessorType> >
	::type Timer0;

	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::Timer, 1>, ProzessorType> >
	::type Timer1;

	typedef typename Generator::Create<
			Generator::CS<HAL::VIC, ProzessorType> >
	::type VIC;

	typedef typename Generator::Create<
			Generator::CS<HAL::WDT, ProzessorType> >
	::type WDT;


/*	TODO: componenten implementieren */
	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::UART, 0>, ProzessorType> >
	::type UART0;
	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::I2C, 0>, ProzessorType> >
	::type I2C0;
	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::I2C, 1>, ProzessorType> >
	::type I2C1;
	typedef typename Generator::Create<
			Generator::CS<HAL::SSP, ProzessorType> >
	::type SSP;
	typedef typename Generator::Create<
			Generator::CS<HAL::SPI, ProzessorType> >
	::type SPI;

};
template<class Base>
struct HAL21x2 : Base {
	typedef typename Base::ProzessorType ProzessorType;
	typedef typename Base::ConfigRep ConfigRep;

	typedef typename Generator::Create<
			Generator::CS<HAL::DAC, ProzessorType> >
	::type DAC;


};
template<class Base>
struct HAL21x4 : Base {
	typedef typename Base::ProzessorType ProzessorType;
	typedef typename Base::ConfigRep ConfigRep;

	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::ADC, 1>, ProzessorType> >
	::type ADC1;

	typedef typename Generator::Create<
			Generator::CS<Generator::NO<HAL::UART, 1>, ProzessorType> >
	::type UART1;
};

} // namespace LPC21xx

#endif //LPC21xxHAL_H
