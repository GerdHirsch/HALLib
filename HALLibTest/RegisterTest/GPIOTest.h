#ifndef GPIOTEST_H_
#define GPIOTEST_H_

#include "GPIOTestRegister.h"
#include "RegisterTestBase.h"

class GPIOTest : public RegisterTestBase{
public:
	typedef Generator::Create<Mock::LPC2134>::type Hal2134;
	typedef Hal2134::GPIO0 GPIO;
	typedef Hal2134::Traits Traits;
	typedef Traits::ValueType ExpectedType;

	CPPUNIT_TEST_SUITE (GPIOTest);
	CPPUNIT_TEST (setToMode);
	CPPUNIT_TEST (ReadWriteClear);
	CPPUNIT_TEST_SUITE_END ();

protected:
	void setToMode();
	void ReadWriteClear();
};
#endif /* GPIOTEST_H_ */
