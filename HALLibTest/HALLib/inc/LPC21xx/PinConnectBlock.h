#ifndef __LPC21XX_PINCONNECTBLOCK_H__
#define __LPC21XX_PINCONNECTBLOCK_H__

/*
 * dieser header enthällt
 * die definitionen der PinConnectBlock Implementierungen
 * für die Prozessorfamilie LPC213x und LPC214x die diesen
 * gemeinsam sind
 */

#include <HAL/Bits.h>
#include <HAL/PinConnectBlockTemplates.h>

namespace LPC21xx{
	template <class Base>
	struct PinConnectBlockBaseLPC21xx;
}


namespace Generator{
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::PinConnectBlock, LPC21xx::LPC21x1>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef CS<SS<HAL::PinConnectBlock, HAL::Register>, ProzessorType> RegisterContext;

	typedef typename Create<RegisterContext, ConfigRepository>::type PCBRegister;

	typedef LPC21xx::PinConnectBlockBaseLPC21xx<PCBRegister> type;
};
}


namespace LPC21xx{

template <class Base>
struct PinConnectBlockBaseLPC21xx : Base {

	typedef typename Base::PinSel_0 PinSel_0;
	typedef typename Base::PinSel_1 PinSel_1;
	typedef typename Base::PinSel_2 PinSel_2;

	// -----------------------------------
	// TODO P0_0 bis P0_31 und PinSelectRegister 2
	// -----------------------------------

	// -----------------------------------
	// P0_0
	// -----------------------------------
	class P0_0 {
		typedef HAL::PinMapper<0, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> TXD_UART0;
		typedef typename this_pin::template Device<2> PWM1;
	};
	// -----------------------------------
	// P0_1
	// -----------------------------------
	class P0_1 {
		typedef HAL::PinMapper<1, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> RxD_UART0;
		typedef typename this_pin::template Device<2> PWM3;
		typedef typename this_pin::template Device<3> EINT0;
	};
	// -----------------------------------
	// P0_2
	// -----------------------------------
	class P0_2 {
		typedef HAL::PinMapper<2, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> SCL0_I2C0;
		typedef typename this_pin::template Device<2> Capture0_Timer0;
	};
	// -----------------------------------
	// P0_3
	// -----------------------------------
	class P0_3 {
		typedef HAL::PinMapper<3, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> SDA0_I2C0;
		typedef typename this_pin::template Device<2> Match0_Timer0;
		typedef typename this_pin::template Device<3> EINT1;
	};
	// -----------------------------------
	// P0_4
	// -----------------------------------
	class P0_4 {
		typedef HAL::PinMapper<4, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> SCK0_SPI0;
		typedef typename this_pin::template Device<2> Capture1_Timer0;
		typedef typename this_pin::template Device<3> AD0_6;
	};
	// -----------------------------------
	// P0_5
	// -----------------------------------
	class P0_5 {
		typedef HAL::PinMapper<5, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> MISO0_SPI0;
		typedef typename this_pin::template Device<2> Match1_Timer0;
		typedef typename this_pin::template Device<3> AD0_7;
	};
	// -----------------------------------
	// P0_6
	// -----------------------------------
	class P0_6 {
		typedef HAL::PinMapper<6, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> MOSI0_SPI0;
		typedef typename this_pin::template Device<2> Capture2_Timer0;
	};
	// -----------------------------------
	// P0_7
	// -----------------------------------
	class P0_7 {
		typedef HAL::PinMapper<7, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> SSEL0_SPI0;
		typedef typename this_pin::template Device<2> PWM2;
		typedef typename this_pin::template Device<3> EINT2;
	};
	// -----------------------------------
	// P0_8
	// -----------------------------------
	class P0_8 {
		typedef HAL::PinMapper<8, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		//TODO: RTS, und ander des UART1 nur ab LPC21x4 verfügbar??
		typedef typename this_pin::template Device<1> TXD_UART1;
		typedef typename this_pin::template Device<2> PWM4;
	};
	// -----------------------------------
	// P0_9
	// -----------------------------------
	class P0_9 {
		typedef HAL::PinMapper<9, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		//TODO: RTS, und ander des UART1 nur ab LPC21x4 verfügbar??
		typedef typename this_pin::template Device<1> RxD_UART1;
		typedef typename this_pin::template Device<2> PWM6;
		typedef typename this_pin::template Device<3> EINT3;
	};
	// -----------------------------------
	// P0_10
	// -----------------------------------
	class P0_10 {
		typedef HAL::PinMapper<10, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<2> Capture0_Timer1;
	};
	// -----------------------------------
	// P0_11
	// -----------------------------------
	class P0_11 {
		typedef HAL::PinMapper<11, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<2> Capture1_Timer1;
		typedef typename this_pin::template Device<3> SCL1_I2C1;
	};
	// -----------------------------------
	// P0_12
	// -----------------------------------
	class P0_12 {
		typedef HAL::PinMapper<12, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<2> Match0_Timer1;
	};
	// -----------------------------------
	// P0_13
	// -----------------------------------
	class P0_13 {
		typedef HAL::PinMapper<13, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<2> Match1_Timer1;
	};
	// -----------------------------------
	// P0_14
	// -----------------------------------
	class P0_14 {
		typedef HAL::PinMapper<14, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<2> EINT1;
		typedef typename this_pin::template Device<3> SDA1_I2C1;
	};
	// -----------------------------------
	// P0_15
	// -----------------------------------
	class P0_15 {
		typedef HAL::PinMapper<15, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<2> EINT2;
	};
	// PinSel1
	// -----------------------------------
	// P0_16
	// -----------------------------------
	class P0_16 {
		typedef HAL::PinMapper<16, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> EINT0;
		typedef typename this_pin::template Device<2> Match2_Timer0;
		typedef typename this_pin::template Device<3> Capture2_Timer0;
	};
	// -----------------------------------
	// P0_17
	// -----------------------------------
	class P0_17 {
		typedef HAL::PinMapper<17, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> Capture2_Timer1;
		typedef typename this_pin::template Device<2> SCK1_SSP;
		typedef typename this_pin::template Device<3> Match2_Timer1;
	};
	// -----------------------------------
	// P0_18
	// -----------------------------------
	class P0_18 {
		typedef HAL::PinMapper<18, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> Capture3_Timer1;
		typedef typename this_pin::template Device<2> MISO1_SSP;
		typedef typename this_pin::template Device<3> Match3_Timer1;
	};
	// -----------------------------------
	// P0_19
	// -----------------------------------
	class P0_19 {
		typedef HAL::PinMapper<19, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> Match2_Timer1;
		typedef typename this_pin::template Device<2> MOSI1_SSP;
		typedef typename this_pin::template Device<3> Capture2_Timer1;
	};
	// -----------------------------------
	// P0_20
	// -----------------------------------
	class P0_20 {
		typedef HAL::PinMapper<20, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> Match3_Timer1;
		typedef typename this_pin::template Device<2> SSEL1_SSP;
		typedef typename this_pin::template Device<3> EINT3;
	};
	// -----------------------------------
	// P0_21
	// -----------------------------------
	class P0_21 {
		typedef HAL::PinMapper<21, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> PWM5;
		typedef typename this_pin::template Device<3> Capture3_Timer1;
	};
	// -----------------------------------
	// P0_22
	// -----------------------------------
	class P0_22 {
		typedef HAL::PinMapper<22, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<2> Capture0_Timer0;
		typedef typename this_pin::template Device<3> Match0_Timer0;
	};
	// -----------------------------------
	// P0_23
	// -----------------------------------
	class P0_23 {
		typedef HAL::PinMapper<23, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
	};
	// -----------------------------------
	// P0_24 reserved
	// -----------------------------------
	// P0_25
	// -----------------------------------
	class P0_25 {
		typedef HAL::PinMapper<25, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> AD0_4;
	};
	// -----------------------------------
	// P0_26 und 27 reserved
	// -----------------------------------
	// P0_28
	// -----------------------------------
	class P0_28 {
		typedef HAL::PinMapper<28, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> AD0_1;
		typedef typename this_pin::template Device<2> Capture2_Timer0;
		typedef typename this_pin::template Device<3> Match2_Timer0;
	};
	// -----------------------------------
	// P0_29
	// -----------------------------------
	class P0_29 {
		typedef HAL::PinMapper<29, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> AD0_2;
		typedef typename this_pin::template Device<2> Capture3_Timer0;
		typedef typename this_pin::template Device<3> Match3_Timer0;
	};
	// -----------------------------------
	// P0_30
	// -----------------------------------
	class P0_30 {
		typedef HAL::PinMapper<30, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> AD0_3;
		typedef typename this_pin::template Device<2> EINT3;
		typedef typename this_pin::template Device<3> Capture0_Timer0;
	};
	// -----------------------------------
	// P0_31
	// -----------------------------------
	// TODO: überprügen ob GPIO nur für output geeignet
	// wie in 214xer family, siehe DOKU
	class P0_31 {
		typedef HAL::PinMapper<31, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPO_Only;
	};
//PinSel2

	// -----------------------------------
	// P1_25_16
	// -----------------------------------
	// TODO: readModifyWrite
/*
	static void selectP1_25_16_GPIO(){
	 	PinSel_2::clearBit(Bit3);
	}

	static void selectP1_25_16_TRACE(){
	 	PinSel_2::setBit(Bit3);
	}
	// -----------------------------------
	// P1_31_26
	// -----------------------------------
	static void selectP1_31_26_GPIO(){
	 	PinSel_2::clearBit(Bit2);
	}
	static void selectP1_31_26_DEBUG(){
	 	PinSel_2::setBit(Bit2);
	}
*/

};

template <class Base>
struct PinConnectBlockLPC21x2 : Base {
	typedef typename Base::PinSel_1 PinSel_1;
	// -----------------------------------
	// P0_25
	// -----------------------------------
	class P0_25 {
		typedef HAL::PinMapper<25, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> AD0_4;
		typedef typename this_pin::template Device<2> Aout_DAC;
	};
};

template <class Base>
struct PinConnectBlockLPC21x4 : Base {
	typedef typename Base::PinSel_0 PinSel_0;
	typedef typename Base::PinSel_1 PinSel_1;
	typedef typename Base::PinSel_2 PinSel_2;

	// -----------------------------------
	// P0_6
	// -----------------------------------
	class P0_6 {
		typedef HAL::PinMapper<6, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> MOSI0_SPI0;
		typedef typename this_pin::template Device<2> Capture2_Timer0;
		typedef typename this_pin::template Device<3> AD1_0;
	};
	// -----------------------------------
	// P0_8
	// -----------------------------------
	class P0_8 {
		typedef HAL::PinMapper<8, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		//TODO: RTS, und ander des UART1 nur ab LPC21x4 verfügbar??
		typedef typename this_pin::template Device<1> TXD_UART1;
		typedef typename this_pin::template Device<2> PWM4;
		typedef typename this_pin::template Device<3> AD1_1;
	};
	// -----------------------------------
	// P0_10
	// -----------------------------------
	class P0_10 {
		typedef HAL::PinMapper<10, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> RTS_UART1;
		typedef typename this_pin::template Device<2> Capture0_Timer1;
		typedef typename this_pin::template Device<3> AD1_2;
	};
	// -----------------------------------
	// P0_11
	// -----------------------------------
	class P0_11 {
		typedef HAL::PinMapper<11, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> CTS_UART1;
		typedef typename this_pin::template Device<2> Capture1_Timer1;
		typedef typename this_pin::template Device<3> SCL1_I2C1;
	};
	// -----------------------------------
	// P0_12
	// -----------------------------------
	class P0_12 {
		typedef HAL::PinMapper<12, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> DSR_UART1;
		typedef typename this_pin::template Device<2> Match0_Timer1;
		typedef typename this_pin::template Device<3> AD1_3;
	};
	// -----------------------------------
	// P0_13
	// -----------------------------------
	class P0_13 {
		typedef HAL::PinMapper<13, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> DTR_UART1;
		typedef typename this_pin::template Device<2> Match1_Timer1;
		typedef typename this_pin::template Device<3> AD1_4;
	};
	// -----------------------------------
	// P0_14
	// -----------------------------------
	class P0_14 {
		typedef HAL::PinMapper<14, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> DCD_UART1;
		typedef typename this_pin::template Device<2> EINT1;
		typedef typename this_pin::template Device<3> SDA1_I2C1;
	};
	// -----------------------------------
	// P0_15
	// -----------------------------------
	class P0_15 {
		typedef HAL::PinMapper<15, PinSel_0> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> RI_UART1;
		typedef typename this_pin::template Device<2> EINT2;
		typedef typename this_pin::template Device<3> AD1_5;
	};
	// -----------------------------------
	// P0_21
	// -----------------------------------
	class P0_21 {
		typedef HAL::PinMapper<21, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> PWM5;
		typedef typename this_pin::template Device<2> AD1_6;
		typedef typename this_pin::template Device<3> Capture3_Timer1;
	};
	// -----------------------------------
	// P0_22
	// -----------------------------------
	class P0_22 {
		typedef HAL::PinMapper<22, PinSel_1> this_pin;
	public:
		typedef typename this_pin::template Device<0> GPIO;
		typedef typename this_pin::template Device<1> AD1_7;
		typedef typename this_pin::template Device<2> Capture0_Timer0;
		typedef typename this_pin::template Device<3> Match0_Timer0;
	};
};
} // namespace LPC21xx

#endif // __LPC21XX_PINCONNECTBLOCK_H__
