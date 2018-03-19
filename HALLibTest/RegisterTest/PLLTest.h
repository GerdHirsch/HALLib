/*
 * SCTest.h
 *
 *  Created on: 05.01.2014
 *      Author: Gerd
 */

#ifndef PLLTEST_H_
#define PLLTEST_H_
#include "PLLTestRegister.h"
#include "RegisterTestBase.h"
class PLLTest : public RegisterTestBase{
public:
	typedef Generator::Create<Mock::LPC2148>::type Hal;
	typedef Hal::PhaseLockedLoop PLL;

	typedef Hal::Traits Traits;
	typedef Traits::ValueType ExpectedType;

	CPPUNIT_TEST_SUITE (PLLTest);
	CPPUNIT_TEST (test);
	CPPUNIT_TEST (testEnablePLL);
	CPPUNIT_TEST (testConnectEnabledPLL);
	CPPUNIT_TEST (testDisconnectPLL);
	CPPUNIT_TEST (testDisableDisconnectedPLL);
	CPPUNIT_TEST (testSetPLLSpeedInMHz);
	CPPUNIT_TEST_SUITE_END ();

protected:
	void test();
	void testEnablePLL();
	void testConnectEnabledPLL();
	void testDisconnectPLL();
	void testDisableDisconnectedPLL();
	void testSetPLLSpeedInMHz();

	template<class FunctionType>
	void simpleRegisterCompare(
				std::string id,
				FunctionType fcn,
				ExpectedType& mockRegister,
				ExpectedType bitsToSet,
				ExpectedType bitsToClear);

	template<class FunctionType, class ParamType>
	void complexRegisterCompare(
			std::string id,
			FunctionType fcn,
			ParamType param,
			ExpectedType& mockRegister,
			ExpectedType bitsToSet,
			ExpectedType bitsToClear);
};

#endif /* PLLTEST_H_ */
