#include "DisplayTestApp.h"
#include "DisplayTestBase.h"

using namespace std;

void DisplayTestBase::compareExpectedResult(){
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setArea x0",
			static_cast<int>(mock->initArea.p0.x),
			static_cast<int>(mock->testArea.p0.x));
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setArea y0",
			static_cast<int>(mock->initArea.p0.y),
			static_cast<int>(mock->testArea.p0.y));
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setArea x1",
			static_cast<int>(mock->initArea.p1.x),
			static_cast<int>(mock->testArea.p1.x));
	CPPUNIT_ASSERT_EQUAL_MESSAGE("setArea y1",
			static_cast<int>(mock->initArea.p1.y),
			static_cast<int>(mock->testArea.p1.y));

	HAL::CHAR buffer[33];

	for(size_t y = 0; y < DisplayHALMock::HEIGHT; ++y){
		for(size_t x = 0; x < DisplayHALMock::WIDTH; ++x){
			string message(testDisplay->value2string(x, buffer));
			message.append(", ");
			message.append(testDisplay->value2string(y, buffer));

			CPPUNIT_ASSERT_EQUAL_MESSAGE(message.c_str(),
					static_cast<int>(mock->expected.getPixel(x, y)),
					static_cast<int>(mock->result.getPixel(x, y)));
		}
	}

}

void DisplayTestBase::setUp ()
{
	// Vorbereitungen treffen, indem Objekte initialisiert werden
	mock = DisplayHALMock::instance = new DisplayHALMock();

	testDisplay = &Display::getInstance();
	testDisplay->clear();

	for (int i = 1; i < Display::NumColors; ++i){
		if(i < 10){
			testDisplay->setColor(i, '0' + i);
		}
		else {
			testDisplay->setColor(i, 'A' + i - 10);
		}
	}
}

void DisplayTestBase::tearDown ()
{
	// Objekte alle wieder loeschen
	delete DisplayHALMock::instance;
}
