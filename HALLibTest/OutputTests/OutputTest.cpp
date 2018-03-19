#include "OutputTest.h"
#include <LPC214x/Doc/CreateDoc.h>
#include <LPC213x/Doc/CreateDoc.h>

//CPPUNIT_TEST_SUITE_REGISTRATION (OutputTest);

using namespace Generator;

void OutputTest::CreateLPC21xxContextDoc(){
	LPC214x::createContextDoc();
	//LPC213x::createContextDoc();
}
void OutputTest::CreateLPC21xxComponentsDoc(){
//	LPC214x::createComponentsDoc();
//	LPC213x::createComponentsDoc();
}
