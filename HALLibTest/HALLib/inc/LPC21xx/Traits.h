#ifndef __LPC21xx_TRAITS_H_
#define __LPC21xx_TRAITS_H_

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>

#include <LPC21xx/Types.h>

namespace LPC21xx
{
	template <class ProcessorType_>
	struct LPC21xxTraits
	{
		typedef ProcessorType_ ProcessorType;
		typedef unsigned long ValueType;
		typedef ValueType RegisterAddressType;
		typedef volatile ValueType RegisterType;
//		typedef volatile unsigned long RegisterType;
	};
}

namespace Generator {
	template<class Origin, class ConfigRepository>
	struct Component<CS<HAL::Traits, LPC21xx::Base>, Origin, ConfigRepository>
	{
		typedef typename Origin::template getSelector<>::type ProzessorType;
		typedef LPC21xx::LPC21xxTraits<ProzessorType> type;
	};
} // namespace Generator

#endif //__LPC21xx_TRAITS_H_
