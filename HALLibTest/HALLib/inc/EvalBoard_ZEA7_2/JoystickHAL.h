#ifndef __EVALBOARD_ZEA7_2_JOYSTICK_HAL_H__
#define __EVALBOARD_ZEA7_2_JOYSTICK_HAL_H__


#include <Generator/CreateComponent.h>
#include <CommonComponents/CommonComponentTypes.h>


namespace ZEA7_2_Components{
	template<typename HAL_>
	struct JoystickHAL;
}

namespace Generator	{ namespace SD {
	template<class BoardType, class ConfigRepository>
	struct Component<Boards::ZEA7_2, CommonComponents::JoystickHAL, BoardType, ConfigRepository>
	{
		typedef typename ConfigRepository::Controller Controller;
		typedef typename Create<Controller, HAL::Layer, ConfigRepository>::type Hal;
		typedef ZEA7_2_Components::JoystickHAL<Hal> type;
	};
}} // namespace Generator::SD


namespace ZEA7_2_Components{

template<typename HAL_>
struct JoystickHAL
{
	typedef HAL_ Hal;
  	typedef typename Hal::GPIOPort0 port0;
	typedef typename Hal::GPIOPort1 port1;

  	static void init(void);
  	static unsigned char readKey(void);
	static unsigned char getMessage();

	enum{  ESC = 0x01, UP = 0x02, OK = 0x04, RIGHT = 0x08, DOWN = 0x10, LEFT = 0x20 };


};

template<typename HAL_> inline 
void JoystickHAL<HAL_>
::init() {
	// Set P0.10-P0.15 to input mode
	// Bit 10 bis 15 == joystick
	port0::setToInputMode(Bit10|Bit11|Bit12|Bit13|Bit14|Bit15);
}

template<typename HAL_> inline 
unsigned char JoystickHAL<HAL_>
::readKey() {
	static int KeyCount=0;
	static char previousKey=0x3F; 

	// Bit 10 bis 15 == joystick 
	// nur die unteren 6 Bits
	char k=(unsigned char)(port0::read() >>10) & 0x3F;

	if(k==previousKey) {
		KeyCount++;	
		if(KeyCount>30000) {
			KeyCount=0;
			return k;	
			}
		}
	else {
		KeyCount=0;
		}
	previousKey=k;
	return 0x3F;
}


template<typename HAL_> inline 
unsigned char JoystickHAL<HAL_>
::getMessage() {
	//keycode=(~readKey())&0x3F;
	return (~readKey())&0x3F;
	//return keycode;
}


}

#endif // __EVALBOARD_ZEA7_2_JOYSTICK_HAL_H__

