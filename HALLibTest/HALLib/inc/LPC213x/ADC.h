#ifndef __LPC213x_ADC_H_
#define __LPC213x_ADC_H_

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>

namespace Generator {
// TODO: AD0_0/5 nicht für alle LPC21xx zur verfügung stellen
/*template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD0, 0>, LPC213x::LPC2131>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC0Register, 0>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit0> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD0, 5>, LPC213x::LPC2131>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC0Register, 5>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit5> type;
};*/
} // namespace Generator

#endif // __LPC213x_ADC_H_
