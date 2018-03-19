/*
 * SCTest.cpp
 *
 *  Created on: 05.01.2014
 *      Author: Gerd
 */

#include <RegisterTest/PLLTest.h>

namespace Mock {
// Phase Locked Loop (PLL)
PLLTest::ExpectedType  PLLCON_;
PLLTest::ExpectedType  PLLCFG_;
PLLTest::ExpectedType  PLLSTAT_;
PLLTest::ExpectedType  PLLFEED_;
// IntEnable/Disable wird benötigt um während des feeds alle
// interrupts auszuschalten
PLLTest::ExpectedType IntEnable_;
PLLTest::ExpectedType IntEnClr_;
} // namespace Mock

void PLLTest::test(){
	CPPUNIT_ASSERT_MESSAGE("Todo: PLL testen", false);
}

template<class FunctionType>
void PLLTest::simpleRegisterCompare(
		std::string id,
		FunctionType fcn,
		ExpectedType& mockRegister,
		ExpectedType bitsToSet,
		ExpectedType bitsToClear) {

	mockRegister = 0;
	ExpectedType expected = bitsToSet;

	fcn();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(id + " mockRegister = 0",
			expected, mockRegister);

	mockRegister = AllBits;
	expected = AllBits & ~bitsToClear;
	fcn();
	CPPUNIT_ASSERT_EQUAL_MESSAGE(id + " mockRegister = All",
			expected, mockRegister);
}

template<class FunctionType, class ParamType>
void PLLTest::complexRegisterCompare(
		std::string id,
		FunctionType fcn,
		ParamType param,
		ExpectedType& mockRegister,
		ExpectedType bitsToSet,
		ExpectedType bitsToClear) {

	mockRegister = 0;
	ExpectedType expected = bitsToSet;

	fcn(param);
	CPPUNIT_ASSERT_EQUAL_MESSAGE(id + " mockRegister = 0",
			expected, mockRegister);

	mockRegister = AllBits;
//	expected = AllBits & ~bitsToClear;
	fcn(param);
	CPPUNIT_ASSERT_EQUAL_MESSAGE(id + " mockRegister = All",
			expected, mockRegister);
}

void PLLTest::testEnablePLL(){
	simpleRegisterCompare("enablePLL()", PLL::enablePLL, Mock::PLLCON_, Bit0, 0);
}
void PLLTest::testConnectEnabledPLL(){
	simpleRegisterCompare("connectEnabledPLL()", PLL::connectEnabledPLL, Mock::PLLCON_, Bit0|Bit1, 0);
}
void PLLTest::testDisconnectPLL(){
	simpleRegisterCompare("disablePLL()", PLL::disconnectPLL, Mock::PLLCON_, Bit0, Bit1);
}
void PLLTest::testDisableDisconnectedPLL(){
	simpleRegisterCompare("disableDisconnectedPLL()", PLL::disableDisconnectedPLL, Mock::PLLCON_, 0, Bit0|Bit1);
}
void PLLTest::testSetPLLSpeedInMHz(){
	complexRegisterCompare("setPLLSpeedInMHz()", PLL::setPLLSpeedInMHz, 60, Mock::PLLCFG_, Bit0|Bit1|Bit5, 0);
}
