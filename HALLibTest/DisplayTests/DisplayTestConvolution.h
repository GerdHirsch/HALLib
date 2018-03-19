#ifndef DISPLAYTESTCONVOLUTION_H_
#define DISPLAYTESTCONVOLUTION_H_

#include "DisplayTestBase.h"

using namespace std;

class DisplayTestConvolution : public DisplayTestBase {

	CPPUNIT_TEST_SUITE (DisplayTestConvolution);

	CPPUNIT_TEST (Test);

	CPPUNIT_TEST_SUITE_END ();

	protected:
		void Test();

};

#endif /* DISPLAYTESTCONVOLUTION_H_ */
