#ifndef PWMTEST_H_
#define PWMTEST_H_

#include "RegisterTestBase.h"
#include <LPC21xx/PWM.h>

class PWMTest : public RegisterTestBase
{
public:

	typedef Generator::Create<Mock::LPC2141>::type Hal2141;
	typedef Hal2141::PWM PWM;
	//	typedef Generator::Create<Generator::CS<HAL::PWM, Mock::LPC2141> >::type PWM;
	typedef Hal2141::Traits Traits;
	typedef Traits::ValueType ExpectedType;

	typedef PWM::PWM1 PWM1;
	typedef PWM::PWM2 PWM2;
	typedef PWM::PWM3 PWM3;
	typedef PWM::PWM4 PWM4;
	typedef PWM::PWM5 PWM5;
	typedef PWM::PWM6 PWM6;

	CPPUNIT_TEST_SUITE (PWMTest);
	CPPUNIT_TEST (enablePWM);
	CPPUNIT_TEST (Test);
	CPPUNIT_TEST_SUITE_END ();

protected:
	void Test();
	void enablePWM();
};

#endif /* PWMTEST_H_ */
