/*
 * SCTestRegister.h
 *
 *  Created on: 30.12.2013
 *      Author: Gerd
 */

#ifndef PLLTESTREGISTER_H_
#define PLLTESTREGISTER_H_
#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HALMock/RegisterMock.h>
#include <HALMock/Types.h>

namespace Mock {
// Phase Locked Loop (PLL)
extern unsigned long  PLLCON_;
extern unsigned long  PLLCFG_;
extern unsigned long  PLLSTAT_;
extern unsigned long  PLLFEED_;
// IntEnable/Disable wird benötigt um während des feeds alle
// interrupts auszuschalten
extern unsigned long IntEnable_;
extern unsigned long IntEnClr_;

template<class ProzessorType>
struct PLLRegister{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	// Phase Locked Loop (PLL)
	typedef Mock::RegisterMock<Traits, &PLLCON_>  PLLCON;
	typedef Mock::RegisterMock<Traits, &PLLCFG_>  PLLCFG;
	typedef Mock::RegisterMock<Traits, &PLLSTAT_>  PLLSTAT;
	typedef Mock::RegisterMock<Traits, &PLLFEED_>  PLLFEED;
	// IntEnable/Disable wird benötigt um während des feeds alle
	// interrupts auszuschalten
	typedef Mock::RegisterMock<Traits, &IntEnable_> IntEnable;
	typedef Mock::RegisterMock<Traits, &IntEnClr_> IntEnClr;
};
}//namespace Mock

//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<
	CS<SS<HAL::PhaseLockedLoop, HAL::Register>, Mock::Base>,
	Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef Mock::PLLRegister<ProzessorType> type;
};
} // namespace Generator

#endif /* PLLTESTREGISTER_H_ */
