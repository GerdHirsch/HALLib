#ifndef __LPC21XX_EXTERNALINTERRUPT_H_
#define __LPC21XX_EXTERNALINTERRUPT_H_


#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <HAL/MemoryMappedRegister.h>

#include <LPC21xx/Types.h>
#include <LPC21xx/Traits.h>

namespace LPC21xx {
template <class Registers>
struct ExternalInterrupt;
}

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::ExternalInterrupt, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::EINTRegister, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type Register;

	typedef LPC21xx::ExternalInterrupt<Register> type;
};
} // namespace Generator


namespace LPC21xx {

template <class Registers>
struct ExternalInterrupt {

	typedef typename Registers::Traits Traits;
	typedef typename Traits::ValueType ValueType;

	//=================================================================
	//Sensitivity Policies
	//=================================================================
	struct LowLevel{
		static void init(ValueType value){
			Registers::EXTMODE::clearBit(value);
			Registers::EXTPOLAR::clearBit(value);
		}
	};
	struct HighLevel{
		static void init(ValueType value){
			Registers::EXTMODE::clearBit(value);
			Registers::EXTPOLAR::setBit(value);
		}
	};
	struct FallingEdge{
		static void init(ValueType value){
			Registers::EXTMODE::setBit(value);
			Registers::EXTPOLAR::clearBit(value);
		}

	};
	struct RisingEdge{
		static void init(ValueType value){
			Registers::EXTMODE::setBit(value);
			Registers::EXTPOLAR::setBit(value);
		}

	};


	enum{ eint0 = Bit0, eint1 = Bit1, eint2 = Bit2, eint3 = Bit3,
		allEints = Bit0|Bit1|Bit2|Bit3};

	static void clearAllInterruptFlags(ValueType eints = allEints){
		Registers::EXTINT::setBit(eints);
	}
	static bool isInterruptSource(ValueType eints = allEints){
			return Registers::EXTINT::readBit(eints);
	}

	template<
			unsigned int EINTNo, class Sensitivity = FallingEdge
			>
	struct EINT{
		enum { No = EINTNo, value = 0x1<<EINTNo};

		static void clearInterruptFlag(){
			Registers::EXTINT::setBit(value);
		}
		static bool isInterruptSource(){
			return Registers::EXTINT::readBit(value);
		}
		static void init(){
			Sensitivity::init(value);
		}
	};
};
} // namespace LPC21xx

#endif /* __LPC21XX_EXTERNALINTERRUPT_H_ */
