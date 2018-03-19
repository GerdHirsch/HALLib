#include <iostream>
#include "PinConnectBlockTest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (PinConnectBlockTest);

namespace Mock{
PinConnectBlockTest::ExpectedType pinsel0 = 0;
PinConnectBlockTest::ExpectedType pinsel1 = 0;
PinConnectBlockTest::ExpectedType pinsel2 = 0;
//template<class ProzessorType, class HWTraits>
//typename HWTraits::ValueType PCBMockRegisters<ProzessorType, HWTraits>::pinsel0 = 0;
} // namespace Mock

using namespace Mock;

//PCB21::selectP([0-9])_([0-9]+)_([0-9,A-Z,a-z,_]+),

void PinConnectBlockTest::selectP0_0_GPIO(){
	ExpectedType expected = 0x0;
	compareExpectedResult(
			P0_0::GPIO::select,
			pinsel0,
			expected,
			Bit0, Bit1
	);
}

void PinConnectBlockTest::selectP0_0_TXD_UART0(){
	ExpectedType expected = Bit0;
	compareExpectedResult(
			P0_0::TXD_UART0::select,
			pinsel0,
			expected,
			Bit0, Bit1
	);
}
void PinConnectBlockTest::selectP0_0_PWM1(){
	ExpectedType expected = Bit1;
	compareExpectedResult(
			P0_0::PWM1::select,
			pinsel0,
			expected,
			Bit0, Bit1
	);
}

void PinConnectBlockTest::selectP0_1_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_1::GPIO::select,
			pinsel0,
			expected,
			Bit2, Bit3
	);
}

void PinConnectBlockTest::selectP0_1_RxD_UART0(){
	ExpectedType expected = (Bit2);
	compareExpectedResult(
			P0_1::RxD_UART0::select,
			pinsel0,
			expected,
			Bit2, Bit3
	);
}

void PinConnectBlockTest::selectP0_1_PWM3(){
	ExpectedType expected = (Bit3);
	compareExpectedResult(
			P0_1::PWM3::select,
			pinsel0,
			expected,
			Bit2, Bit3
	);
}

void PinConnectBlockTest::selectP0_1_EINT0(){
	ExpectedType expected = (Bit3|Bit2);
	compareExpectedResult(
			P0_1::EINT0::select,
			pinsel0,
			expected,
			Bit2, Bit3
	);
}

void PinConnectBlockTest::selectP0_2_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_2::GPIO::select,
			pinsel0,
			expected,
			Bit4, Bit5
	);
}

void PinConnectBlockTest::selectP0_2_SCL0_I2C0(){
	ExpectedType expected = Bit4;
	compareExpectedResult(
			P0_2::SCL0_I2C0::select,
			pinsel0,
			expected,
			Bit4, Bit5
	);
}

void PinConnectBlockTest::selectP0_2_Capture_0_0_Timer0(){
	ExpectedType expected = Bit5;
	compareExpectedResult(
			P0_2::Capture0_Timer0::select,
			pinsel0,
			expected,
			Bit4, Bit5
	);
}

void PinConnectBlockTest::selectP0_3_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_3::GPIO::select,
			pinsel0,
			expected,
			Bit6, Bit7
	);
}

void PinConnectBlockTest::selectP0_3_SDA0_I2C0(){
	ExpectedType expected = (Bit6);
	compareExpectedResult(
			P0_3::SDA0_I2C0::select,
			pinsel0,
			expected,
			Bit6, Bit7
	);
}

void PinConnectBlockTest::selectP0_3_Match_0_0_Timer0(){
	ExpectedType expected = (Bit7);
	compareExpectedResult(
			P0_3::Match0_Timer0::select,
			pinsel0,
			expected,
			Bit6, Bit7
	);
}

void PinConnectBlockTest::selectP0_3_EINT1(){
	ExpectedType expected = (Bit7|Bit6);
	compareExpectedResult(
			P0_3::EINT1::select,
			pinsel0,
			expected,
			Bit6, Bit7
	);
}

void PinConnectBlockTest::selectP0_4_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_4::GPIO::select,
			pinsel0,
			expected,
			Bit8, Bit9
	);
}

void PinConnectBlockTest::selectP0_4_SCK0_SPI0(){
	ExpectedType expected = (Bit8);
	compareExpectedResult(
			P0_4::SCK0_SPI0::select,
			pinsel0,
			expected,
			Bit8, Bit9
	);
}

void PinConnectBlockTest::selectP0_4_Capture_0_1_Timer0(){
	ExpectedType expected = (Bit9);
	compareExpectedResult(
			P0_4::Capture1_Timer0::select,
			pinsel0,
			expected,
			Bit8, Bit9
	);
}

void PinConnectBlockTest::selectP0_4_AD0_6(){
	ExpectedType expected = (Bit9|Bit8);
	compareExpectedResult(
			P0_4::AD0_6::select,
			pinsel0,
			expected,
			Bit8, Bit9
	);
}

void PinConnectBlockTest::selectP0_5_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_5::GPIO::select,
			pinsel0,
			expected,
			Bit10, Bit11
	);
}

void PinConnectBlockTest::selectP0_5_MISO0_SPI0(){
	ExpectedType expected = (Bit10);
	compareExpectedResult(
			P0_5::MISO0_SPI0::select,
			pinsel0,
			expected,
			Bit10, Bit11
	);
}

void PinConnectBlockTest::selectP0_5_Match_0_1_Timer0(){
	ExpectedType expected = (Bit11);
	compareExpectedResult(
			P0_5::Match1_Timer0::select,
			pinsel0,
			expected,
			Bit10, Bit11
	);
}

void PinConnectBlockTest::selectP0_5_AD0_7(){
	ExpectedType expected = (Bit11|Bit10);
	compareExpectedResult(
			P0_5::AD0_7::select,
			pinsel0,
			expected,
			Bit10, Bit11
	);
}

void PinConnectBlockTest::selectP0_6_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_6::GPIO::select,
			pinsel0,
			expected,
			Bit12, Bit13
	);
}

void PinConnectBlockTest::selectP0_6_MOSI0_SPI0(){
	ExpectedType expected = (Bit12);
	compareExpectedResult(
			P0_6::MOSI0_SPI0::select,
			pinsel0,
			expected,
			Bit12, Bit13
	);
}

void PinConnectBlockTest::selectP0_6_Capture_0_2_Timer0(){
	ExpectedType expected = (Bit13);
	compareExpectedResult(
			P0_6::Capture2_Timer0::select,
			pinsel0,
			expected,
			Bit12, Bit13
	);
}
void PinConnectBlockTest::selectP0_6_AD1_0(){
	ExpectedType expected = (Bit13|Bit12);
	compareExpectedResult(
			P0_6::AD1_0::select,
			pinsel0,
			expected,
			Bit12, Bit13
	);
}

void PinConnectBlockTest::selectP0_7_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_7::GPIO::select,
			pinsel0,
			expected,
			Bit14, Bit15
	);
}

void PinConnectBlockTest::selectP0_7_SSEL0_SPI0(){
	ExpectedType expected = Bit14;
	compareExpectedResult(
			P0_7::SSEL0_SPI0::select,
			pinsel0,
			expected,
			Bit14, Bit15
	);
}

void PinConnectBlockTest::selectP0_7_PWM2(){
	ExpectedType expected = (Bit15);
	compareExpectedResult(
			P0_7::PWM2::select,
			pinsel0,
			expected,
			Bit14, Bit15
	);
}

void PinConnectBlockTest::selectP0_7_EINT2(){
	ExpectedType expected = (Bit15|Bit14);
	compareExpectedResult(
			P0_7::EINT2::select,
			pinsel0,
			expected,
			Bit14, Bit15
	);
}

void PinConnectBlockTest::selectP0_8_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_8::GPIO::select,
			pinsel0,
			expected,
			Bit16, Bit17
	);
}

void PinConnectBlockTest::selectP0_8_TXD_UART1(){
	ExpectedType expected = (Bit16);
	compareExpectedResult(
			P0_8::TXD_UART1::select,
			pinsel0,
			expected,
			Bit16, Bit17
	);
}

void PinConnectBlockTest::selectP0_8_PWM4(){
	ExpectedType expected = (Bit17);
	compareExpectedResult(
			P0_8::PWM4::select,
			pinsel0,
			expected,
			Bit16, Bit17
	);
}
void PinConnectBlockTest::selectP0_8_AD1_1(){
	ExpectedType expected = (Bit17|Bit16);
	compareExpectedResult(
			P0_8::AD1_1::select,
			pinsel0,
			expected,
			Bit16, Bit17
	);
}

void PinConnectBlockTest::selectP0_9_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_9::GPIO::select,
			pinsel0,
			expected,
			Bit18, Bit19
	);
}

void PinConnectBlockTest::selectP0_9_RxD_UART1(){
	ExpectedType expected = (Bit18);
	compareExpectedResult(
			P0_9::RxD_UART1::select,
			pinsel0,
			expected,
			Bit18, Bit19
	);
}

void PinConnectBlockTest::selectP0_9_PWM6(){
	ExpectedType expected = (Bit19);
	compareExpectedResult(
			P0_9::PWM6::select,
			pinsel0,
			expected,
			Bit18, Bit19
	);
}

void PinConnectBlockTest::selectP0_9_EINT3(){
	ExpectedType expected = (Bit19|Bit18);
	compareExpectedResult(
			P0_9::EINT3::select,
			pinsel0,
			expected,
			Bit18, Bit19
	);
}

void PinConnectBlockTest::selectP0_10_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_10::GPIO::select,
			pinsel0,
			expected,
			Bit20, Bit21
	);
}
void PinConnectBlockTest::selectP0_10_RTS_UART1(){
	ExpectedType expected = Bit20;
	compareExpectedResult(
			P0_10::RTS_UART1::select,
			pinsel0,
			expected,
			Bit20, Bit21
	);
}

void PinConnectBlockTest::selectP0_10_Capture_1_0_Timer1(){
	ExpectedType expected = (Bit21);
	compareExpectedResult(
			P0_10::Capture0_Timer1::select,
			pinsel0,
			expected,
			Bit20, Bit21
	);
}
void PinConnectBlockTest::selectP0_10_AD1_2(){
	ExpectedType expected = Bit20|Bit21;
	compareExpectedResult(
			P0_10::AD1_2::select,
			pinsel0,
			expected,
			Bit20, Bit21
	);
}

void PinConnectBlockTest::selectP0_11_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_11::GPIO::select,
			pinsel0,
			expected,
			Bit22, Bit23
	);
}
void PinConnectBlockTest::selectP0_11_CTS_UART1(){
	ExpectedType expected = Bit22;
	compareExpectedResult(
			P0_11::CTS_UART1::select,
			pinsel0,
			expected,
			Bit22, Bit23
	);
}

void PinConnectBlockTest::selectP0_11_Capture_1_1_Timer1(){
	ExpectedType expected = (Bit23);
	compareExpectedResult(
			P0_11::Capture1_Timer1::select,
			pinsel0,
			expected,
			Bit22, Bit23
	);
}

void PinConnectBlockTest::selectP0_11_SCL1_I2C1(){
	ExpectedType expected = (Bit23|Bit22);
	compareExpectedResult(
			P0_11::SCL1_I2C1::select,
			pinsel0,
			expected,
			Bit22, Bit23
	);
}

void PinConnectBlockTest::selectP0_12_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_12::GPIO::select,
			pinsel0,
			expected,
			Bit24, Bit25
	);
}
void PinConnectBlockTest::selectP0_12_DSR_UART1(){
	ExpectedType expected = Bit24;
	compareExpectedResult(
			P0_12::DSR_UART1::select,
			pinsel0,
			expected,
			Bit24, Bit25
	);
}

void PinConnectBlockTest::selectP0_12_Match_1_0_Timer1(){
	ExpectedType expected = (Bit25);
	compareExpectedResult(
			P0_12::Match0_Timer1::select,
			pinsel0,
			expected,
			Bit24, Bit25
	);
}
void PinConnectBlockTest::selectP0_12_AD1_3(){
	ExpectedType expected = (Bit25|Bit24);
	compareExpectedResult(
			P0_12::AD1_3::select,
			pinsel0,
			expected,
			Bit24, Bit25
	);
}

void PinConnectBlockTest::selectP0_13_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_13::GPIO::select,
			pinsel0,
			expected,
			Bit26, Bit27
	);
}
void PinConnectBlockTest::selectP0_13_DTR_UART1(){
	ExpectedType expected = Bit26;
	compareExpectedResult(
			P0_13::DTR_UART1::select,
			pinsel0,
			expected,
			Bit26, Bit27
	);
}

void PinConnectBlockTest::selectP0_13_Match_1_1_Timer1(){
	ExpectedType expected = (Bit27);
	compareExpectedResult(
			P0_13::Match1_Timer1::select,
			pinsel0,
			expected,
			Bit26, Bit27
	);
}
void PinConnectBlockTest::selectP0_13_AD1_4(){
	ExpectedType expected = (Bit27|Bit26);
	compareExpectedResult(
			P0_13::AD1_4::select,
			pinsel0,
			expected,
			Bit26, Bit27
	);
}

void PinConnectBlockTest::selectP0_14_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_14::GPIO::select,
			pinsel0,
			expected,
			Bit28, Bit29
	);
}
void PinConnectBlockTest::selectP0_14_DCD_UART1(){
	ExpectedType expected = Bit28;
	compareExpectedResult(
			P0_14::DCD_UART1::select,
			pinsel0,
			expected,
			Bit28, Bit29
	);
}

void PinConnectBlockTest::selectP0_14_EINT1(){
	ExpectedType expected = (Bit29);
	compareExpectedResult(
			P0_14::EINT1::select,
			pinsel0,
			expected,
			Bit28, Bit29
	);
}

void PinConnectBlockTest::selectP0_14_SDA1_I2C1(){
	ExpectedType expected = (Bit29|Bit28);
	compareExpectedResult(
			P0_14::SDA1_I2C1::select,
			pinsel0,
			expected,
			Bit28, Bit29
	);
}

void PinConnectBlockTest::selectP0_15_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_15::GPIO::select,
			pinsel0,
			expected,
			Bit30, Bit31
	);
}
void PinConnectBlockTest::selectP0_15_RI_UART1(){
	ExpectedType expected = Bit30;
	compareExpectedResult(
			P0_15::RI_UART1::select,
			pinsel0,
			expected,
			Bit30, Bit31
	);
}

void PinConnectBlockTest::selectP0_15_EINT2(){
	ExpectedType expected = (Bit31);
	compareExpectedResult(
			P0_15::EINT2::select,
			pinsel0,
			expected,
			Bit30, Bit31
	);
}
void PinConnectBlockTest::selectP0_15_AD1_5(){
	ExpectedType expected = (Bit31|Bit30);
	compareExpectedResult(
			P0_15::AD1_5::select,
			pinsel0,
			expected,
			Bit30, Bit31
	);
}

// PinSel1
void PinConnectBlockTest::selectP0_16_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_16::GPIO::select,
			pinsel1,
			expected,
			Bit0, Bit1
	);

}
void PinConnectBlockTest::selectP0_16_EINT0(){
	ExpectedType expected = Bit0;
	compareExpectedResult(
			P0_16::EINT0::select,
			pinsel1,
			expected,
			Bit0, Bit1
	);

}
void PinConnectBlockTest::selectP0_16_Match_0_2_Timer0(){
	ExpectedType expected = Bit1;
	compareExpectedResult(
			P0_16::Match2_Timer0::select,
			pinsel1,
			expected,
			Bit0, Bit1
	);

}
void PinConnectBlockTest::selectP0_16_Capture_0_2_Timer0(){
	ExpectedType expected = Bit1|Bit0;
	compareExpectedResult(
			P0_16::Capture2_Timer0::select,
			pinsel1,
			expected,
			Bit0, Bit1
	);

}

void PinConnectBlockTest::selectP0_17_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_17::GPIO::select,
			pinsel1,
			expected,
			Bit2, Bit3
	);

}
void PinConnectBlockTest::selectP0_17_Capture_1_2_Timer1(){
	ExpectedType expected = Bit2;
	compareExpectedResult(
			P0_17::Capture2_Timer1::select,
			pinsel1,
			expected,
			Bit2, Bit3
	);

}
void PinConnectBlockTest::selectP0_17_SCK1_SSP(){
	ExpectedType expected = Bit3;
	compareExpectedResult(
			P0_17::SCK1_SSP::select,
			pinsel1,
			expected,
			Bit2, Bit3
	);

}
void PinConnectBlockTest::selectP0_17_Match_1_2_Timer1(){
	ExpectedType expected = Bit3|Bit2;
	compareExpectedResult(
			P0_17::Match2_Timer1::select,
			pinsel1,
			expected,
			Bit2, Bit3
	);

}
void PinConnectBlockTest::selectP0_18_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_18::GPIO::select,
			pinsel1,
			expected,
			Bit4, Bit5
	);

}
void PinConnectBlockTest::selectP0_18_Capture_1_3_Timer1(){
	ExpectedType expected = Bit4;
	compareExpectedResult(
			P0_18::Capture3_Timer1::select,
			pinsel1,
			expected,
			Bit4, Bit5
	);

}
void PinConnectBlockTest::selectP0_18_MISO1_SSP(){
	ExpectedType expected = Bit5;
	compareExpectedResult(
			P0_18::MISO1_SSP::select,
			pinsel1,
			expected,
			Bit4, Bit5
	);

}
void PinConnectBlockTest::selectP0_18_Match_1_3_Timer1(){
	ExpectedType expected = Bit5|Bit4;
	compareExpectedResult(
			P0_18::Match3_Timer1::select,
			pinsel1,
			expected,
			Bit4, Bit5
	);

}

void PinConnectBlockTest::selectP0_19_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_19::GPIO::select,
			pinsel1,
			expected,
			Bit6, Bit7
	);

}
void PinConnectBlockTest::selectP0_19_Match_1_2_Timer1(){
	ExpectedType expected = Bit6;
	compareExpectedResult(
			P0_19::Match2_Timer1::select,
			pinsel1,
			expected,
			Bit6, Bit7
	);

}
void PinConnectBlockTest::selectP0_19_MOSI1_SSP(){
	ExpectedType expected = Bit7;
	compareExpectedResult(
			P0_19::MOSI1_SSP::select,
			pinsel1,
			expected,
			Bit6, Bit7
	);

}
void PinConnectBlockTest::selectP0_19_Capture_1_2_Timer1(){
	ExpectedType expected = Bit7|Bit6;
	compareExpectedResult(
			P0_19::Capture2_Timer1::select,
			pinsel1,
			expected,
			Bit6, Bit7
	);

}

void PinConnectBlockTest::selectP0_20_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_20::GPIO::select,
			pinsel1,
			expected,
			Bit8, Bit9
	);

}
void PinConnectBlockTest::selectP0_20_Match_1_3_Timer1(){
	ExpectedType expected = Bit8;
	compareExpectedResult(
			P0_20::Match3_Timer1::select,
			pinsel1,
			expected,
			Bit8, Bit9
	);

}
void PinConnectBlockTest::selectP0_20_SSEL1_SSP(){
	ExpectedType expected = Bit9;
	compareExpectedResult(
			P0_20::SSEL1_SSP::select,
			pinsel1,
			expected,
			Bit8, Bit9
	);

}
void PinConnectBlockTest::selectP0_20_EINT3(){
	ExpectedType expected = Bit9|Bit8;
	compareExpectedResult(
			P0_20::EINT3::select,
			pinsel1,
			expected,
			Bit8, Bit9
	);

}

void PinConnectBlockTest::selectP0_21_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_21::GPIO::select,
			pinsel1,
			expected,
			Bit10, Bit11
	);

}
void PinConnectBlockTest::selectP0_21_PWM5(){
	ExpectedType expected = Bit10;
	compareExpectedResult(
			P0_21::PWM5::select,
			pinsel1,
			expected,
			Bit10, Bit11
	);
}
void PinConnectBlockTest::selectP0_21_AD1_6(){
	ExpectedType expected = Bit11;
	compareExpectedResult(
			P0_21::AD1_6::select,
			pinsel1,
			expected,
			Bit10, Bit11
	);
}
void PinConnectBlockTest::selectP0_21_Capture_1_3_Timer1(){
	ExpectedType expected = Bit10|Bit11;
	compareExpectedResult(
			P0_21::Capture3_Timer1::select,
			pinsel1,
			expected,
			Bit10, Bit11
	);

}

void PinConnectBlockTest::selectP0_22_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_22::GPIO::select,
			pinsel1,
			expected,
			Bit12, Bit13
	);

}
void PinConnectBlockTest::selectP0_22_AD1_7(){
	ExpectedType expected = Bit12;
	compareExpectedResult(
			P0_22::AD1_7::select,
			pinsel1,
			expected,
			Bit12, Bit13
	);

}
void PinConnectBlockTest::selectP0_22_Capture_0_0_Timer0(){
	ExpectedType expected = Bit13;
	compareExpectedResult(
			P0_22::Capture0_Timer0::select,
			pinsel1,
			expected,
			Bit12, Bit13
	);

}
void PinConnectBlockTest::selectP0_22_Match_0_0_Timer0(){
	ExpectedType expected = Bit13|Bit12;
	compareExpectedResult(
			P0_22::Match0_Timer0::select,
			pinsel1,
			expected,
			Bit12, Bit13
	);

}

void PinConnectBlockTest::selectP0_23_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_23::GPIO::select,
			pinsel1,
			expected,
			Bit14, Bit15
	);

}
void PinConnectBlockTest::selectP0_23_VBus(){
	ExpectedType expected = Bit14;
	compareExpectedResult(
			P0_23::VBus::select,
			pinsel1,
			expected,
			Bit14, Bit15
	);

}

		//P0_24 reserved

void PinConnectBlockTest::selectP0_25_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_25::GPIO::select,
			pinsel1,
			expected,
			Bit18, Bit19
	);

}
void PinConnectBlockTest::selectP0_25_AD0_4(){
	ExpectedType expected = Bit18;
	compareExpectedResult(
			P0_25::AD0_4::select,
			pinsel1,
			expected,
			Bit18, Bit19
	);

}
void PinConnectBlockTest::selectP0_25_Aout_DAC(){
	ExpectedType expected = Bit19;
	compareExpectedResult(
			P0_25::Aout_DAC::select,
			pinsel1,
			expected,
			Bit18, Bit19
	);

}
void PinConnectBlockTest::printContext(){
	typedef Mock::LPC2131 Context;
	Generator::PrintBaseType<Context>::print(std::cout);
}
void PinConnectBlockTest::selectP0_26_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_26::GPIO::select,
			pinsel1,
			expected,
			Bit20, Bit21
	);

}
void PinConnectBlockTest::selectP0_26_AD0_5(){
	ExpectedType expected = Bit20;
	compareExpectedResult(
			P0_26::AD0_5::select,
			pinsel1,
			expected,
			Bit20, Bit21
	);

}

void PinConnectBlockTest::selectP0_27_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_27::GPIO::select,
			pinsel1,
			expected,
			Bit22, Bit23
	);

}
void PinConnectBlockTest::selectP0_27_AD0_0(){
	ExpectedType expected = Bit22;
	compareExpectedResult(
			P0_27::AD0_0::select,
			pinsel1,
			expected,
			Bit22, Bit23
	);

}
void PinConnectBlockTest::selectP0_27_Capture_0_1_Timer0(){
	ExpectedType expected = Bit23;
	compareExpectedResult(
			P0_27::Capture1_Timer0::select,
			pinsel1,
			expected,
			Bit22, Bit23
	);

}
void PinConnectBlockTest::selectP0_27_Match_0_1_Timer0(){
	ExpectedType expected = Bit22|Bit23;
	compareExpectedResult(
			P0_27::Match1_Timer0::select,
			pinsel1,
			expected,
			Bit22, Bit23
	);

}
void PinConnectBlockTest::selectP0_28_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_28::GPIO::select,
			pinsel1,
			expected,
			Bit24, Bit25
	);

}
void PinConnectBlockTest::selectP0_28_AD0_1(){
	ExpectedType expected = Bit24;
	compareExpectedResult(
			P0_28::AD0_1::select,
			pinsel1,
			expected,
			Bit24, Bit25
	);

}
void PinConnectBlockTest::selectP0_28_Capture_0_2_Timer0(){
	ExpectedType expected = Bit25;
	compareExpectedResult(
			P0_28::Capture2_Timer0::select,
			pinsel1,
			expected,
			Bit24, Bit25
	);

}
void PinConnectBlockTest::selectP0_28_Match_0_2_Timer0(){
	ExpectedType expected = Bit24|Bit25;
	compareExpectedResult(
			P0_28::Match2_Timer0::select,
			pinsel1,
			expected,
			Bit24, Bit25
	);

}


void PinConnectBlockTest::selectP0_29_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_29::GPIO::select,
			pinsel1,
			expected,
			Bit26, Bit27
	);

}
void PinConnectBlockTest::selectP0_29_AD0_2(){
	ExpectedType expected = Bit26;
	compareExpectedResult(
			P0_29::AD0_2::select,
			pinsel1,
			expected,
			Bit26, Bit27
	);

}
void PinConnectBlockTest::selectP0_29_Capture_0_3_Timer0(){
	ExpectedType expected = Bit27;
	compareExpectedResult(
			P0_29::Capture3_Timer0::select,
			pinsel1,
			expected,
			Bit26, Bit27
	);

}
void PinConnectBlockTest::selectP0_29_Match_0_3_Timer0(){
	ExpectedType expected = Bit27|Bit26;
	compareExpectedResult(
			P0_29::Match3_Timer0::select,
			pinsel1,
			expected,
			Bit26, Bit27
	);

}

void PinConnectBlockTest::selectP0_30_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_30::GPIO::select,
			pinsel1,
			expected,
			Bit28, Bit29
	);

}
void PinConnectBlockTest::selectP0_30_AD0_3(){
	ExpectedType expected = Bit28;
	compareExpectedResult(
			P0_30::AD0_3::select,
			pinsel1,
			expected,
			Bit28, Bit29
	);

}
void PinConnectBlockTest::selectP0_30_EINT3(){
	ExpectedType expected = Bit29;
	compareExpectedResult(
			P0_30::EINT3::select,
			pinsel1,
			expected,
			Bit28, Bit29
	);

}
void PinConnectBlockTest::selectP0_30_Capture_0_0_Timer0(){
	ExpectedType expected = Bit29|Bit28;
	compareExpectedResult(
			P0_30::Capture0_Timer0::select,
			pinsel1,
			expected,
			Bit28, Bit29
	);

}

void PinConnectBlockTest::selectP0_31_GPO_Port(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			P0_31::GPO_Only::select,
			pinsel1,
			expected,
			Bit30, Bit31
	);

}
void PinConnectBlockTest::selectP0_31_UP_LED(){
	ExpectedType expected = Bit30;
	typedef PCB2141::P0_31 P0_31;
	compareExpectedResult(
			P0_31::UP_LED::select,
			pinsel1,
			expected,
			Bit30, Bit31
	);

}
void PinConnectBlockTest::selectP0_31_CONNECT(){
	ExpectedType expected = Bit31;
	typedef PCB2141::P0_31 P0_31;
	compareExpectedResult(
			P0_31::CONNECT::select,
			pinsel1,
			expected,
			Bit30, Bit31
	);

}
//PinSel2
/*
void PinConnectBlockTest::selectP1_31_26_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			PCB2141::selectP1_31_26_GPIO,
			pinsel2,
			expected,
			Bit2, Bit2
	);

}
void PinConnectBlockTest::selectP1_31_26_Debug(){
	ExpectedType expected = Bit2;
	compareExpectedResult(
			PCB2141::selectP1_31_26_DEBUG,
			pinsel2,
			expected,
			Bit2, Bit2
	);

}
void PinConnectBlockTest::selectP1_25_16_GPIO(){
	ExpectedType expected = (0x0);
	compareExpectedResult(
			PCB2141::selectP1_25_16_GPIO,
			pinsel2,
			expected,
			Bit3, Bit3
	);

}
void PinConnectBlockTest::selectP1_25_16_Trace(){
	ExpectedType expected = Bit3;
	compareExpectedResult(
			PCB2141::selectP1_25_16_TRACE,
			pinsel2,
			expected,
			Bit3, Bit3
	);
}
*/

