
#ifndef __OUTPUT_TEST_H_
#define __OUTPUT_TEST_H_

#include "../HALLibTestApp.h"

class OutputTest : public CPPUNIT_NS::TestFixture {

	CPPUNIT_TEST_SUITE(OutputTest);

	CPPUNIT_TEST(CreateLPC21xxContextDoc);

	CPPUNIT_TEST_SUITE_END();

	protected:
		void CreateLPC21xxContextDoc();
		void CreateLPC21xxComponentsDoc();
};

#endif /* __OUTPUT_TEST_H_ */
