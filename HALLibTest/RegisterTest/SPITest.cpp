#include "SPITest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (SPITest);

namespace Mock {
unsigned long  s0spcr	= 0;
unsigned long  s0spsr	= 0;
unsigned long  s0spdr	= 0;
unsigned long  s0spccr	= 0;
unsigned long  s0spint	= 0;
} // namespace Mock

void SPITest::Test(){
	unsigned long expected = 0;

	expected |= Bit5;
	SPI::setMasterMode();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setMasterMode()", expected, Mock::s0spcr);

	expected = 0;
	SPI::setSlaveMode();
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setSlaveMode()", expected, Mock::s0spcr);

	expected = Bit2|Bit3|Bit5;
	SPI::writeData(Bit2|Bit3|Bit5);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("writeData(Bit2|Bit3|Bit5)", expected, Mock::s0spdr);

	expected = Bit3;
	SPI::setClockRate(Bit3);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setClockRate(Bit3)", expected, Mock::s0spccr);

	expected = Bit3;
	SPI::setClockRate(Bit2);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setClockRate(Bit2)", expected, Mock::s0spccr);

	expected = Bit5;
	SPI::setClockRate(Bit5);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setClockRate(Bit5)", expected, Mock::s0spccr);

	expected = Bit2|Bit5|Bit7;
	SPI::setClockRate(Bit0|Bit2|Bit5|Bit7);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setClockRate(Bit0|Bit2|Bit5|Bit7)", expected, Mock::s0spccr);

	expected = Bit2|Bit8|Bit11;
	SPI::setTransferRate(SPI::TransferBits_9());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTransferRate(SPI::TransferBits_9())", expected, Mock::s0spcr);

	expected = Bit2|Bit8|Bit9|Bit11;
	SPI::setTransferRate(SPI::TransferBits_11());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTransferRate(SPI::TransferBits_11())", expected, Mock::s0spcr);

	expected = 0;
	SPI::setTransferRate(SPI::TransferBits_8());
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setTransferRate(SPI::TransferBits_8())", expected, Mock::s0spcr&Bit2);


	Mock::s0spsr = 0;
	CPPUNIT_ASSERT_MESSAGE("!isSlaveAbort()", !SPI::isSlaveAbort());
	Mock::s0spsr = Bit3;
	CPPUNIT_ASSERT_MESSAGE("isSlaveAbort()", SPI::isSlaveAbort());

	CPPUNIT_ASSERT_MESSAGE("!isModeFault()", !SPI::isModeFault());
	Mock::s0spsr = Bit4;
	CPPUNIT_ASSERT_MESSAGE("isModeFault()", SPI::isModeFault());

	CPPUNIT_ASSERT_MESSAGE("!isReadOverrun()", !SPI::isReadOverrun());
	Mock::s0spsr = Bit5;
	CPPUNIT_ASSERT_MESSAGE("isReadOverrun()", SPI::isReadOverrun());

	CPPUNIT_ASSERT_MESSAGE("!isWriteCollision()", !SPI::isWriteCollision());
	Mock::s0spsr = Bit6;
	CPPUNIT_ASSERT_MESSAGE("isWriteCollision()", SPI::isWriteCollision());

	CPPUNIT_ASSERT_MESSAGE("!isTransferComplete()", !SPI::isTransferComplete());
	Mock::s0spsr = Bit7;
	CPPUNIT_ASSERT_MESSAGE("isTransferComplete()", SPI::isTransferComplete());

}
