#ifndef REGISTERTESTBASE_H_
#define REGISTERTESTBASE_H_

#include "../HALLibTestApp.h"

class RegisterTestBase : public CPPUNIT_NS::TestFixture {
public:
	void setUp();
	void tearDown();

protected:
//	template<class Function, class TestRegister, class Expected>
//	void compareExpectedResult(
//				Function pFTest,
//				TestRegister& testRegister,
//				Expected expected,
//				Expected bitA,
//				Expected bitB
//			);
	void compareExpectedResult(
			void (*pFTest)(),
			unsigned long &testRegister,
			unsigned long expected,
			unsigned long bitA,
			unsigned long bitB
		);
};

#endif /* REGISTERTESTBASE_H_ */
