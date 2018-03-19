/*
 * SCTest.cpp
 *
 *  Created on: 05.01.2014
 *      Author: Gerd
 */

#include <RegisterTest/SCTest.h>

namespace Mock {
// SystemControl Mock Register
// External Interrupts (EXT)
SCTest::ExpectedType  EXTINT_;
SCTest::ExpectedType  EXTWAKE_;
SCTest::ExpectedType  EXTMODE_;
SCTest::ExpectedType  EXTPOLAR_;

// Memory Accelerator Module (MAM) (MEM?? siehe Doku)
SCTest::ExpectedType  MAMCR_;
SCTest::ExpectedType  MAMTIM_;
SCTest::ExpectedType  MAMMAP_;

// VPB Divider (APB Divider?? Doku)
SCTest::ExpectedType  VPBDIV_;

// Reset
SCTest::ExpectedType  RSIR_;

// Code Security/Debugging
SCTest::ExpectedType  CSPR_;

// System Controls and Status
SCTest::ExpectedType  SCS_;
} // namespace Mock

void SCTest::test(){
	CPPUNIT_ASSERT_MESSAGE("Todo: SystemControl testen", false);
}


void SCTest::pClk_CClkTest(){
	Mock::VPBDIV_ = 0;
	ExpectedType expectedCCLK = 14745600;
	ExpectedType expectedPCLK = 3686400;

	CPPUNIT_ASSERT_EQUAL_MESSAGE("SC::CCLK()",
			expectedCCLK, SC::CCLK());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("SC::PCLK()",
			expectedPCLK, SC::PCLK());

	Mock::VPBDIV_ = Bit0;
	expectedCCLK = 14745600;
	expectedPCLK = 14745600;


	CPPUNIT_ASSERT_EQUAL_MESSAGE("SC::CCLK()",
			expectedCCLK, SC::CCLK());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("SC::PCLK()",
			expectedPCLK, SC::PCLK());

	Mock::VPBDIV_ = Bit1;
	expectedCCLK = 14745600;
	expectedPCLK = 7372800;


	CPPUNIT_ASSERT_EQUAL_MESSAGE("SC::CCLK()",
			expectedCCLK, SC::CCLK());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("SC::PCLK()",
			expectedPCLK, SC::PCLK());
}
