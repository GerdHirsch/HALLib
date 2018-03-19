#ifndef __EVALBOARD_ZEA7_2_POTI_HAL_H__
#define __EVALBOARD_ZEA7_2_POTI_HAL_H__

#include <Generator/CreateComponent.h>
#include <CommonComponents/CommonComponentTypes.h>


namespace ZEA7_2_Components{
	template<typename HAL_>
	struct PotiHAL;
}

namespace Generator
{
	template<class BoardType, class ConfigRepository>
	struct Component<Boards::ZEA7_2, BoardType, CommonComponents::PotiHAL, ConfigRepository>
	{
		typedef typename ConfigRepository::Controller Controller;
		typedef typename Create<Controller, HAL::Layer, ConfigRepository>::type Hal;
		typedef ZEA7_2_Components::PotiHAL<Hal> type;
	};
}


namespace ZEA7_2_Components{

template<typename HAL_>
struct PotiHAL
{
	typedef HAL_ Hal;
	typedef typename Hal::AD0 ADC1;
	typedef typename Hal::PinConnectBlock PCB;	

	enum { MAXVALUE = 0x3FF };

	static void init() {
  		PCB::selectP0_28_AD0_1();
		ADC1::selectAD();
		ADC1::selectCLKDivisor();
		ADC1::operational();
	}	
	
	static unsigned long read() {
		unsigned long val; 
	
		ADC1::startConversion();
	 	while (!ADC1::read(val))
			;
		ADC1::stopConversion();	

		return val;			  
	}

};

}       

#endif // __EVALBOARD_ZEA7_2_POTI_HAL_H__
