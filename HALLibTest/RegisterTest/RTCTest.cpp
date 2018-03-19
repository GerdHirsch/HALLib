/*
 * RTCTest.cpp
 *
 *  Created on: 30.12.2013
 *      Author: Gerd
 */

#include <RegisterTest/RTCTest.h>

namespace Mock {
// RTC Mock Register
RTCTest::ExpectedType  Ilr = 0;
RTCTest::ExpectedType  Ctc = 0;
RTCTest::ExpectedType  Ccr = 0;
RTCTest::ExpectedType  Ciir = 0;
RTCTest::ExpectedType  Amr = 0;
RTCTest::ExpectedType  CTime0 = 0;
RTCTest::ExpectedType  CTime1 = 0;
RTCTest::ExpectedType  CTime2 = 0;
RTCTest::ExpectedType  Clk_sec = 0;
RTCTest::ExpectedType  Clk_min = 0;
RTCTest::ExpectedType  Clk_hour = 0;
RTCTest::ExpectedType  Clk_dom = 0;
RTCTest::ExpectedType  Clk_dow = 0;
RTCTest::ExpectedType  Clk_doy = 0;
RTCTest::ExpectedType  Clk_month = 0;
RTCTest::ExpectedType  Clk_year = 0;
RTCTest::ExpectedType  Al_sec = 0;
RTCTest::ExpectedType  Al_min = 0;
RTCTest::ExpectedType  Al_hour = 0;
RTCTest::ExpectedType  Al_dom = 0;
RTCTest::ExpectedType  Al_dow = 0;
RTCTest::ExpectedType  Al_doy = 0;
RTCTest::ExpectedType  Al_month = 0;
RTCTest::ExpectedType  Al_year = 0;
RTCTest::ExpectedType  Preint = 0;
RTCTest::ExpectedType  Prefrac = 0;
} // namespace Mock

void RTCTest::test(){
	CPPUNIT_ASSERT_MESSAGE("Todo: RTC testen", false);
}

void RTCTest::initPrescalerFromPeripheralClock(){

	Mock::VPBDIV_ = 0;
	ExpectedType expectedInt = 111;
	ExpectedType expectedFrac = 16384;

	RTC::initPrescalerFromPeripheralClock();

	CPPUNIT_ASSERT_EQUAL_MESSAGE("Preint Mock::VPBDIV_ = 0",
			expectedInt, Mock::Preint);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("Prefrac Mock::VPBDIV_ = 0",
			expectedFrac, Mock::Prefrac);

	Mock::VPBDIV_ = Bit0 | Bit1;
	expectedInt = 111;
	expectedFrac = 16384;

	RTC::initPrescalerFromPeripheralClock();

	CPPUNIT_ASSERT_EQUAL_MESSAGE("Preint Mock::VPBDIV_ = Bit0 | Bit1",
			expectedInt, Mock::Preint);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("Prefrac Mock::VPBDIV_ = Bit0 | Bit1",
			expectedFrac, Mock::Prefrac);

	Mock::VPBDIV_ = Bit0;
	expectedInt = 449;
	expectedFrac = 0;
	RTC::initPrescalerFromPeripheralClock();

	CPPUNIT_ASSERT_EQUAL_MESSAGE("Preint Mock::VPBDIV_ = Bit0",
			expectedInt, Mock::Preint);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("Prefrac Mock::VPBDIV_ = Bit0",
			expectedFrac, Mock::Prefrac);

	Mock::VPBDIV_ = Bit1;
	expectedInt = 224;
	expectedFrac = 0;
	RTC::initPrescalerFromPeripheralClock();

	CPPUNIT_ASSERT_EQUAL_MESSAGE("Preint Mock::VPBDIV_ = Bit1",
			expectedInt, Mock::Preint);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("Prefrac Mock::VPBDIV_ =Bit1",
			expectedFrac, Mock::Prefrac);
}

void RTCTest::connectWith32KHzPeripheralClock(){
	Mock::Ccr = Bit0 | Bit1;

	ExpectedType expected = Bit0 | Bit1 | Bit4;
	RTC::connectWith32KHzClock();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("connectWith32KHzClock()",
				expected, Mock::Ccr);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("true isConnectedWith32KHzClock()",
				true, RTC::isConnectedWith32KHzClock());

	expected = Bit0 | Bit1;
	RTC::connectWithPeripheralClock();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("connectWithPeripheralClock()",
			expected, Mock::Ccr);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("false isConnectedWith32KHzClock()",
				false, RTC::isConnectedWith32KHzClock());
}

void RTCTest::startStopRTC(){
	Mock::Ccr = Bit1 | Bit4;

	ExpectedType expected = Bit0 | Bit1 | Bit4;
	RTC::startRTC();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("startRTC()",
				expected, Mock::Ccr);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("isClockEnabled()",
				true, RTC::isClockEnabled());

	expected = Bit1 | Bit4;
	RTC::stopRTC();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("stopRTC()",
				expected, Mock::Ccr);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("isClockEnabled()",
				false, RTC::isClockEnabled());
}

void RTCTest::resetClockTickCounter(){
	// reset setBit/clearBit(Bit1)
	Mock::Ccr = Bit0 | Bit1 | Bit4;

	ExpectedType expected = Bit0 | Bit4;
	RTC::resetClockTickCounter();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("resetClockTickCounter()",
				expected, Mock::Ccr);
}

template<class ToTest>
void RTCTest::setGetTime(ExpectedType& sec, ExpectedType& min, ExpectedType& hour)
{
	ExpectedType expectedHour = 1;
	ExpectedType expectedMin = 1;
	ExpectedType expectedSec = 1;

	//Set
	ToTest::setTime(1, 1, 1);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTime(1, 1, 1)",
			expectedHour, hour);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTime(1, 1, 1)",
			expectedMin, min);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTime(1, 1, 1)",
			expectedSec, sec);
	//Get
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getTime(1, 1, 1)",
			expectedHour, ToTest::getHour());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getTime(1, 1, 1)",
			expectedMin, ToTest::getMin());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getTime(1, 1, 1)",
			expectedSec, ToTest::getSec());

	expectedHour = 2;
	expectedMin = 3;
	expectedSec = 4;
	//Set
	ToTest::setTime(2, 3, 4);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTime(2, 3, 4)",
			expectedHour, hour);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTime(2, 3, 4)",
			expectedMin, min);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTime(2, 3, 4)",
			expectedSec, sec);
	//Get
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getTime(2, 3, 4)",
			expectedHour, ToTest::getHour());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getTime(2, 3, 4)",
			expectedMin, ToTest::getMin());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getTime(2, 3, 4)",
			expectedSec, ToTest::getSec());
}
void RTCTest::setGetClockTime(){
	typedef RTC::Clock ToTest;
	setGetTime<ToTest>(Mock::Clk_sec, Mock::Clk_min, Mock::Clk_hour);
}
void RTCTest::setGetAlarmTime(){
	typedef RTC::Alarm ToTest;
	setGetTime<ToTest>(Mock::Al_sec, Mock::Al_min, Mock::Al_hour);
}

template<class ToTest>
void RTCTest::setGetDate(ExpectedType& dom, ExpectedType& month, ExpectedType& year)
{
	ExpectedType expectedYear = 2014;
	ExpectedType expectedMonth = 1;
	ExpectedType expectedDay = 1;

	ToTest::setDate(expectedYear, expectedMonth, expectedDay);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTime(2014, 1, 1)",
			expectedYear, year);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTime(2014, 1, 1)",
			expectedMonth, month);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTime(2014, 1, 1)",
			expectedDay, dom);
	//Get
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getDate(2014, 1, 1)",
			expectedYear, ToTest::getYear());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getDate(20141, 1, 1)",
			expectedMonth, ToTest::getMonth());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getDate(2014, 1, 1)",
			expectedDay, ToTest::getDayOfMonth());
}
void RTCTest::setGetClockDate(){
	typedef RTC::Clock ToTest;
	setGetDate<ToTest>(Mock::Clk_dom, Mock::Clk_month, Mock::Clk_year);
}
void RTCTest::setGetAlarmDate(){
	typedef RTC::Alarm ToTest;
	setGetDate<ToTest>(Mock::Al_dom, Mock::Al_month, Mock::Al_year);
}

template<class ToTest, class Op>
void RTCTest::enableDisableInterrupt(ExpectedType& testRegister){
	IRMask mask = IRMask(RTC::SEC | RTC::HOUR | RTC::MON);

	ExpectedType expected = Op::getExpectedValue(mask);
	ToTest::enableInterruptOn(mask);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("enableInterruptOn(RTC::SEC | RTC::HOUR | RTC::MON)",
			expected, testRegister);

	ExpectedType expectedMask = mask;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getEnabledInterrupts()",
			expectedMask, ToTest::getEnabledInterrupts());

	expected = Op::getExpectedValue(IRMask(RTC::HOUR | RTC::MON));
	ToTest::removeInterruptOn(RTC::SEC);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("removeInterruptOn(RTC::SEC)",
			expected, testRegister);

	expected = Op::getExpectedValue(IRMask(RTC::SEC | RTC::HOUR | RTC::MON));
	ToTest::addInterruptOn(RTC::SEC);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("addInterruptOn(RTC::SEC)",
			expected, testRegister);

	mask = IRMask(RTC::MIN | RTC::YEAR);
	expected = Op::getExpectedValue(mask);
	ToTest::enableInterruptOn(mask);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("enableInterruptOn(RTC::MIN | RTC::YEAR)",
			expected, testRegister);

	expectedMask = mask;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("getEnabledInterrupts()",
			expectedMask, ToTest::getEnabledInterrupts());

	expected = Op::getExpectedValue(RTC::NONE);
	ToTest::disableAllInterrupts();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("disableAllInterrupts()",
			expected, testRegister);
}
void RTCTest::enableDisableClockInterrupt(){
	ExpectedType& testRegister = Mock::Ciir;
	typedef RTC::Clock ToTest;

	enableDisableInterrupt<ToTest, ClockOp>(testRegister);
}
void RTCTest::enableDisableAlarmInterrupt(){
	ExpectedType& testRegister = Mock::Amr;
	typedef RTC::Alarm ToTest;

	enableDisableInterrupt<ToTest, AlarmOp>(testRegister);
}

void RTCTest::isInterruptSource(){
	/* The Interrupt Location Register is a 2-bit register that
	 * specifies which blocks are generating an interrupt (see Table 262).
	 * Writing a one to the appropriate bit clears the corresponding
	 * interrupt.
	 * Writing a zero has no effect. This allows the
	 * programmer to read this register and write back the same value
	 * to clear only the interrupt that is detected by the read. */
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Clock::isInterruptSource)",
			false, RTC::Clock::isInterruptSource());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Alarm::isInterruptSource)",
			false, RTC::Alarm::isInterruptSource());
	ExpectedType expected = 0;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("RTC::getInterruptSource)",
			expected, RTC::getInterruptSource());

	Mock::Ilr = Bit0;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Clock::isInterruptSource)",
			true, RTC::Clock::isInterruptSource());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Alarm::isInterruptSource)",
			false, RTC::Alarm::isInterruptSource());
	expected = Bit0;;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("RTC::getInterruptSource)",
			expected, RTC::getInterruptSource());

	Mock::Ilr = Bit1;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Clock::isInterruptSource)",
			false, RTC::Clock::isInterruptSource());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Alarm::isInterruptSource)",
			true, RTC::Alarm::isInterruptSource());
	expected = Bit1;;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("RTC::getInterruptSource)",
			expected, RTC::getInterruptSource());

	//Mock::Ilr = Bit0 | Bit1;
	RTC::clearAllInterruptFlags();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Clock::isInterruptSource)",
			true, RTC::Clock::isInterruptSource());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Alarm::isInterruptSource)",
			true, RTC::Alarm::isInterruptSource());
	expected = Bit1 | Bit0;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("RTC::getInterruptSource)",
			expected, RTC::getInterruptSource());

	/*
	 * Interrupt Location.
	 * Reading this location indicates the source of an interrupt.
	 * Writing a one to the appropriate bit at this location
	 * clears the associated interrupt.
	 */
	Mock::Ilr = 0;
	RTC::Clock::clearInterruptFlag();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Clock::clearInterruptFlag)",
			true, RTC::Clock::isInterruptSource());
	Mock::Ilr = 0;
	RTC::Alarm::clearInterruptFlag();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Alarm::clearInterruptFlag)",
			true, RTC::Alarm::isInterruptSource());


}


