#include "DisplayTestLine.h"


//CPPUNIT_TEST_SUITE_REGISTRATION (DisplayTestLine);

void DisplayTestLine::drawVertical_3_0_3_6_Test(){

	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(3, 0), p1(3, 6);
	//U32 x0 = 0, y0 = 0, x1 = 3, y1 = 3;

	mock->beginInit();

	mock->setArea(p0, Point(p1.x + 1, p1.y + 1));
//	mock->setArea(p0, Point(p1.x + 1, p1.y));

	drawVerticalLine(p0, p1.y, expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->drawLine(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestLine::drawHorizontal_0_3_6_3_Test(){

	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(0, 3), p1(6, 3);
	//U32 x0 = 0, y0 = 0, x1 = 3, y1 = 3;

	mock->beginInit();

	mock->setArea(p0, Point(p1.x + 1, p1.y + 1));

	drawHorizontalLine(p0, p1.x, expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->drawLine(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestLine::drawLine_0_0_3_3_Test(){

	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0, p1(3,3);
	//U32 x0 = 0, y0 = 0, x1 = 3, y1 = 3;

	mock->beginInit();

	mock->setArea(p0, p1);
	mock->setPixel(p0, expectedValue);
	mock->setPixel(Point(p0.x+1, p0.y+1), expectedValue);
	mock->setPixel(Point(p0.x+2, p0.y+2), expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->drawLine(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestLine::drawLine_m3_m3_3_3_Test(){

	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(-3, -3), p1(3, 3);
	Point p0Expt;
	//U32 x0 = 0, y0 = 0, x1 = 3, y1 = 3;

	mock->beginInit();

	mock->setArea(p0Expt, p1);

	mock->setPixel(p0Expt, expectedValue);
	mock->setPixel(Point(p0Expt.x+1, p0Expt.y+1), expectedValue);
	mock->setPixel(Point(p0Expt.x+2, p0Expt.y+2), expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->drawLine(p0, p1, colorIndex, true);

	mock->endTest();

	mock->print();

	compareExpectedResult();
}
