#include "ADCTest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (ADCTest);

namespace Mock{
unsigned long ad_cr = 0;
unsigned long ad_gdr = 0;
unsigned long ad_stat = 0;
unsigned long ad_inten = 0;
unsigned long ad_drn = 0;
} // namespace Mock

void ADCTest::Test(){
//	AD0_1::selectAD();
//	AD0_2::selectAD();
//	AD0_3::selectAD();
//	AD0_4::selectAD();
//	AD0_6::selectAD();
//	AD0_7::selectAD();
//
//	AD0_0::selectAD();
//	AD0_5::selectAD();
//
//	AD1_0::selectAD();
//	AD1_1::selectAD();
//	AD1_2::selectAD();
//	AD1_3::selectAD();
//	AD1_4::selectAD();
//	AD1_5::selectAD();
//	AD1_6::selectAD();
//	AD1_7::selectAD();

	CPPUNIT_ASSERT_EQUAL_MESSAGE("TODO: Test ADC", true, false);
}
