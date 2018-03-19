#ifndef __LPC21XX_PLL_REGISTER_H__
#define __LPC21XX_PLL_REGISTER_H__

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/MemoryMappedRegister.h>
#include <LPC21xx/Traits.h>


//===================================================================
// PLL
//===================================================================
namespace LPC21xx {
template <class ProzessorType>
struct SCRegistersLPC21xx {
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	// Phase Locked Loop (PLL)
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC080>  PLLCON;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC084>  PLLCFG;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC088>  PLLSTAT;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC08C>  PLLFEED;
	// IntEnable/Disable wird benötigt um während des feeds alle
	// interrupts auszuschalten
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF010> IntEnable;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF014> IntEnClr;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<SS<HAL::PLL, HAL::Register>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef LPC21xx::SCRegistersLPC21xx<ProzessorType> type;
};
} // namespace Generator

#endif // __LPC21XX_PLL_REGISTER_H__
