#ifndef PINCONNECTBLOCKLPC214X_H_
#define PINCONNECTBLOCKLPC214X_H_
/*
 * dieser header enthällt die definitionen
 * der PinConnectBlock Implementierungen für die LPC214x Familie
 * die Generatoren für diese Implementierungen
 */
#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <LPC21xx/PinConnectBlock.h>
#include <LPC214x/Types.h>

namespace LPC214x{
	template <class Base>
	struct PinConnectBlockLPC2141;
}

namespace Generator {
// Implemenentierung mit 44 -> x4 -> 42 -> x2 -> 41 -> x1
template<class Origin, class ConfigRepository>
struct Component<
	CS<HAL::PinConnectBlock, LPC214x::LPC2141>,
	Origin,
	ConfigRepository>
{
	typedef  CS<HAL::PinConnectBlock, LPC214x::LPC2141> current_selector;

	typedef typename Origin::template BaseType<current_selector>
		::type base_type;

	typedef typename Create<base_type, ConfigRepository, Origin>::type PCB214Base;

	typedef LPC214x::PinConnectBlockLPC2141<PCB214Base> type;
};

//template<class Origin, class ConfigRepository>
//struct Component<
//	CS<HAL::PinConnectBlock, LPC214x::LPC2141>,
//	Origin,
//	ConfigRepository>
//{
//	typedef typename Origin::template getSelector<>::type ProzessorType;
//	typedef CS<HAL::PCBRegister, ProzessorType> RegisterContext;
//
//	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type Base;
//
//	typedef LPC21xx::PinConnectBlockBaseLPC21xx<Base> PCB214Base;
//
//	typedef LPC214x::PinConnectBlockLPC2141<PCB214Base> type;
//};
//--------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::PinConnectBlock, LPC214x::LPC2142>, Origin, ConfigRepository>
{
	typedef typename Origin::template
			BaseType<CS<HAL::PinConnectBlock, LPC214x::LPC2142> >::type BaseType;

	typedef typename Create<BaseType, ConfigRepository, Origin>
		::type PCBLPC2141;

	typedef LPC21xx::PinConnectBlockLPC21x2<PCBLPC2141> type;
};
//--------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::PinConnectBlock, LPC214x::LPC2144>, Origin, ConfigRepository>
{
	typedef typename Origin::template
			BaseType<CS<HAL::PinConnectBlock, LPC214x::LPC2144> >::type BaseType;

	typedef typename Create<BaseType, ConfigRepository, Origin>
		::type PCBLPC2142;

	typedef LPC21xx::PinConnectBlockLPC21x4<PCBLPC2142> type;
};
} // namespace Generator

namespace LPC214x {

template <class Base>
struct PinConnectBlockLPC2141 : Base {
	typedef typename Base::PinSel_1 PinSel_1;

	// -----------------------------------
	// P0_23
	// -----------------------------------
	class P0_23 {
		typedef HAL::PinMapper<23, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> VBus;
	};
	// -----------------------------------
	// P0_31
	// -----------------------------------
	class P0_31 {
		typedef HAL::PinMapper<31, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPO_Only;
		typedef typename this_pin::template Device<1> UP_LED;
		typedef typename this_pin::template Device<2> CONNECT;
	};
};

} // namespace LPC214x

#endif /* PINCONNECTBLOCKLPC214X_H_ */
