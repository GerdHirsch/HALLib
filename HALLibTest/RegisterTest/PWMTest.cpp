#include "PWMTest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (PWMTest);

namespace Mock {
// Allgemeine PWM Register
PWMTest::ExpectedType pwm_tcr	= 0;
PWMTest::ExpectedType pwm_tc	= 0;
PWMTest::ExpectedType pwm_pr	= 0;
PWMTest::ExpectedType pwm_pc	= 0;
//wird von allen benötigt
PWMTest::ExpectedType pwm_ir	= 0;
PWMTest::ExpectedType pwm_mcr	= 0;
PWMTest::ExpectedType pwm_ler	= 0;
PWMTest::ExpectedType pwm_mr0	= 0;

//PWMn spezifische
PWMTest::ExpectedType pwm_pcr	= 0;
PWMTest::ExpectedType pwm_mrn	= 0;
} // namespace Mock

using namespace Mock;

void PWMTest::Test(){
	PWM::enablePWM();
	PWM1::enablePWMOutput();
	PWM2::enablePWMOutput();
	PWM3::enablePWMOutput();
	PWM4::enablePWMOutput();
	PWM5::enablePWMOutput();
	PWM6::enablePWMOutput();

	CPPUNIT_ASSERT_EQUAL_MESSAGE("TODO: Test PWM", true, false);

}
void PWMTest::enablePWM(){
	ExpectedType expected = 0x0;

	expected |= Bit3;

	PWM::enablePWM();

	CPPUNIT_ASSERT_EQUAL_MESSAGE("PWM::enablePWM()", expected, pwm_tcr);
	//	compareExpectedResult(
//			PWM::enablePWM();
//			pwm_tcr,
//			expected,
//			Bit0, Bit1
//	);
}

