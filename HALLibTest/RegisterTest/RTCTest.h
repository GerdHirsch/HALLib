/*
 * RTCTest.h
 *
 *  Created on: 30.12.2013
 *      Author: Gerd
 */

#ifndef RTCTEST_H_
#define RTCTEST_H_
#include "RTCTestRegister.h"
#include "SCTestRegister.h"
#include "RegisterTestBase.h"

class RTCTest : public RegisterTestBase{
public:
	typedef Generator::Create<Mock::LPC2134>::type Hal2134;
	typedef Hal2134::RTC RTC;
	typedef Hal2134::SC SC;
	typedef RTC::IRMask IRMask;

	typedef Hal2134::Traits Traits;
	typedef Traits::ValueType ExpectedType;

	CPPUNIT_TEST_SUITE (RTCTest);
	CPPUNIT_TEST (initPrescalerFromPeripheralClock);
	CPPUNIT_TEST (connectWith32KHzPeripheralClock);
	CPPUNIT_TEST (startStopRTC);
	CPPUNIT_TEST (resetClockTickCounter);
	CPPUNIT_TEST (setGetClockTime);
	CPPUNIT_TEST (setGetAlarmTime);
	CPPUNIT_TEST (setGetClockDate);
	CPPUNIT_TEST (setGetAlarmDate);
	CPPUNIT_TEST (enableDisableClockInterrupt);
	CPPUNIT_TEST (enableDisableAlarmInterrupt);
	CPPUNIT_TEST (isInterruptSource);
//	CPPUNIT_TEST (test);
	CPPUNIT_TEST_SUITE_END ();

protected:
	void initPrescalerFromPeripheralClock();
	void connectWith32KHzPeripheralClock();
	void startStopRTC();
	void resetClockTickCounter();
	void setGetClockTime();
	void setGetAlarmTime();
	void setGetClockDate();
	void setGetAlarmDate();
	void enableDisableClockInterrupt();
	void enableDisableAlarmInterrupt();
	void isInterruptSource();
	void test();

	//=================================================================
	// Helper Clock und Alarm Tests
	template<class ToTest>
	void setGetTime(
			ExpectedType& sec,
			ExpectedType& min,
			ExpectedType& hour);

	template<class ToTest>
	void setGetDate(
			ExpectedType& dom,
			ExpectedType& month,
			ExpectedType& year);

	// berechnet mit Op::getExpectedValue (AlarmOp und ClockOp)
	template<class ToTest, class Op>
	void enableDisableInterrupt(ExpectedType& interruptRegister);


	struct AlarmOp{
		static ExpectedType getExpectedValue(IRMask mask){
			return 0xFF & ~mask;
		}
	};
	struct ClockOp{
		static ExpectedType getExpectedValue(IRMask mask){
			return mask;
		}
	};
	//=================================================================
};

#endif /* RTCTEST_H_ */
