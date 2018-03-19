#ifndef VICTEST_H_
#define VICTEST_H_

#include <LPC213x/VIC.h>
#include "RegisterTestBase.h"

class VICTest : public RegisterTestBase{
public:
	typedef Generator::Create<Mock::LPC2134>::type Hal2134;
	typedef Hal2134::Traits Traits;
	typedef Traits::RegisterType RegisterType;
	typedef Traits::ValueType ExpectedType;

	typedef Hal2134::VIC VIC;



	CPPUNIT_TEST_SUITE (VICTest);
	CPPUNIT_TEST (initIRQDefault);	//4
	CPPUNIT_TEST (CaptureEnableReleaseTimer0);	//4
	CPPUNIT_TEST (CaptureEnableReleaseTimer1);	//5
	CPPUNIT_TEST (CaptureEnableReleaseUART0);	//6
	CPPUNIT_TEST (CaptureEnableReleaseUART1);	//7
	CPPUNIT_TEST (CaptureEnableReleasePWM);		//8
	CPPUNIT_TEST (CaptureEnableReleaseI2C);		//9
	CPPUNIT_TEST (CaptureEnableReleaseSPI);		//10
	CPPUNIT_TEST (CaptureEnableReleaseSSP);		//11
//	CPPUNIT_TEST (CaptureEnableReleasePLL);	//12
	CPPUNIT_TEST (CaptureEnableReleaseRTC);		//13
	CPPUNIT_TEST (CaptureEnableReleaseEINT0);	//14
	CPPUNIT_TEST (CaptureEnableReleaseEINT1);	//15
	CPPUNIT_TEST (CaptureEnableReleaseEINT2);	//16
	CPPUNIT_TEST (CaptureEnableReleaseEINT3);	//17
	CPPUNIT_TEST (CaptureEnableReleaseADC0);	//18
	CPPUNIT_TEST (CaptureEnableReleaseI2C1);	//19
//	CPPUNIT_TEST (CaptureEnableReleaseBOD);	//20
	CPPUNIT_TEST (CaptureEnableReleaseADC1);	//21
	CPPUNIT_TEST_SUITE_END ();

protected:
	void initIRQDefault();
	void CaptureEnableReleaseTimer0(); 	//4
	void CaptureEnableReleaseTimer1(); 	//5
	void CaptureEnableReleaseUART0(); 	//6
	void CaptureEnableReleaseUART1(); 	//7
	void CaptureEnableReleasePWM(); 	//8
	void CaptureEnableReleaseI2C(); 	//9
	void CaptureEnableReleaseSPI(); 	//10
	void CaptureEnableReleaseSSP(); 	//11
//	void CaptureEnableReleasePLL(); //12
	void CaptureEnableReleaseRTC(); 	//13
	void CaptureEnableReleaseEINT0(); 	//14
	void CaptureEnableReleaseEINT1(); 	//15
	void CaptureEnableReleaseEINT2(); 	//16
	void CaptureEnableReleaseEINT3(); 	//17
	void CaptureEnableReleaseADC0(); 	//18
	void CaptureEnableReleaseI2C1(); 	//19
//	void CaptureEnableReleaseBOD(); //20
	void CaptureEnableReleaseADC1(); 	//21

	/*!
	 * \param DeviceNo die Nummer des Devices lt.
	 * Tab 63 7.5 Interrupt Sources UM10139.pdf
	 * Die DeviceNo%16 wird als slotNo verwendet, so
	 * werden möglichst alle slots getestet
	 * \param Device der Name des Device aus der Hal
	 * @param deviceBit, das Bit das für das Device gesetzt (FIQ)
	 * oder gelöscht (IRQ) werden muss.
	 */
	template<unsigned int DeviceNo, class Device>
	void CaptureAndEnableDisableDevice(
			ExpectedType deviceBit);
};

#endif /* VICTEST_H_ */
