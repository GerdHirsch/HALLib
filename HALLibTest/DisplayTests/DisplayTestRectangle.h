#ifndef DISPLAYTESTRECTANGLE_H_
#define DISPLAYTESTRECTANGLE_H_

#include "DisplayTestBase.h"

class DisplayTestRectangle : public DisplayTestBase {
	CPPUNIT_TEST_SUITE (DisplayTestRectangle);

		CPPUNIT_TEST (fillRectangle_0_0_6_6_Test);
		CPPUNIT_TEST (fillRectangle_0_0_WIDTH_HEIGHT_Test);

		CPPUNIT_TEST (fillRectangle_m5_m5_5_5_Test);

		CPPUNIT_TEST (drawRectangle_0_0_6_6_Test);
		CPPUNIT_TEST (drawRectangle_10_10_16_16_Test);

		CPPUNIT_TEST (draw1_m5_m5_m1_m1_Test);
		CPPUNIT_TEST (draw2_m5_m5_5_m1_Test);
		CPPUNIT_TEST (draw3_m5_m5_Wp5_m1_Test);
		CPPUNIT_TEST (draw4_m5_m5_m1_5_Test);
		CPPUNIT_TEST (draw5_m5_m5_5_5_Test);
		CPPUNIT_TEST (draw6_m5_m5_Wp5_5_Test);
		CPPUNIT_TEST (draw7_m5_m5_m1_Hp5_Test);
		CPPUNIT_TEST (draw8_m5_m5_5_Hp5_Test);
		CPPUNIT_TEST (draw9_m5_m5_Wp5_Hp5_Test);

		CPPUNIT_TEST (drawRectangle_m5_5_5_15_Test);
		CPPUNIT_TEST (drawRectangle_m1_m1_W_H_Test);
//		CPPUNIT_TEST (drawRectangle_m1_m1_Wp1_Hp1_Test);

	CPPUNIT_TEST_SUITE_END ();

		protected:
			void fillRectangle_0_0_6_6_Test();
			void fillRectangle_0_0_WIDTH_HEIGHT_Test();

			void fillRectangle_m5_m5_5_5_Test();

			void drawRectangle_0_0_6_6_Test();
			void drawRectangle_10_10_16_16_Test();

			void draw1_m5_m5_m1_m1_Test();
			void draw2_m5_m5_5_m1_Test();
			void draw3_m5_m5_Wp5_m1_Test();
			void draw4_m5_m5_m1_5_Test();
			void draw5_m5_m5_5_5_Test();
			void draw6_m5_m5_Wp5_5_Test();
			void draw7_m5_m5_m1_Hp5_Test();
			void draw8_m5_m5_5_Hp5_Test();
			void draw9_m5_m5_Wp5_Hp5_Test();

			void drawRectangle_m5_5_5_15_Test();
			void drawRectangle_m1_m1_W_H_Test();
			void drawRectangle_m1_m1_Wp1_Hp1_Test();

};

#endif /* DISPLAYTESTRECTANGLE_H_ */
