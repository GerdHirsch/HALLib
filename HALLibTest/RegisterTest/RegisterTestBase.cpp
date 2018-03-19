#include "../HALLibTestApp.h"
#include "RegisterTestBase.h"

void RegisterTestBase::compareExpectedResult(
			void (*pFTest)(),
			unsigned long &testRegister,
			unsigned long expected,
			unsigned long bitA,
			unsigned long bitB
		)

//template<class Function, class TestRegister, class Expected>
//void RegisterTestBase::compareExpectedResult(
//			Function pFTest,
//			TestRegister testRegister,
//			Expected expected,
//			Expected bitA,
//			Expected bitB
//		)
{
		testRegister = static_cast<unsigned long>(0x0);
		pFTest();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("0", expected, testRegister);

		testRegister = static_cast<unsigned long>(0x0) | (bitA);
		pFTest();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("0|(BitA)", expected, testRegister);

		testRegister = static_cast<unsigned long>(0x0) | (bitB);
		pFTest();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("0|(BitB)", expected, testRegister);

		testRegister = static_cast<unsigned long>(0x0) | (bitB|bitA);
		pFTest();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("0|(BitB|BitA)", expected, testRegister);

		expected = (~0x0 & ~(bitB|bitA)) | expected;

		testRegister = ~static_cast<unsigned long>(0x0);
		pFTest();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("1", expected, testRegister);

		testRegister = ~static_cast<unsigned long>(0x0) & ~(bitA);
		pFTest();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("1&~(BitA)", expected, testRegister);

		testRegister = ~static_cast<unsigned long>(0x0) & ~(bitB);
		pFTest();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("1&~(BitB)", expected, testRegister);

		testRegister = ~static_cast<unsigned long>(0x0) & ~(bitB|bitA);
		pFTest();
		CPPUNIT_ASSERT_EQUAL_MESSAGE("1&~(BitB|BitA)", expected, testRegister);
}

void RegisterTestBase::setUp ()
{
	// Vorbereitungen treffen, indem Objekte initialisiert werden
//	testDisplay = new ShadowDisplay_();
}

void RegisterTestBase::tearDown ()
{
	// Objekte alle wieder loeschen
//	delete testDisplay;
}
