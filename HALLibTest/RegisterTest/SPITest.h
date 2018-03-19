#ifndef SPITEST_H_
#define SPITEST_H_

#include "RegisterTestBase.h"
//#include <LPC21xx/SPI.h>

class SPITest : public RegisterTestBase{

	typedef Generator::Create<Mock::LPC2134>::type Hal2134;
	typedef Hal2134::SPI SPI;

	CPPUNIT_TEST_SUITE (SPITest);
	CPPUNIT_TEST (Test);
	CPPUNIT_TEST_SUITE_END ();

protected:
	void Test();
};

#endif /* SPITEST_H_ */
