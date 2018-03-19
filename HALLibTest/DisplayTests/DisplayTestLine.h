#ifndef DISPLAYTESTLINE_H_
#define DISPLAYTESTLINE_H_

#include "DisplayTestBase.h"

using namespace std;

class DisplayTestLine : public DisplayTestBase {

	CPPUNIT_TEST_SUITE (DisplayTestLine);

		CPPUNIT_TEST (drawHorizontal_0_3_6_3_Test);
		CPPUNIT_TEST (drawVertical_3_0_3_6_Test);
		CPPUNIT_TEST (drawLine_0_0_3_3_Test);
//		CPPUNIT_TEST (drawLine_m3_m3_3_3_Test);

	CPPUNIT_TEST_SUITE_END ();

	protected:
		void drawHorizontal_0_3_6_3_Test();
		void drawVertical_3_0_3_6_Test();
		void drawLine_0_0_3_3_Test();
		void drawLine_m3_m3_3_3_Test();
};

#endif /* DISPLAYTESTLINE_H_ */
