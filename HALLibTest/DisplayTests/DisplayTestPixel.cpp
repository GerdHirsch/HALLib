#include "DisplayTestPixel.h"

//CPPUNIT_TEST_SUITE_REGISTRATION (DisplayTestPixel);

void DisplayTestPixel::setPixel_0_0_Test ()
{
	Display::Color colorIndex = 1;
	ExpectedType expectedValue = testDisplay->getColor(colorIndex);

	Point p;
	mock->beginInit();

	mock->setArea(p,Point(p.x+1, p.y+1));
	mock->setPixel(p, expectedValue);

	mock->endInit();
	mock->beginTest();

	testDisplay->setPixel(p, colorIndex, true);

	mock->endTest();

	compareExpectedResult();
}

void DisplayTestPixel::setPixel_m1_m1_Test ()
{
	Display::Color colorIndex = 1;
	Point p(-1,-1);

	mock->beginInit();

	// wird nicht benötigt wegen defaults
	mock->setArea(Point(),Point());

	mock->endInit();
	mock->beginTest();

	testDisplay->setPixel(p, colorIndex, true);

	mock->endTest();

	compareExpectedResult();
}

void DisplayTestPixel::setPixel_m1_1_Test ()
{
	Display::Color colorIndex = 1;

	Point p(-1,1);

	mock->beginInit();

	// wird nicht benötigt wegen defaults
	mock->setArea(Point(),Point());

	mock->endInit();
	mock->beginTest();

	testDisplay->setPixel(p, colorIndex, true);

	mock->endTest();

	compareExpectedResult();
}

void DisplayTestPixel::setPixel_m1_H_Test ()
{
	Display::Color colorIndex = 1;

	Point p(-1,HEIGHT);

	mock->beginInit();

	// wird nicht benötigt wegen defaults
	mock->setArea(Point(),Point());

	mock->endInit();
	mock->beginTest();

	testDisplay->setPixel(p, colorIndex, true);

	mock->endTest();

	compareExpectedResult();
}

void DisplayTestPixel::setPixel_1_H_Test ()
{
	Display::Color colorIndex = 1;

	Point p(1,HEIGHT);

	mock->beginInit();

	// wird nicht benötigt wegen defaults
	mock->setArea(Point(),Point());

	mock->endInit();
	mock->beginTest();

	testDisplay->setPixel(p, colorIndex, true);

	mock->endTest();

	compareExpectedResult();
}

void DisplayTestPixel::setPixel_W_H_Test ()
{
	Display::Color colorIndex = 1;

	Point p(WIDTH,HEIGHT);

	mock->beginInit();

	// wird nicht benötigt wegen defaults
	mock->setArea(Point(),Point());

	mock->endInit();
	mock->beginTest();

	testDisplay->setPixel(p, colorIndex, true);

	mock->endTest();

	compareExpectedResult();
}

void DisplayTestPixel::setPixel_W_1_Test ()
{
	Display::Color colorIndex = 1;

	Point p(WIDTH,1);

	mock->beginInit();

	// wird nicht benötigt wegen defaults
	mock->setArea(Point(),Point());

	mock->endInit();
	mock->beginTest();

	testDisplay->setPixel(p, colorIndex, true);

	mock->endTest();

	compareExpectedResult();
}

void DisplayTestPixel::setPixel_W_m1_Test ()
{
	Display::Color colorIndex = 1;

	Point p(WIDTH,-1);

	mock->beginInit();

	// wird nicht benötigt wegen defaults
	mock->setArea(Point(),Point());

	mock->endInit();
	mock->beginTest();

	testDisplay->setPixel(p, colorIndex, true);

	mock->endTest();

	compareExpectedResult();
}

void DisplayTestPixel::setPixel_1_m1_Test ()
{
	Display::Color colorIndex = 1;

	Point p(1,-1);

	mock->beginInit();

	// wird nicht benötigt wegen defaults
	mock->setArea(Point(),Point());

	mock->endInit();
	mock->beginTest();

	testDisplay->setPixel(p, colorIndex, true);

	mock->endTest();

	compareExpectedResult();
}

//
//template<typename DeviceContext>
//void DemoTransformierteKoordinaten(DeviceContext& dc){
//	dc.setRange(-100, 100, -100, 100); // double xMin, xMax, yMin, yMax
//	dc.setRotation(30); // 30° double degree % 360
//	dc.setRotation(30, 180); // 30° 180' double degree % 360
//	dc.setRotation(30, 180, 90); // 30° 180' 90'' double degree % 360
//
//	/degree = 30;
//	dc.fillEllipse(p0,p1,color, Degree(30, 30, 45)); // Degree(grad, minute, sekunde)
//	dc.fillEllipse(p0,p1,color, degree, rotationsPoint);
//}
