/*
 * DisplayTestConvolution.cpp
 *
 *  Created on: 03.10.2011
 *      Author: pipo
 */

#include "DisplayTestConvolution.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (DisplayTestConvolution);

void DisplayTestConvolution::Test ()
{
	Display::Color colorIndex = 8;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p0(10,10), p1(50,40);
	mock->beginInit();
	mock->setArea(p0, p1);

	int xMax = p1.x - p0.x;
	int yMax = p1.y - p0.y;

//	for (int x = 1; x < xMax - 1; ++x){
//		mock->setPixel(Point(p0.x+x, p0.y), expectedValue);
//		mock->setPixel(Point(p0.x+x, p1.y - 1), expectedValue);
//	}
//	for (int y = 1; y < yMax - 1; ++y)
//		for (int x = 0; x < xMax; ++x)
//		{
//			mock->setPixel(Point(p0.x + x, p0.y + y), expectedValue);
//		}


	mock->endInit();
	mock->beginTest();

//	testDisplay->fillEllipse(p0, p1, colorIndex, false);
//	testDisplay->fillRectangle(Point(), Point(WIDTH, HEIGHT), 0, true);
	testDisplay->drawLine(Point(0,0), Point(1,10), colorIndex, false);
//	testDisplay->convolute();
	testDisplay->flush();
//	testDisplay->flush(Point(),Point(50,50));

	mock->endTest();

//	mock->print();

	compareExpectedResult();
}
