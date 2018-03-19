#include "DisplayTestEllipse.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (DisplayTestEllipse);

void DisplayTestEllipse::fillEllipse_0_0_6_6_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0, p1(6,6);
	mock->beginInit();
	mock->setArea(p0, p1);

	int xMax = p1.x - p0.x;
	int yMax = p1.y - p0.y;

	for (int x = 1; x < xMax - 1; ++x){
		mock->setPixel(Point(p0.x+x, p0.y), expectedValue);
		mock->setPixel(Point(p0.x+x, p1.y - 1), expectedValue);
	}
	for (int y = 1; y < yMax - 1; ++y)
		for (int x = 0; x < xMax; ++x)
		{
			mock->setPixel(Point(p0.x + x, p0.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillEllipse(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestEllipse::fillEllipse_0_Hm6_6_H_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(0,HEIGHT - 6), p1(6,HEIGHT);
	mock->beginInit();
	mock->setArea(p0, p1);

	int xMax = p1.x - p0.x;
	int yMax = p1.y - p0.y;

	for (int x = 1; x < xMax - 1; ++x){
		mock->setPixel(Point(p0.x+x, p0.y), expectedValue);
		mock->setPixel(Point(p0.x+x, p1.y - 1), expectedValue);
	}
	for (int y = 1; y < yMax - 1; ++y)
		for (int x = 0; x < xMax; ++x)
		{
			mock->setPixel(Point(p0.x + x, p0.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillEllipse(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestEllipse::fillEllipse_0_Hm5_6_Hp1_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(0, HEIGHT - 5), p1(6, HEIGHT + 1);
	mock->beginInit();

	Point p1Expt(6,DisplayHALMock::HEIGHT);
	mock->setArea(p0, p1Expt);

	int xMax = p1.x - p0.x;
	int yMax = p1.y - p0.y;

	for (int x = 1; x < xMax - 1; ++x){
		mock->setPixel(Point(p0.x+x, p0.y), expectedValue);
//		mock->setPixel(Point(p0.x+x, p1.y - 1), expectedValue);
	}
	for (int y = 1; y < yMax - 1; ++y)
		for (int x = 0; x < xMax; ++x)
		{
			mock->setPixel(Point(p0.x + x, p0.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillEllipse(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestEllipse::fillEllipse_10_10_16_16_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(10,10), p1(16,16);
	mock->beginInit();
	mock->setArea(p0, p1);

	int xMax = p1.x - p0.x;
	int yMax = p1.y - p0.y;

	for (int x = 1; x < xMax - 1; ++x){
		mock->setPixel(Point(p0.x+x, p0.y), expectedValue);
		mock->setPixel(Point(p0.x+x, p1.y - 1), expectedValue);
	}
	for (int y = 1; y < yMax - 1; ++y)
		for (int x = 0; x < xMax; ++x)
		{
			mock->setPixel(Point(p0.x + x, p0.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillEllipse(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestEllipse::drawEllipse_0_0_6_6_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0, p1(6,6);
	mock->beginInit();

	mock->setArea(p0, p1);
	for (int x = 1; x < p1.x - 1; ++x){
		mock->setPixel(Point(p0.x+x, p0.y), expectedValue);
		mock->setPixel(Point(p0.x+x, p1.y - 1), expectedValue);
	}
	for (int y = 1; y < p1.y - 1; ++y)
		for (int x = 0; x < p1.x; ++x)
		{
			mock->setPixel(Point(p0.x + x, p0.y + y), expectedValue);
		}
	for (int y = 1; y < p1.y - 1; ++y)
		for (int x = 1; x < p1.x - 1; ++x)
		{
			mock->setPixel(Point(p0.x + x, p0.y + y), 0);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->drawEllipse(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestEllipse::fillEllipse_m5_m5_5_5_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);
	Point p0(-5,-5), p1(5,5);
	mock->beginInit();

//	mock->setArea(p0, p1);
	// nur innerhalb der hal grenzen schreiben
	Point p0Expt;

	mock->setArea(p0Expt, p1);

	int xMax = p1.x - p0Expt.x;
	int yMax = p1.y - p0Expt.y;

	for (int x = 0; x < xMax - 2; ++x){
		mock->setPixel(Point(p0Expt.x+x, p1.y - 1), expectedValue);
	}
	for (int x = 0; x < xMax - 1; ++x){
		mock->setPixel(Point(p0Expt.x+x, p1.y - 2), expectedValue);
	}

	for (int y = 0; y < yMax - 2; ++y)
		for (int x = 0; x < xMax; ++x)
		{
			mock->setPixel(Point(p0Expt.x + x, p0Expt.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillEllipse(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestEllipse::fillEllipse_m5_5_5_15_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(-5,5), p1(5,15);
	mock->beginInit();

//	mock->setArea(p0, p1);
	// nur innerhalb der hal grenzen schreiben
	Point p0Expt(0,5);

	mock->setArea(p0Expt, p1);

	int xMax = p1.x - p0Expt.x;
	int yMax = p1.y - p0Expt.y;

	for (int x = 0; x < xMax - 2; ++x){
		mock->setPixel(Point(p0Expt.x+x, p0.y), expectedValue);
		mock->setPixel(Point(p0Expt.x+x, p1.y-1), expectedValue);
	}
	for (int x = 0; x < xMax - 1; ++x){
		mock->setPixel(Point(p0Expt.x+x, p0.y+1), expectedValue);
		mock->setPixel(Point(p0Expt.x+x, p1.y-2), expectedValue);
	}

	for (int y = 2; y < yMax - 2; ++y)
		for (int x = 0; x < xMax; ++x)
		{
			mock->setPixel(Point(p0Expt.x + x, p0Expt.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillEllipse(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestEllipse::fillEllipse_m1_Hm6_5_H_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(-1, HEIGHT - 6), p1(5, HEIGHT);

	mock->beginInit();

	Point p0Expt(0,DisplayHALMock::HEIGHT - 6);
	mock->setArea(p0Expt, p1);

	int xMax = p1.x - p0Expt.x;
	int yMax = p1.y - p0Expt.y;

	for (int x = 0; x < xMax - 1; ++x){
		mock->setPixel(Point(p0Expt.x+x, p0.y), expectedValue);
		mock->setPixel(Point(p0Expt.x+x, p1.y - 1), expectedValue);
	}
	for (int y = 1; y < yMax -1; ++y)
		for (int x = 0; x < xMax; ++x)
		{
			mock->setPixel(Point(p0Expt.x + x, p0Expt.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillEllipse(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}
