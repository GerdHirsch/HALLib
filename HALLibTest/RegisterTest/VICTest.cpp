#include "VICTest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (VICTest);

namespace Mock {
VICTest::ExpectedType vicIRQStatus    = 0;
VICTest::ExpectedType vicFIQStatus    = 0;
VICTest::ExpectedType vicRawIntr      = 0;
VICTest::ExpectedType vicIntSelect    = 0;
VICTest::ExpectedType vicIntEnable    = 0;
VICTest::ExpectedType vicIntEnClr     = 0;
VICTest::ExpectedType vicSoftInt      = 0;
VICTest::ExpectedType vicSoftIntClr   = 0;
VICTest::ExpectedType vicProtection   = 0;
VICTest::ExpectedType vicVectAddr     = 0;
VICTest::ExpectedType vicDefVectAddr  = 0;
VICTest::ExpectedType vicVectAddr0    = 0;
VICTest::ExpectedType vicVectAddr1    = 0;
VICTest::ExpectedType vicVectAddr2    = 0;
VICTest::ExpectedType vicVectAddr3    = 0;
VICTest::ExpectedType vicVectAddr4    = 0;
VICTest::ExpectedType vicVectAddr5    = 0;
VICTest::ExpectedType vicVectAddr6    = 0;
VICTest::ExpectedType vicVectAddr7    = 0;
VICTest::ExpectedType vicVectAddr8    = 0;
VICTest::ExpectedType vicVectAddr9    = 0;
VICTest::ExpectedType vicVectAddr10   = 0;
VICTest::ExpectedType vicVectAddr11   = 0;
VICTest::ExpectedType vicVectAddr12   = 0;
VICTest::ExpectedType vicVectAddr13   = 0;
VICTest::ExpectedType vicVectAddr14   = 0;
VICTest::ExpectedType vicVectAddr15   = 0;
VICTest::ExpectedType vicVectCntl0    = 0;
VICTest::ExpectedType vicVectCntl1    = 0;
VICTest::ExpectedType vicVectCntl2    = 0;
VICTest::ExpectedType vicVectCntl3    = 0;
VICTest::ExpectedType vicVectCntl4    = 0;
VICTest::ExpectedType vicVectCntl5    = 0;
VICTest::ExpectedType vicVectCntl6    = 0;
VICTest::ExpectedType vicVectCntl7    = 0;
VICTest::ExpectedType vicVectCntl8    = 0;
VICTest::ExpectedType vicVectCntl9    = 0;
VICTest::ExpectedType vicVectCntl10   = 0;
VICTest::ExpectedType vicVectCntl11   = 0;
VICTest::ExpectedType vicVectCntl12   = 0;
VICTest::ExpectedType vicVectCntl13   = 0;
VICTest::ExpectedType vicVectCntl14   = 0;
VICTest::ExpectedType vicVectCntl15   = 0;

VICTest::ExpectedType* addr[] =
{
		&vicVectAddr0,
		&vicVectAddr1,
		&vicVectAddr2,
		&vicVectAddr3,
		&vicVectAddr4,
		&vicVectAddr5,
		&vicVectAddr6,
		&vicVectAddr7,
		&vicVectAddr8,
		&vicVectAddr9,
		&vicVectAddr10,
		&vicVectAddr11,
		&vicVectAddr12,
		&vicVectAddr13,
		&vicVectAddr14,
		&vicVectAddr15
};
VICTest::ExpectedType* cntl[]=
{
		&vicVectCntl0,
		&vicVectCntl1,
		&vicVectCntl2,
		&vicVectCntl3,
		&vicVectCntl4,
		&vicVectCntl5,
		&vicVectCntl6,
		&vicVectCntl7,
		&vicVectCntl8,
		&vicVectCntl9,
		&vicVectCntl10,
		&vicVectCntl11,
		&vicVectCntl12,
		&vicVectCntl13,
		&vicVectCntl14,
		&vicVectCntl15
};

} // nemaspace Mock

void deviceNameISR(){}

void VICTest::initIRQDefault(){

	VIC::initIRQDefault(deviceNameISR);
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"capture ISR Address IRQ",
			reinterpret_cast<ExpectedType>(deviceNameISR),
			Mock::vicDefVectAddr);
}

template<unsigned int DeviceNo, class Device>
void VICTest::CaptureAndEnableDisableDevice(
		ExpectedType deviceBit){

	const ExpectedType SlotNo = DeviceNo%16;

	//=================================================================
	// Software Interrupts
	//=================================================================
	ExpectedType expectedDeviceBit = deviceBit;
	Mock::vicSoftInt = 0;
	VIC::triggerSWInterrupt<Device>();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"triggerSWinterrupt 0",
			expectedDeviceBit,
			Mock::vicSoftInt);

	Mock::vicSoftIntClr = 0;
	VIC::clearSWInterrupt<Device>();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"clearSWInterrupt 0",
			expectedDeviceBit,
			Mock::vicSoftIntClr);

	expectedDeviceBit = AllBits;
	Mock::vicSoftInt = AllBits & ~deviceBit;
	VIC::triggerSWInterrupt<Device>();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"triggerSWinterrupt AllBits",
			expectedDeviceBit,
			Mock::vicSoftInt);

	Mock::vicSoftIntClr = AllBits & ~deviceBit;
	VIC::clearSWInterrupt<Device>();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"clearSWInterrupt AllBits",
			expectedDeviceBit,
			Mock::vicSoftIntClr);

	//=================================================================
	typedef typename VIC::Slot<SlotNo>::template Device<Device> IRQSlot;
	//=================================================================

	// capture
	Mock::vicIntSelect = AllBits; // IRQ löscht DeviceBit
	*Mock::addr[SlotNo] = 0;
	*Mock::cntl[SlotNo] = 0;
	IRQSlot::capture(deviceNameISR);

	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"capture ISR Address IRQ",
			reinterpret_cast<ExpectedType>(deviceNameISR),
			*Mock::addr[SlotNo]);

	ExpectedType expectedDeviceNo = Bit5|DeviceNo;
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"capture enabled and Device IRQ",
			expectedDeviceNo, // Bit5 enable Interrupt 4:0 DeviceNo
			*Mock::cntl[SlotNo]);

	expectedDeviceBit = AllBits & ~deviceBit;
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"capture IRQ",
			expectedDeviceBit, // DevicePos 0=IRQ, 1=FIQ
			Mock::vicIntSelect);

	//release
	IRQSlot::release();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"release ISR Address IRQ",
			static_cast<ExpectedType>(0),
			*Mock::addr[SlotNo]);

	expectedDeviceNo = 0;
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"release enabled and Device IRQ",
			expectedDeviceNo, // Bit5 enable Interrupt 4:0 DeviceNo
			*Mock::cntl[SlotNo]);

	// enable/disable Interrupt
	Mock::vicIntEnable = 0;
	ExpectedType expectedEnable = deviceBit;
	IRQSlot::enableInterrupt();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"enableInterrupt IRQ",
			expectedEnable, // DevicePos 1=enabled
			Mock::vicIntEnable);

	Mock::vicIntEnClr = 0;
	IRQSlot::disableInterrupt();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"disableInterrupt IRQ",
			expectedEnable, // DevicePos 1=disabled
			Mock::vicIntEnClr);

	// end of Interrupt
	Mock::vicVectAddr = reinterpret_cast<ExpectedType>(deviceNameISR);
	IRQSlot::endOfInterrupt();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"endOfInterrupt IRQ",
			static_cast<ExpectedType>(0),
			Mock::vicVectAddr);

	//=================================================================
	typedef typename IRQSlot::template Category<VIC::FIQ> FIQSlot;
	//=================================================================
	// capture
	Mock::vicIntSelect = 0; // FIQ setzt DeviceBit
	FIQSlot::capture(deviceNameISR);

	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"capture ISR Address FIQ",
			reinterpret_cast<ExpectedType>(deviceNameISR),
			*Mock::addr[SlotNo]);

	expectedDeviceNo = Bit5|DeviceNo;
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"capture enabled and Device FIQ",
			expectedDeviceNo, // Bit5 enable Interrupt 4:0 DeviceNo
			*Mock::cntl[SlotNo]);

	expectedDeviceBit = deviceBit;
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"capture FIQ",
			expectedDeviceBit, // DevicePos 0=IRQ, 1=FIQ
			Mock::vicIntSelect);

	//release
	FIQSlot::release();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"release ISR Address FIQ",
			static_cast<ExpectedType>(0),
			*Mock::addr[SlotNo]);

	expectedDeviceNo = 0;
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"release enabled and Device FIQ",
			expectedDeviceNo, // Bit5 enable Interrupt 4:0 DeviceNo
			*Mock::cntl[SlotNo]);

	// enable/disable Interrupt
	Mock::vicIntEnable = 0;
	expectedEnable = deviceBit;
	FIQSlot::enableInterrupt();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"enableInterrupt FIQ",
			expectedEnable, // DevicePos 1=enabled
			Mock::vicIntEnable);

	Mock::vicIntEnClr = 0;
	FIQSlot::disableInterrupt();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"disableInterrupt FIQ",
			expectedEnable, // DevicePos 1=disabled
			Mock::vicIntEnClr);

	// end of Interrupt
	Mock::vicVectAddr = reinterpret_cast<ExpectedType>(deviceNameISR);
	FIQSlot::endOfInterrupt();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(
			"endOfInterrupt FIQ",
			static_cast<ExpectedType>(0),
			Mock::vicVectAddr);
}

void VICTest::CaptureEnableReleaseTimer0(){
	const ExpectedType deviceNo = 4;
	ExpectedType deviceBit = Bit4;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::Timer0>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseTimer1(){
	const ExpectedType deviceNo = 5;
	ExpectedType deviceBit = Bit5;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::Timer1>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseUART0(){
	const ExpectedType deviceNo = 6;
	ExpectedType deviceBit = Bit6;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::UART0>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseUART1(){
	const ExpectedType deviceNo = 7;
	ExpectedType deviceBit = Bit7;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::UART1>(
			deviceBit);
}
void VICTest::CaptureEnableReleasePWM(){
	const ExpectedType deviceNo = 8;
	ExpectedType deviceBit = Bit8;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::PWM>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseI2C(){
	const ExpectedType deviceNo = 9;
	ExpectedType deviceBit = Bit9;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::I2C0>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseSPI(){
	const ExpectedType deviceNo = 10;
	ExpectedType deviceBit = Bit10;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::SPI>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseSSP(){
	const ExpectedType deviceNo = 11;
	ExpectedType deviceBit = Bit11;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::SSP>(
			deviceBit);
}
//void VICTest::CaptureEnableReleasePLL(){
//	const ExpectedType deviceNo = 12;
//	ExpectedType deviceBit = Bit12;
//	CaptureAndEnableDisableDevice<deviceNo, Hal2134::PLL>(
//			deviceBit);
//}
void VICTest::CaptureEnableReleaseRTC(){
	const ExpectedType deviceNo = 13;
	ExpectedType deviceBit = Bit13;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::RTC>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseEINT0(){
	const ExpectedType deviceNo = 14;
	ExpectedType deviceBit = Bit14;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::EINT::EINT<0>>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseEINT1(){
	const ExpectedType deviceNo = 15;
	ExpectedType deviceBit = Bit15;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::EINT::EINT<1>>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseEINT2(){
	const ExpectedType deviceNo = 16;
	ExpectedType deviceBit = Bit16;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::EINT::EINT<2>>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseEINT3(){
	const ExpectedType deviceNo = 17;
	ExpectedType deviceBit = Bit17;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::EINT::EINT<3>>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseADC0(){
	const ExpectedType deviceNo = 18;
	ExpectedType deviceBit = Bit18;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::ADC0>(
			deviceBit);
}
void VICTest::CaptureEnableReleaseI2C1(){
	const ExpectedType deviceNo = 19;
	ExpectedType deviceBit = Bit19;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::I2C1>(
			deviceBit);
}
//void VICTest::CaptureEnableReleaseBOD(){
//	const ExpectedType deviceNo = 20;
//	ExpectedType deviceBit = Bit20;
//	CaptureAndEnableDisableDevice<deviceNo, Hal2134::BOD>(
//			deviceBit);
//}
void VICTest::CaptureEnableReleaseADC1(){
	const ExpectedType deviceNo = 21;
	ExpectedType deviceBit = Bit21;
	CaptureAndEnableDisableDevice<deviceNo, Hal2134::ADC1>(
			deviceBit);
}

