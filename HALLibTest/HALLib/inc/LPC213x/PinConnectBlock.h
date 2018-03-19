#ifndef __LPC213x_PINCONNECTBLOCK_H_
#define __LPC213x_PINCONNECTBLOCK_H_

#include <HAL/PinConnectBlockTemplates.h>

#include <LPC21xx/PinConnectBlock.h>
#include <LPC213x/Types.h>

namespace LPC213x{
template <class Base>
struct PinConnectBlockLPC2131;
}

namespace Generator {
// Implemenentierung mit 34 -> x4 -> 32 -> x2 -> 31 -> x1
template<class Origin, class ConfigRepository>
struct Component<
	CS<HAL::PinConnectBlock, LPC213x::LPC2131>,
	Origin,
	ConfigRepository>
{
	typedef  CS<HAL::PinConnectBlock, LPC213x::LPC2131> current_selector;

	typedef typename Origin::template BaseType<current_selector>
		::type base_type;

	typedef typename Create<base_type, ConfigRepository, Origin>::type PCB213Base;

	typedef LPC213x::PinConnectBlockLPC2131<PCB213Base> type;
};
//Implementierung mit 34 -> 32 -> 31
//template<class Origin, class ConfigRepository>
//struct Component<CS<HAL::PinConnectBlock, LPC213x::LPC2131>, Origin, ConfigRepository>
//{
//	typedef typename Origin::Selector ProzessorType;
//	typedef CS<HAL::PCBRegister, ProzessorType> RegisterContext;
//
//	typedef typename Create<RegisterContext, ConfigRepository>::type PCBRegister;
//
//	typedef LPC21xx::PinConnectBlockBaseLPC21xx<PCBRegister> PCB213Base;
//
//	typedef LPC213x::PinConnectBlockLPC2131<PCB213Base> type;
//};
//
//--------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::PinConnectBlock, LPC213x::LPC2132>, Origin, ConfigRepository>
{
	typedef typename Origin::template
			BaseType<CS<HAL::PinConnectBlock, LPC213x::LPC2132> >::type BaseType;

	typedef typename Create<BaseType, ConfigRepository, Origin>
		::type PCBLPC2131;

	typedef LPC21xx::PinConnectBlockLPC21x2<PCBLPC2131> type;
};

//--------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::PinConnectBlock, LPC213x::LPC2134>, Origin, ConfigRepository>
{
	typedef typename Origin::template
			BaseType<CS<HAL::PinConnectBlock, LPC213x::LPC2134> >::type BaseType;

	typedef typename Create<BaseType, ConfigRepository, Origin>
		::type PCBLPC2132;

	typedef LPC21xx::PinConnectBlockLPC21x4 < PCBLPC2132 > type;
};
} // namespace Generator


namespace LPC213x{

template <class Base>
struct PinConnectBlockLPC2131 : Base {
	typedef typename Base::PinSel_0 PinSel_0;
	typedef typename Base::PinSel_1 PinSel_1;
	typedef typename Base::PinSel_2 PinSel_2;

	// -----------------------------------
	// P0_26
	// -----------------------------------
	class P0_26 {
		typedef HAL::PinMapper<26, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> AD0_5;
	};
	// -----------------------------------
	// P0_27
	// -----------------------------------
	class P0_27 {
		typedef HAL::PinMapper<27, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> AD0_0;
		typedef typename this_pin::template Device<2> Capture1_Timer0;
		typedef typename this_pin::template Device<3> Match1_Timer0;
	};
};
} // namespace LPC213x

#endif /* __LPC213x_PINCONNECTBLOCK_H_ */
