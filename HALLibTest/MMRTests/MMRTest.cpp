#include "MMRTest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (MMRTest);

namespace Mock{
unsigned long testMockRegister = 0;
}

using namespace Generator;

void MMRTest::CreateTraits(){
	typedef Create<CS<HAL::Traits, LPC21xx::Base> >::type Traits;
	typedef Traits::ProcessorType ProcessorType;
}

void MMRTest::CreateMMR(){

	typedef CS<Mock::Register, Mock::Base> Selector;

	typedef TestDevice Result;

//	Generator::PrintBaseType<Origin>::print();

	typedef Mock::TestMockRegister<Mock::Base, Selector, Origin, EmptyRepository> Expected;
	//============================================
	TestComponent<Expected, Result>::test();
	//============================================
}

void MMRTest::UseMMR(){
	typedef TestDevice::TestRegister TestRegister;
	unsigned long bit12 = Bit12;
	unsigned long bit13 = Bit13;
	unsigned long bit14 = Bit14;

	TestRegister::setBit(Bit13);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Bit13", Mock::testMockRegister, bit13);

	TestRegister::setBit(Bit14);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Bit14|Bit13", Mock::testMockRegister, bit14|bit13);

	CPPUNIT_ASSERT_EQUAL_MESSAGE("readBit(Bit13)",
			static_cast<unsigned long>(TestRegister::readBit(Bit13)),
			static_cast<unsigned long>(bit13));
	CPPUNIT_ASSERT_EQUAL_MESSAGE("readBit(Bit14)",
			static_cast<long unsigned int>(TestRegister::readBit(Bit14)),
			static_cast<long unsigned int>(bit14));
	CPPUNIT_ASSERT_EQUAL_MESSAGE("read():Bit14|Bit13",
			static_cast<long unsigned int>(TestRegister::read()),
			static_cast<long unsigned int>(bit14|bit13));

	TestRegister::clearBit(Bit13);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Bit13", Mock::testMockRegister & Bit13, 0x0UL);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Bit14", Mock::testMockRegister, bit14);

	TestRegister::set(Bit12);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Bit12", Mock::testMockRegister, bit12);

	TestRegister::setBit(Bit14|Bit13);
	CPPUNIT_ASSERT_EQUAL_MESSAGE("Bit14|Bit13", Mock::testMockRegister, bit14|bit13|bit12);
}
