/*
 * SCTestRegister.h
 *
 *  Created on: 30.12.2013
 *      Author: Gerd
 */

#ifndef SCTESTREGISTER_H_
#define SCTESTREGISTER_H_
#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HALMock/RegisterMock.h>
#include <HALMock/Types.h>

namespace Mock {
// External Interrupts (EXT)
extern unsigned long  EXTINT_;
extern unsigned long  EXTWAKE_;
extern unsigned long  EXTMODE_;
extern unsigned long  EXTPOLAR_;

// Memory Accelerator Module (MAM) (MEM?? siehe Doku)
extern unsigned long  MAMCR_;
extern unsigned long  MAMTIM_;
extern unsigned long  MAMMAP_;

// Phase Locked Loop (PLL)
extern unsigned long  PLLCON_;
extern unsigned long  PLLCFG_;
extern unsigned long  PLLSTAT_;
extern unsigned long  PLLFEED_;
// IntEnable/Disable wird benötigt um während des feeds alle
// interrupts auszuschalten
extern unsigned long IntEnable_;
extern unsigned long IntEnClr_;

// VPB Divider (APB Divider?? Doku)
extern unsigned long  VPBDIV_;

// Reset
extern unsigned long  RSIR_;

// Code Security/Debugging
extern unsigned long  CSPR_;

// System Controls and Status
extern unsigned long  SCS_;



template<class ProzessorType>
struct SCRegister{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	// External Interrupts (EXT)
	typedef Mock::RegisterMock<Traits, &EXTINT_>  EXTINT;
	typedef Mock::RegisterMock<Traits, &EXTWAKE_>  EXTWAKE;
	typedef Mock::RegisterMock<Traits, &EXTMODE_>  EXTMODE;
	typedef Mock::RegisterMock<Traits, &EXTPOLAR_>  EXTPOLAR;

	// Memory Accelerator Module (MAM) (MEM?? siehe Doku)
	typedef Mock::RegisterMock<Traits, &MAMCR_>  MAMCR;
	typedef Mock::RegisterMock<Traits, &MAMTIM_>  MAMTIM;
	typedef Mock::RegisterMock<Traits, &MAMMAP_>  MAMMAP;

	// Phase Locked Loop (PLL)
	typedef Mock::RegisterMock<Traits, &PLLCON_>  PLLCON;
	typedef Mock::RegisterMock<Traits, &PLLCFG_>  PLLCFG;
	typedef Mock::RegisterMock<Traits, &PLLSTAT_>  PLLSTAT;
	typedef Mock::RegisterMock<Traits, &PLLFEED_>  PLLFEED;
	// IntEnable/Disable wird benötigt um während des feeds alle
	// interrupts auszuschalten
	typedef Mock::RegisterMock<Traits, &IntEnable_> IntEnable;
	typedef Mock::RegisterMock<Traits, &IntEnClr_> IntEnClr;

	// VPB Divider (APB Divider?? Doku)
	typedef Mock::RegisterMock<Traits, &VPBDIV_>  VPBDIV;

	// Reset
	typedef Mock::RegisterMock<Traits, &RSIR_>  RSIR;

	// Code Security/Debugging
	typedef Mock::RegisterMock<Traits, &CSPR_>  CSPR;

	// System Controls and Status
	typedef Mock::RegisterMock<Traits, &SCS_>  SCS;
};
}//namespace Mock

//-------------------------------------------------------------------
namespace Generator {
// RTC
template<class Origin, class ConfigRepository>
struct Component<
	CS<SS<HAL::SystemControl, HAL::Register>, Mock::Base>,
	Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef Mock::SCRegister<ProzessorType> type;
};
} // namespace Generator

#endif /* SCTESTREGISTER_H_ */
