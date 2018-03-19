#ifndef ADCTEST_H_
#define ADCTEST_H_


//#include "ADCTestRegister.h"
#include "RegisterTestBase.h"
#include <LPC21xx/ADC.h>
#include <LPC213x/ADC.h>

class ADCTest : public RegisterTestBase {
	typedef Generator::Create<Mock::LPC2134>::type Hal2134;
	typedef Generator::Create<Mock::LPC2144>::type Hal2144;

//	typedef Generator::Create<LPC213x::LPC2134>::type Hal2134x;
//	typedef Hal2134x::AD0_1 AD0_0x;
//
//
//	typedef Hal2144::AD0_1 AD0_1;
//	typedef Hal2144::AD0_2 AD0_2;
//	typedef Hal2144::AD0_3 AD0_3;
//	typedef Hal2144::AD0_4 AD0_4;
//	typedef Hal2144::AD0_6 AD0_6;
//	typedef Hal2144::AD0_7 AD0_7;
//
//	typedef Hal2134::AD0_0 AD0_0;
//	typedef Hal2134::AD0_5 AD0_5;
//
//	typedef Hal2144::AD1_0 AD1_0;
//	typedef Hal2144::AD1_1 AD1_1;
//	typedef Hal2144::AD1_2 AD1_2;
//	typedef Hal2144::AD1_3 AD1_3;
//	typedef Hal2144::AD1_4 AD1_4;
//	typedef Hal2144::AD1_5 AD1_5;
//	typedef Hal2144::AD1_6 AD1_6;
//	typedef Hal2144::AD1_7 AD1_7;


	// auf allen geräten
//	typedef Generator::Create<Generator::CS<Generator::NumberOf<HAL::AD0, 1>, Mock::LPC2144> >
//		::type AD0_1;
//	typedef Generator::Create<Generator::CS<Generator::NumberOf<HAL::AD0, 2>, Mock::LPC2144> >
//		::type AD0_2;
//	typedef Generator::Create<Generator::CS<Generator::NumberOf<HAL::AD0, 3>, Mock::LPC2144> >
//		::type AD0_3;
//	typedef Generator::Create<Generator::CS<Generator::NumberOf<HAL::AD0, 4>, Mock::LPC2144> >
//		::type AD0_4;
//	typedef Generator::Create<Generator::CS<Generator::NumberOf<HAL::AD0, 6>, Mock::LPC2144> >
//		::type AD0_6;
//	typedef Generator::Create<Generator::CS<Generator::NumberOf<HAL::AD0, 7>, Mock::LPC2144> >
//		::type AD0_7;
//
//	// nur bei 3x
//	typedef Generator::Create<Generator::CS<Generator::NumberOf<HAL::AD0, 0>, Mock::LPC2134> >
//		::type AD0_0;
//	typedef Generator::Create<Generator::CS<Generator::NumberOf<HAL::AD0, 5>, Mock::LPC2134> >
//		::type AD0_5;

	CPPUNIT_TEST_SUITE(ADCTest);
	CPPUNIT_TEST(Test);
	CPPUNIT_TEST_SUITE_END();

protected:
	void Test();
};
#endif /* ADCTEST_H_ */
