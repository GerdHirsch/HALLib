#include "TimerTest.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (TimerTest);

namespace Mock{
unsigned long ir = 0;
unsigned  long tcr = 0;
unsigned  long tc = 0;
unsigned  long pr = 0;
unsigned  long pc = 0;
unsigned  long mcr = 0;
unsigned  long mr0 = 0;
unsigned  long mr1 = 0;
unsigned  long mr2 = 0;
unsigned  long mr3 = 0;
unsigned  long ccr = 0;
unsigned  long cr0 = 0;
unsigned  long cr1 = 0;
unsigned  long cr2 = 0;
unsigned  long cr3 = 0;
unsigned  long emr = 0;
unsigned  long ctcr = 0;
} // namespace Mock

void TimerTest::Test(){
	Mock::ir=10;
//	T0::IR::read();
	T0::startTimer();

	CPPUNIT_ASSERT_MESSAGE("Todo: Timer testen",false);
}
