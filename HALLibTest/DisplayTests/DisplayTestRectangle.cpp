#include "DisplayTestRectangle.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (DisplayTestRectangle);

void DisplayTestRectangle::fillRectangle_0_0_6_6_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0, p1(6,6);
	mock->beginInit();

	mock->setArea(p0, p1);

	for (int y = 0; y < p1.y ; ++y)
		for (int x = 0; x < p1.x; ++x)
		{
			mock->setPixel(Point(p0.x + x, p0.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::fillRectangle_0_0_WIDTH_HEIGHT_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0, p1(DisplayHALMock::WIDTH, DisplayHALMock::HEIGHT);
	mock->beginInit();

	mock->setArea(p0, p1);

	for (int y = 0; y < p1.y ; ++y)
		for (int x = 0; x < p1.x; ++x)
		{
			mock->setPixel(Point(p0.x + x, p0.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::fillRectangle_m5_m5_5_5_Test ()
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

	for (int y = 0; y < yMax; ++y)
		for (int x = 0; x < xMax; ++x)
		{
			mock->setPixel(Point(p0Expt.x + x, p0Expt.y + y), expectedValue);
		}


	mock->endInit();
	mock->beginTest();

	testDisplay->fillRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

//====================================================

void DisplayTestRectangle::drawRectangle_0_0_6_6_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0, p1(6,6);
	mock->beginInit();

	mock->setArea(p0, p1);

	for (int x = 0; x < p1.x ; ++x){
			mock->setPixel(Point(p0.x+x, p0.y), expectedValue);
			mock->setPixel(Point(p0.x+x, p1.y - 1), expectedValue);
	}
	for (int y = 0; y < p1.y ; ++y){
			mock->setPixel(Point(p0.x, p0.y + y), expectedValue);
			mock->setPixel(Point(p1.x - 1, p0.y + y), expectedValue);
	}


	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::drawRectangle_10_10_16_16_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(10,10), p1(16,16);
	mock->beginInit();

	mock->setArea(p0, p1);

	int xMax = p1.x - p0.x;
	int yMax = p1.y - p0.y;

	for (int x = 0; x < xMax ; ++x){
			mock->setPixel(Point(p0.x+x, p0.y), expectedValue);
			mock->setPixel(Point(p0.x+x, p1.y - 1), expectedValue);
	}
	for (int y = 0; y < yMax; ++y){
			mock->setPixel(Point(p0.x, p0.y + y), expectedValue);
			mock->setPixel(Point(p1.x - 1, p0.y + y), expectedValue);
	}


	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

// TODO: drawRect(10,10,W,H);

//----------------------------------------------------

// tests mit p0/p1-9
/*		p0
 * 		   1 ___2___	3
 * 			|		|
 * 		   4|	5	|	6
 * 			|_______|
 * 	       7	8		9
 */

void DisplayTestRectangle::draw1_m5_m5_m1_m1_Test ()
{
	Display::Color colorIndex = 1;

	Point p0(-5, -5), p1(-1, -1);
	mock->beginInit();

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::draw2_m5_m5_5_m1_Test ()
{
	Display::Color colorIndex = 1;

	Point p0(-5, -5), p1(5, -1);
	mock->beginInit();

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::draw3_m5_m5_Wp5_m1_Test ()
{
	Display::Color colorIndex = 1;

	Point p0(-5, -5), p1(WIDTH + 5, -1);
	mock->beginInit();

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}
//------------
void DisplayTestRectangle::draw4_m5_m5_m1_5_Test ()
{
	Display::Color colorIndex = 1;

	Point p0(-5, -5), p1(-1, 5);
	mock->beginInit();

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::draw5_m5_m5_5_5_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(-5,-5), p1(5,5);
	mock->beginInit();

	Point p0Expt;

	mock->setArea(p0Expt, p1);

	drawVerticalLine(Point(p1.x - 1,0), p1.y, expectedValue);
	drawHorizontalLine(Point(0, p1.y - 1), p1.x, expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::draw6_m5_m5_Wp5_5_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(-5, -5), p1(WIDTH + 5, 5);
	mock->beginInit();

	Point p0Expt(0,p1.y - 1);
	Point p1Expt(WIDTH, 5);

	mock->setArea(p0Expt, p1Expt);
	//BottomLine von drawRectangle(p0, p1,..)
	drawHorizontalLine(Point(0, p1.y - 1), p1Expt.x, expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}
//------------
void DisplayTestRectangle::draw7_m5_m5_m1_Hp5_Test ()
{
	Display::Color colorIndex = 1;

	Point p0(-5, -5), p1(-1, HEIGHT + 5);
	mock->beginInit();

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::draw8_m5_m5_5_Hp5_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(-5, -5), p1(5, HEIGHT + 5);
	mock->beginInit();

	Point p0Expt(p1.x - 1, 0);
	Point p1Expt(5, HEIGHT);

	mock->setArea(p0Expt, p1Expt);

	drawVerticalLine(Point(p1.x - 1, 0), p1Expt.y, expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::draw9_m5_m5_Wp5_Hp5_Test ()
{
	Display::Color colorIndex = 1;

	Point p0(-5, -5), p1(WIDTH + 5,HEIGHT + 5);
	mock->beginInit();

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}
//==================================================
// tests mit p0/p1-6
/*
 * 		     _______
 * 		p0	|		|
 * 		   4|	5	|	6
 * 			|_______|
 * 	       7	8		9
 */
//==================================================
// tests mit p0/p1-3
/*
 * 		     _______
 * 			|		|
 * 		    |		|
 * 			|_______|
 * 	    p0
 * 	       7	8		9
 */

// tests mit p0/p2-9
/*			 p0
 * 		     ___2___	3
 * 			|		|
 * 		    |	5	|	6
 * 			|_______|
 * 	        	8		9
 */

// tests mit p0/p5-9
/*
 * 		     _______
 * 			|p0		|
 * 		    |	5	|	6
 * 			|_______|
 * 	        	8		9
 */

// tests mit p0/p8-9
/*
 * 		     _______
 * 			|		|
 * 		    |		|
 * 			|_______|
 * 	         p0
 * 	         	8		9
 */

// tests mit p0/p3-9
/*					 p0
 * 		     _______	3
 * 			|		|
 * 		    |		|	6
 * 			|_______|
 * 	        			9
 */

// tests mit p0/p6-9
/*
 * 		     _______
 * 			|		|p0
 * 		    |		|	6
 * 			|_______|
 * 	        			9
 */

// tests mit p0/p9
/*
 * 		     _______
 * 			|		|
 * 		    |		|
 * 			|_______|
 * 	        		 p0
 * 	        			9
 */


void DisplayTestRectangle::drawRectangle_m5_5_5_15_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(-5,5), p1(5,15);
	mock->beginInit();

	Point p0Expt(0,5);

	mock->setArea(p0Expt, p1);

	drawVerticalLine(Point(p1.x - 1, p0.y), p1.y, expectedValue);
	drawHorizontalLine(p0Expt, p1.x, expectedValue);
	drawHorizontalLine(Point(p0Expt.x, p1.y - 1), p1.x, expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::drawRectangle_m1_m1_W_H_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(-1,-1), p1(WIDTH,HEIGHT);
	mock->beginInit();

	Point p0Expt;

	mock->setArea(p0Expt, p1);

	int xMax = p1.x - p0Expt.x;
	int yMax = p1.y - p0Expt.y;

	for (int x = 0; x < xMax - 1; ++x)
		mock->setPixel(Point(p0Expt.x + x, p1.y - 1), expectedValue);
	for (int y = 0; y < yMax; ++y)
		mock->setPixel(Point(p1.x - 1, p0Expt.y + y), expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

	//mock->print();

	compareExpectedResult();
}

void DisplayTestRectangle::drawRectangle_m1_m1_Wp1_Hp1_Test ()
{
	Display::Color colorIndex = 1;

	Point p0(-1,-1), p1(WIDTH + 1,HEIGHT + 1);
	mock->beginInit();

	mock->endInit();
	mock->beginTest();

	testDisplay->drawRectangle(p0, p1, colorIndex, true);

	mock->endTest();

	//mock->print();

	compareExpectedResult();
}
