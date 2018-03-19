/*
 * PCTest.cpp
 *
 *  Created on: 05.01.2014
 *      Author: Gerd
 */

#include <RegisterTest/PCTest.h>

namespace Mock {
// Power Control (PC) Mock Register
PCTest::ExpectedType  PCON_;
PCTest::ExpectedType  PCONP_;
} // namespace Mock

void PCTest::test(){
	CPPUNIT_ASSERT_MESSAGE("Todo: PowerControl testen", false);
}

template<class Device>
void PCTest::enableDisablePCLK_Device(ExpectedType bit){
	const ExpectedType AllDevices = 0x817BE;
	Mock::PCONP_ = 0;
	ExpectedType expected = bit;

	PC::connectPCLK<Device>();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("connectPCLK<Device>()",
			expected, Mock::PCONP_);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("true isConnectedPCLK<Device>()",
			true, PC::isConnectedPCLK<Device>());

	Mock::PCONP_ = AllDevices;
	expected = AllDevices & ~bit;
	PC::disconnectPCLK<Device>();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("disconnectPCLK<Device>()",
			expected, Mock::PCONP_);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("true isConnectedPCLK<Device>()",
			false, PC::isConnectedPCLK<Device>());
}
//Timer Bit1, Bit2
void PCTest::enableDisablePCLK_Timer(){
	enableDisablePCLK_Device<Hal::Timer0>(Bit1);
	enableDisablePCLK_Device<Hal::Timer1>(Bit2);
}
//UART Bit3, Bit4
void PCTest::enableDisablePCLK_UART(){
	enableDisablePCLK_Device<Hal::UART0>(Bit3);
	enableDisablePCLK_Device<Hal::UART1>(Bit4);
}
//PWM Bit5
void PCTest::enableDisablePCLK_PWM(){
	enableDisablePCLK_Device<Hal::PWM>(Bit5);
}
//Reserved Bit6
//I2C0 Bit7
void PCTest::enableDisablePCLK_I2C(){
	enableDisablePCLK_Device<Hal::I2C0>(Bit7);
}
//SPI Bit8
void PCTest::enableDisablePCLK_SPI(){
	enableDisablePCLK_Device<Hal::SPI>(Bit8);
}
//RTC Bit9
void PCTest::enableDisablePCLK_RTC(){
	enableDisablePCLK_Device<Hal::RTC>(Bit9);
}
//SSP SPI1 Bit10
void PCTest::enableDisablePCLK_SSP(){
	enableDisablePCLK_Device<Hal::SSP>(Bit10);
}
//Reserved Bit11
//ADC0 Bit12
void PCTest::enableDisablePCLK_ADC(){
	enableDisablePCLK_Device<Hal::ADC0>(Bit12);
}
