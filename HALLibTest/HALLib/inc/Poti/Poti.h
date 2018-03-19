#ifndef POTI_H
#define POTI_H

#include <Generator/CreateComponent.h>
//#include <HAL/Typedefs.h>
#include <CommonComponents/CommonComponentTypes.h>


namespace InputDevice{
template<typename HAL_>
struct Poti;
}

namespace Generator { namespace SD {
	template<class BoardType, class ConfigRepository>
	struct Component<SelectorDefault, CommonComponents::Poti, BoardType, ConfigRepository>
	{
		typedef typename Create<BoardType, CommonComponents::PotiHAL, ConfigRepository>::type Hal;
		typedef InputDevice::Poti<Hal> type;
	};
}} // namespace Generator::SD
namespace InputDevice{
// diese Klasse konvertiert den Rohwert von PotiHAL::read() 
// in den übergebenen Wertebereich
template<typename PotiHAL>
struct Poti : PotiHAL {
	typedef PotiHAL PotiHal;
	typedef Poti<PotiHal> type;

	static type getInstance(){
	 	static type instance;
		return instance;
	}
	static unsigned long getValue(unsigned long maxVal)
	{
	 	return (PotiHAL::read() * maxVal) / PotiHAL::MAXVALUE; 
	}
protected:
	Poti(){ this->init();}
	//typedef typename PotiHal::Hal Hal;
//	typedef typename Hal::AD1 ADC1;
//	typedef typename Hal::PinConnectBlock PCB;	


	// Todo: in EvalBoard spezifische Klasse verschieben
//	static void init() {
//  		PCB::selectP0_28_AD0_1();
//		ADC1::selectAD();
//		ADC1::selectCLKDivisor();
//		ADC1::operational();
//	}	
	

//	static unsigned long read() {
//		unsigned long val; 
//	
//		ADC1::startConversion();
//	 	while (!ADC1::read(val))
//			;
//		ADC1::stopConversion();	
//
//		return val;			  
//	}
};
}
#endif // POTI_H
