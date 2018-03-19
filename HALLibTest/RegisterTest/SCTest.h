/*
 * SCTest.h
 *
 *  Created on: 05.01.2014
 *      Author: Gerd
 */

#ifndef SCTEST_H_
#define SCTEST_H_
#include "SCTestRegister.h"
#include "RegisterTestBase.h"
class SCTest : public RegisterTestBase{
public:
	typedef Generator::Create<Mock::LPC2148>::type Hal;
	typedef Hal::SC SC;

	typedef Hal::Traits Traits;
	typedef Traits::ValueType ExpectedType;

	CPPUNIT_TEST_SUITE (SCTest);
	CPPUNIT_TEST (pClk_CClkTest);
//	CPPUNIT_TEST (test);
	CPPUNIT_TEST_SUITE_END ();

protected:
	void pClk_CClkTest();
	void test();
};

#endif /* SCTEST_H_ */
