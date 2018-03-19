#ifndef PINCONNECTTEST_H_
#define PINCONNECTTEST_H_

#include "PCBTestRegister.h"
#include "RegisterTestBase.h"

class PinConnectBlockTest : public RegisterTestBase {
public:


	typedef Generator::Create<Mock::LPC2131>::type Hal2131;
	typedef Generator::Create<Mock::LPC2141>::type Hal2141;
	typedef Generator::Create<Mock::LPC2144>::type Hal2144;

	typedef Hal2131::PinConnectBlock PCB2131;
	typedef Hal2141::PinConnectBlock PCB2141;
	typedef Hal2144::PinConnectBlock PCB2144;

	// experiment mit static registern in Component zur Deklaration
	// mit dem richtigen type: RegisterType
//	typedef Generator::Create<Generator::CS<HAL::PCBRegister, Mock::LPC2144>>
//			::type PCBRegister;
//	typedef Hal2144::Traits ghTraits;
//	typedef decltype(PCBRegister::pinsel0) ResultType;
//	ResultType& pinsel0 = PCBRegister::pinsel0;
//	typedef ResultType ExpectedType;
//	ExpectedType &pinsel0 = PCBRegister::pinsel0;

	typedef Hal2131::Traits Traits;
	typedef Traits::ValueType ExpectedType;


	typedef PCB2141::P0_0 P0_0;
	typedef PCB2141::P0_1 P0_1;
	typedef PCB2141::P0_2 P0_2;
	typedef PCB2141::P0_3 P0_3;
	typedef PCB2141::P0_4 P0_4;
	typedef PCB2141::P0_5 P0_5;

	typedef PCB2144::P0_6 P0_6;

	typedef PCB2141::P0_7 P0_7;

	typedef PCB2144::P0_8 P0_8;

	typedef PCB2141::P0_9 P0_9;

	typedef PCB2144::P0_10 P0_10;
	typedef PCB2144::P0_11 P0_11;
	typedef PCB2144::P0_12 P0_12;
	typedef PCB2144::P0_13 P0_13;
	typedef PCB2144::P0_14 P0_14;
	typedef PCB2144::P0_15 P0_15;
	typedef PCB2141::P0_16 P0_16;
	typedef PCB2141::P0_17 P0_17;
	typedef PCB2141::P0_18 P0_18;
	typedef PCB2141::P0_19 P0_19;
	typedef PCB2141::P0_20 P0_20;
	typedef PCB2144::P0_21 P0_21;
	typedef PCB2144::P0_22 P0_22;
	typedef PCB2141::P0_23 P0_23;
	typedef PCB2144::P0_25 P0_25;

	typedef PCB2131::P0_26 P0_26;
	typedef PCB2131::P0_27 P0_27;

	typedef PCB2141::P0_28 P0_28;
	typedef PCB2141::P0_29 P0_29;
	typedef PCB2141::P0_30 P0_30;
	typedef PCB2131::P0_31 P0_31;

	CPPUNIT_TEST_SUITE (PinConnectBlockTest);

	CPPUNIT_TEST (selectP0_0_GPIO);
	CPPUNIT_TEST (selectP0_0_TXD_UART0);
	CPPUNIT_TEST (selectP0_0_PWM1);

	CPPUNIT_TEST (selectP0_1_GPIO);
	CPPUNIT_TEST (selectP0_1_RxD_UART0);
	CPPUNIT_TEST (selectP0_1_PWM3);
	CPPUNIT_TEST (selectP0_1_EINT0);

	CPPUNIT_TEST (selectP0_2_GPIO);
	CPPUNIT_TEST (selectP0_2_SCL0_I2C0);
	CPPUNIT_TEST (selectP0_2_Capture_0_0_Timer0);

	CPPUNIT_TEST (selectP0_3_GPIO);
	CPPUNIT_TEST (selectP0_3_SDA0_I2C0);
	CPPUNIT_TEST (selectP0_3_Match_0_0_Timer0);
	CPPUNIT_TEST (selectP0_3_EINT1);

	CPPUNIT_TEST (selectP0_4_GPIO);
	CPPUNIT_TEST (selectP0_4_SCK0_SPI0);
	CPPUNIT_TEST (selectP0_4_Capture_0_1_Timer0);
	CPPUNIT_TEST (selectP0_4_AD0_6);

	CPPUNIT_TEST (selectP0_5_GPIO);
	CPPUNIT_TEST (selectP0_5_MISO0_SPI0);
	CPPUNIT_TEST (selectP0_5_Match_0_1_Timer0);
	CPPUNIT_TEST (selectP0_5_AD0_7);

	CPPUNIT_TEST (selectP0_6_GPIO);
	CPPUNIT_TEST (selectP0_6_MOSI0_SPI0);
	CPPUNIT_TEST (selectP0_6_Capture_0_2_Timer0);
	CPPUNIT_TEST (selectP0_6_AD1_0);

	CPPUNIT_TEST (selectP0_7_GPIO);
	CPPUNIT_TEST (selectP0_7_SSEL0_SPI0);
	CPPUNIT_TEST (selectP0_7_PWM2);
	CPPUNIT_TEST (selectP0_7_EINT2);

	CPPUNIT_TEST (selectP0_8_GPIO);
	CPPUNIT_TEST (selectP0_8_TXD_UART1);
	CPPUNIT_TEST (selectP0_8_PWM4);
	CPPUNIT_TEST (selectP0_8_AD1_1);

	CPPUNIT_TEST (selectP0_9_GPIO);
	CPPUNIT_TEST (selectP0_9_RxD_UART1);
	CPPUNIT_TEST (selectP0_9_PWM6);
	CPPUNIT_TEST (selectP0_9_EINT3);

	CPPUNIT_TEST (selectP0_10_GPIO);
	CPPUNIT_TEST (selectP0_10_RTS_UART1);
	CPPUNIT_TEST (selectP0_10_Capture_1_0_Timer1);
	CPPUNIT_TEST (selectP0_10_AD1_2);

	CPPUNIT_TEST (selectP0_11_GPIO);
	CPPUNIT_TEST (selectP0_11_CTS_UART1);
	CPPUNIT_TEST (selectP0_11_Capture_1_1_Timer1);
	CPPUNIT_TEST (selectP0_11_SCL1_I2C1);

	CPPUNIT_TEST (selectP0_12_GPIO);
	CPPUNIT_TEST (selectP0_12_DSR_UART1);
	CPPUNIT_TEST (selectP0_12_Match_1_0_Timer1);
	CPPUNIT_TEST (selectP0_12_AD1_3);

	CPPUNIT_TEST (selectP0_13_GPIO);
	CPPUNIT_TEST (selectP0_13_DTR_UART1);
	CPPUNIT_TEST (selectP0_13_Match_1_1_Timer1);
	CPPUNIT_TEST (selectP0_13_AD1_4);

	CPPUNIT_TEST (selectP0_14_GPIO);
	CPPUNIT_TEST (selectP0_14_DCD_UART1);
	CPPUNIT_TEST (selectP0_14_EINT1);
	CPPUNIT_TEST (selectP0_14_SDA1_I2C1);

	CPPUNIT_TEST (selectP0_15_GPIO);
	CPPUNIT_TEST (selectP0_15_RI_UART1);
	CPPUNIT_TEST (selectP0_15_EINT2);
	CPPUNIT_TEST (selectP0_15_AD1_5);
//PinSel1
	CPPUNIT_TEST (selectP0_16_GPIO);
	CPPUNIT_TEST (selectP0_16_EINT0);
	CPPUNIT_TEST (selectP0_16_Match_0_2_Timer0);
	CPPUNIT_TEST (selectP0_16_Capture_0_2_Timer0);

	CPPUNIT_TEST (selectP0_17_GPIO);
	CPPUNIT_TEST (selectP0_17_Capture_1_2_Timer1);
	CPPUNIT_TEST (selectP0_17_SCK1_SSP);
	CPPUNIT_TEST (selectP0_17_Match_1_2_Timer1);

	CPPUNIT_TEST (selectP0_18_GPIO);
	CPPUNIT_TEST (selectP0_18_Capture_1_3_Timer1);
	CPPUNIT_TEST (selectP0_18_MISO1_SSP);
	CPPUNIT_TEST (selectP0_18_Match_1_3_Timer1);

	CPPUNIT_TEST (selectP0_19_GPIO);
	CPPUNIT_TEST (selectP0_19_Match_1_2_Timer1);
	CPPUNIT_TEST (selectP0_19_MOSI1_SSP);
	CPPUNIT_TEST (selectP0_19_Capture_1_2_Timer1);

	CPPUNIT_TEST (selectP0_20_GPIO);
	CPPUNIT_TEST (selectP0_20_Match_1_3_Timer1);
	CPPUNIT_TEST (selectP0_20_SSEL1_SSP);
	CPPUNIT_TEST (selectP0_20_EINT3);

	CPPUNIT_TEST (selectP0_21_GPIO);
	CPPUNIT_TEST (selectP0_21_PWM5);
	CPPUNIT_TEST (selectP0_21_AD1_6);
	CPPUNIT_TEST (selectP0_21_Capture_1_3_Timer1);

	CPPUNIT_TEST (selectP0_22_GPIO);
	CPPUNIT_TEST (selectP0_22_AD1_7);
	CPPUNIT_TEST (selectP0_22_Capture_0_0_Timer0);
	CPPUNIT_TEST (selectP0_22_Match_0_0_Timer0);
//
	CPPUNIT_TEST (selectP0_23_GPIO);
	CPPUNIT_TEST (selectP0_23_VBus);
//
	// P0_24 reserved

//	CPPUNIT_TEST (selectP0_25_GPIO);
	CPPUNIT_TEST (selectP0_25_AD0_4);
	CPPUNIT_TEST (selectP0_25_Aout_DAC);

	//nur in LPC213x verfügbar
	CPPUNIT_TEST (printContext);
	CPPUNIT_TEST (selectP0_26_GPIO);
	CPPUNIT_TEST (selectP0_26_AD0_5);

	CPPUNIT_TEST (selectP0_27_GPIO);
	CPPUNIT_TEST (selectP0_27_AD0_0);
	CPPUNIT_TEST (selectP0_27_Capture_0_1_Timer0);
	CPPUNIT_TEST (selectP0_27_Match_0_1_Timer0);

	// in allen verfügbar
	CPPUNIT_TEST (selectP0_28_GPIO);
	CPPUNIT_TEST (selectP0_28_AD0_1);
	CPPUNIT_TEST (selectP0_28_Capture_0_2_Timer0);
	CPPUNIT_TEST (selectP0_28_Match_0_2_Timer0);
//
	CPPUNIT_TEST (selectP0_29_GPIO);
	CPPUNIT_TEST (selectP0_29_AD0_2);
	CPPUNIT_TEST (selectP0_29_Capture_0_3_Timer0);
	CPPUNIT_TEST (selectP0_29_Match_0_3_Timer0);

	CPPUNIT_TEST (selectP0_30_GPIO);
	CPPUNIT_TEST (selectP0_30_AD0_3);
	CPPUNIT_TEST (selectP0_30_EINT3);
	CPPUNIT_TEST (selectP0_30_Capture_0_0_Timer0);
//
	CPPUNIT_TEST (selectP0_31_GPO_Port);

	// LPC2141 Only
	CPPUNIT_TEST (selectP0_31_UP_LED);
	CPPUNIT_TEST (selectP0_31_CONNECT);
//PinSel2
/*
	CPPUNIT_TEST (selectP1_31_26_GPIO);
	CPPUNIT_TEST (selectP1_31_26_Debug);

	CPPUNIT_TEST (selectP1_25_16_GPIO);
	CPPUNIT_TEST (selectP1_25_16_Trace);
*/

	CPPUNIT_TEST_SUITE_END ();

protected:
	void printContext();
	void selectP0_0_GPIO();
	void selectP0_0_TXD_UART0();
	void selectP0_0_PWM1();

	void selectP0_1_GPIO();
	void selectP0_1_RxD_UART0();
	void selectP0_1_PWM3();
	void selectP0_1_EINT0();

	void selectP0_2_GPIO();
	void selectP0_2_SCL0_I2C0();
	void selectP0_2_Capture_0_0_Timer0();

	void selectP0_3_GPIO();
	void selectP0_3_SDA0_I2C0();
	void selectP0_3_Match_0_0_Timer0();
	void selectP0_3_EINT1();

	void selectP0_4_GPIO();
	void selectP0_4_SCK0_SPI0();
	void selectP0_4_Capture_0_1_Timer0();
	void selectP0_4_AD0_6();

	void selectP0_5_GPIO();
	void selectP0_5_MISO0_SPI0();
	void selectP0_5_Match_0_1_Timer0();
	void selectP0_5_AD0_7();

	void selectP0_6_GPIO();
	void selectP0_6_MOSI0_SPI0();
	void selectP0_6_Capture_0_2_Timer0();
	void selectP0_6_AD1_0();

	void selectP0_7_GPIO();
	void selectP0_7_SSEL0_SPI0();
	void selectP0_7_PWM2();
	void selectP0_7_EINT2();

	void selectP0_8_GPIO();
	void selectP0_8_TXD_UART1();
	void selectP0_8_PWM4();
	void selectP0_8_AD1_1();

	void selectP0_9_GPIO();
	void selectP0_9_RxD_UART1();
	void selectP0_9_PWM6();
	void selectP0_9_EINT3();

	void selectP0_10_GPIO();
	void selectP0_10_RTS_UART1();
	void selectP0_10_Capture_1_0_Timer1();
	void selectP0_10_AD1_2();

	void selectP0_11_GPIO();
	void selectP0_11_CTS_UART1();
	void selectP0_11_Capture_1_1_Timer1();
	void selectP0_11_SCL1_I2C1();

	void selectP0_12_GPIO();
	void selectP0_12_DSR_UART1();
	void selectP0_12_Match_1_0_Timer1();
	void selectP0_12_AD1_3();

	void selectP0_13_GPIO();
	void selectP0_13_DTR_UART1();
	void selectP0_13_Match_1_1_Timer1();
	void selectP0_13_AD1_4();

	void selectP0_14_GPIO();
	void selectP0_14_DCD_UART1();
	void selectP0_14_EINT1();
	void selectP0_14_SDA1_I2C1();

	void selectP0_15_GPIO();
	void selectP0_15_RI_UART1();
	void selectP0_15_EINT2();
	void selectP0_15_AD1_5();
// PinSel1
	void selectP0_16_GPIO();
	void selectP0_16_EINT0();
	void selectP0_16_Match_0_2_Timer0();
	void selectP0_16_Capture_0_2_Timer0();

	void selectP0_17_GPIO();
	void selectP0_17_Capture_1_2_Timer1();
	void selectP0_17_SCK1_SSP();
	void selectP0_17_Match_1_2_Timer1();

	void selectP0_18_GPIO();
	void selectP0_18_Capture_1_3_Timer1();
	void selectP0_18_MISO1_SSP();
	void selectP0_18_Match_1_3_Timer1();

	void selectP0_19_GPIO();
	void selectP0_19_Match_1_2_Timer1();
	void selectP0_19_MOSI1_SSP();
	void selectP0_19_Capture_1_2_Timer1();

	void selectP0_20_GPIO();
	void selectP0_20_Match_1_3_Timer1();
	void selectP0_20_SSEL1_SSP();
	void selectP0_20_EINT3();

	void selectP0_21_GPIO();
	void selectP0_21_PWM5();
	void selectP0_21_AD1_6();
	void selectP0_21_Capture_1_3_Timer1();

	void selectP0_22_GPIO();
	void selectP0_22_AD1_7();
	void selectP0_22_Capture_0_0_Timer0();
	void selectP0_22_Match_0_0_Timer0();

	void selectP0_23_GPIO();
	void selectP0_23_VBus();

	//P0_24 reserved

	void selectP0_25_GPIO();
	void selectP0_25_AD0_4();
	void selectP0_25_Aout_DAC();

	// LPC213x Only
	void selectP0_26_GPIO();
	void selectP0_26_AD0_5();

	// LPC213x Only
	void selectP0_27_GPIO();
	void selectP0_27_AD0_0();
	void selectP0_27_Capture_0_1_Timer0();
	void selectP0_27_Match_0_1_Timer0();

	void selectP0_28_GPIO();
	void selectP0_28_AD0_1();
	void selectP0_28_Capture_0_2_Timer0();
	void selectP0_28_Match_0_2_Timer0();

	void selectP0_29_GPIO();
	void selectP0_29_AD0_2();
	void selectP0_29_Capture_0_3_Timer0();
	void selectP0_29_Match_0_3_Timer0();

	void selectP0_30_GPIO();
	void selectP0_30_AD0_3();
	void selectP0_30_EINT3();
	void selectP0_30_Capture_0_0_Timer0();

	void selectP0_31_GPO_Port();

	// LPC214x Only
	void selectP0_31_UP_LED();
	void selectP0_31_CONNECT();
//PinSel2
/*
	void selectP1_31_26_GPIO();
	void selectP1_31_26_Debug();

	void selectP1_25_16_GPIO();
	void selectP1_25_16_Trace();
*/
};
#endif /* PINCONNECTTEST_H_ */
