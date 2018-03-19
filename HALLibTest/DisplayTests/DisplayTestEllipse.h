#ifndef DISPLAYTESTELLIPSE_H_
#define DISPLAYTESTELLIPSE_H_

#include "DisplayTestBase.h"

using namespace std;

class DisplayTestEllipse : public DisplayTestBase {
	CPPUNIT_TEST_SUITE (DisplayTestEllipse);

	CPPUNIT_TEST (drawEllipse_0_0_6_6_Test);

	CPPUNIT_TEST (fillEllipse_0_0_6_6_Test);
	CPPUNIT_TEST (fillEllipse_0_Hm6_6_H_Test);
	CPPUNIT_TEST (fillEllipse_0_Hm5_6_Hp1_Test);
	CPPUNIT_TEST (fillEllipse_10_10_16_16_Test);

	CPPUNIT_TEST (fillEllipse_m5_m5_5_5_Test);
	CPPUNIT_TEST (fillEllipse_m5_5_5_15_Test);
	CPPUNIT_TEST (fillEllipse_m1_Hm6_5_H_Test);

	CPPUNIT_TEST_SUITE_END ();

	protected:
		void drawEllipse_0_0_6_6_Test();

		void fillEllipse_0_0_6_6_Test();
		void fillEllipse_0_Hm6_6_H_Test();
		void fillEllipse_0_Hm5_6_Hp1_Test();
		void fillEllipse_10_10_16_16_Test();

		void fillEllipse_m5_m5_5_5_Test();
		void fillEllipse_m5_5_5_15_Test();
		void fillEllipse_m1_Hm6_5_H_Test();

};

#endif /* DISPLAYTESTELLIPSE_H_ */
