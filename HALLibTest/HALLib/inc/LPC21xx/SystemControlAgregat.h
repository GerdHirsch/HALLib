#ifndef __LPC21XX_SYSTEMCONTROL_H__
#define __LPC21XX_SYSTEMCONTROL_H__

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <HAL/MemoryMappedRegister.h>

#include <LPC21xx/Types.h>
#include <LPC21xx/Traits.h>

namespace LPC21xx {
template <class Hal>
struct SC;
}

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::SystemControl, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProcessorType;
	typedef typename Create<ProcessorType>::type Hal;

	typedef LPC21xx::SC<Hal> type;
};
} // namespace Generator

namespace LPC21xx {

namespace SC_Private{

template <class Hal>
struct SC {
	typedef typename Hal::PhaseLockedLoop PLL;
	typedef typename Hal::MAM MAM;


};

} // namespace LPC21xx


#endif /* __LPC21XX_SYSTEMCONTROL_H__ */
