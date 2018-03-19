/*
 * PCTest.h
 *
 *  Created on: 05.01.2014
 *      Author: Gerd
 */

#ifndef _PCTEST_H_
#define _PCTEST_H_

#include "PCTestRegister.h"
#include "RegisterTestBase.h"

class PCTest : public RegisterTestBase{
public:
	typedef Generator::Create<Mock::LPC2148>::type Hal;
	typedef Hal::PowerControl PC;

	typedef Hal::Traits Traits;
	typedef Traits::ValueType ExpectedType;

	CPPUNIT_TEST_SUITE (PCTest);
	CPPUNIT_TEST (enableDisablePCLK_Timer);
	CPPUNIT_TEST (enableDisablePCLK_UART);
	CPPUNIT_TEST (enableDisablePCLK_PWM);
	CPPUNIT_TEST (enableDisablePCLK_I2C);
	CPPUNIT_TEST (enableDisablePCLK_SPI);
	CPPUNIT_TEST (enableDisablePCLK_RTC);
	CPPUNIT_TEST (enableDisablePCLK_SSP);
	CPPUNIT_TEST (enableDisablePCLK_ADC);
//	CPPUNIT_TEST (test);
	CPPUNIT_TEST_SUITE_END ();

protected:
	void enableDisablePCLK_Timer();
	void enableDisablePCLK_UART();
	void enableDisablePCLK_PWM();
	void enableDisablePCLK_I2C();
	void enableDisablePCLK_SPI();
	void enableDisablePCLK_RTC();
	void enableDisablePCLK_SSP();
	void enableDisablePCLK_ADC();
	void test();

	// Helper
	template<class Device>
	void enableDisablePCLK_Device(ExpectedType bit);
};

#endif /* _PCTEST_H_ */
