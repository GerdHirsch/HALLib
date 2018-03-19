#ifndef TIMERTEST_H_
#define TIMERTEST_H_

#include "RegisterTestBase.h"

class TimerTest : public RegisterTestBase {

	typedef Generator::Create<Mock::LPC2134>::type Hal2134;

	typedef Hal2134::Timer0 T0;

	CPPUNIT_TEST_SUITE(TimerTest);
	CPPUNIT_TEST(Test);
	CPPUNIT_TEST_SUITE_END();

protected:
	void Test();
};

#endif /* TIMERTEST_H_ */
