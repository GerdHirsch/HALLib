
#ifndef MMRTEST_H_
#define MMRTEST_H_

#include "../HALLibTestApp.h"

#include "MMRTestRegister.h"

class MMRTest : public CPPUNIT_NS::TestFixture {

	typedef Generator::CS<Mock::Register, Mock::LPC2148> Origin;

	typedef Generator::Create<Origin>::type TestDevice;

	CPPUNIT_TEST_SUITE(MMRTest);

	CPPUNIT_TEST(CreateTraits);
	CPPUNIT_TEST(CreateMMR);
	CPPUNIT_TEST(UseMMR);

	CPPUNIT_TEST_SUITE_END();

	protected:
		void CreateTraits();
		void CreateMMR();
		void UseMMR();
};

#endif /* MMRTEST_H_ */
