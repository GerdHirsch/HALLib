#ifndef DISPLAY_TEST_H
#define DISPLAY_TEST_H

#include "DisplayTestBase.h"

using namespace std;

class DisplayTestPixel : public DisplayTestBase
{
	CPPUNIT_TEST_SUITE (DisplayTestPixel);

		CPPUNIT_TEST (setPixel_0_0_Test);

		CPPUNIT_TEST (setPixel_m1_m1_Test);
		CPPUNIT_TEST (setPixel_m1_1_Test);
		CPPUNIT_TEST (setPixel_m1_H_Test);
		CPPUNIT_TEST (setPixel_1_H_Test);
		CPPUNIT_TEST (setPixel_W_H_Test);
		CPPUNIT_TEST (setPixel_W_1_Test);
		CPPUNIT_TEST (setPixel_W_m1_Test);
		CPPUNIT_TEST (setPixel_1_m1_Test);

	CPPUNIT_TEST_SUITE_END ();

	protected:
		void setPixel_0_0_Test ();
		void setPixel_m1_m1_Test ();
		void setPixel_m1_1_Test ();
		void setPixel_m1_H_Test ();
		void setPixel_1_H_Test ();
		void setPixel_W_H_Test ();
		void setPixel_W_1_Test ();
		void setPixel_W_m1_Test ();
		void setPixel_1_m1_Test ();
};

#endif // DISPLAY_TEST_H
