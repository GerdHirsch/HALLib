#include "GPIOTest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (GPIOTest);

namespace Mock {
GPIOTest::ExpectedType ioPin = 0;
GPIOTest::ExpectedType ioSet = 0;
GPIOTest::ExpectedType ioDir = 0;
GPIOTest::ExpectedType ioClr = 0;
} // namespace Mock

void GPIOTest::setToMode(){
	ExpectedType expected = 0;

	expected |= Bit0;

	GPIO::setToOutputMode(Bit0);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setToOutputMode(Bit0)",
			expected, Mock::ioDir);

	GPIO::setToInputMode(Bit0);
	expected = 0;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setToInputMode(Bit0)",
			expected, Mock::ioDir);

	GPIO::setToOutputMode(Bit0|Bit1|Bit2);
	expected = Bit0|Bit1|Bit2;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setToOutputMode(Bit0|Bit1|Bit2)",
			expected, Mock::ioDir);

	GPIO::setToInputMode(Bit1);
	expected &= ~Bit1;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setToInputMode(Bit1)",
			expected, Mock::ioDir);


}

void GPIOTest::ReadWriteClear(){
	ExpectedType expected = 0;

	//write
	expected = Bit0;

	GPIO::write(Bit0);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("write(Bit0)",
			expected, Mock::ioSet);
	//read
	Mock::ioPin = Bit0;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("read()",
			expected, GPIO::read());
	//readPin
	Mock::ioPin = Bit0 | Bit1 | Bit2;
	expected = Bit1;
	CPPUNIT_ASSERT_EQUAL_MESSAGE("readPin(Bit1)",
			expected, GPIO::readPin(Bit1));
	//clear
	Mock::ioClr = 0;
	expected = Bit1;

	GPIO::clear(Bit1);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Clear(Bit1)",
			expected,  Mock::ioClr);

	Mock::ioClr = 0;
	expected = Bit0|Bit1|Bit2;
	GPIO::clear(Bit0|Bit1|Bit2);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Clear(Bit0|Bit1|Bit2)",
			expected,  Mock::ioClr);



}
