#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include <Generator/CreateComponent.h>
//#include <HAL/ComponentTypes.h>
#include <CommonComponents/CommonComponentTypes.h>

namespace InputDevice{
template<typename HAL_>
struct Joystick;
}

namespace Generator { namespace SD {
	template<class BoardType, class ConfigRepository>
	struct Component<SelectorDefault, CommonComponents::Joystick, BoardType, ConfigRepository>
	{
//		typedef typename ConfigRepository::Controller Controller;
//		typedef typename Create<Controller, HAL::Layer>::type Hal;
		typedef typename Create<BoardType, CommonComponents::JoystickHAL, ConfigRepository>::type Hal;
		typedef InputDevice::Joystick<Hal> type;
	};
}} // namespace Generator::SD

namespace InputDevice{

/*
  Die folgenden Definitionen sind in Vorbereitung für statisches Binding
  der Handler und werden noch nicht benutzt
*/
struct EmptyHandler{
  	static void handle(){}
};
template<	
			class LeftHandler_ 		= EmptyHandler, 
			class RightHandler_ 	= EmptyHandler,
			class UpHandler_ 		= EmptyHandler,
			class DownHandler_ 		= EmptyHandler,
			class OKHandler_ 		= EmptyHandler,
			class ESCHandler_ 		= EmptyHandler,
			class DefaultHandler_ 	= EmptyHandler
		>
struct JoystickRepository{
	typedef LeftHandler_ 	LeftHandler;
	typedef RightHandler_ 	RightHandler;
	typedef UpHandler_ 		UpHandler;
	typedef DownHandler_ 	DownHandler;
	typedef OKHandler_ 		OKHandler;
	typedef ESCHandler_ 	ESCHandler;
	typedef DefaultHandler_ DefaultHandler;   	
};

template<typename JoystickHAL>
class Joystick : JoystickHAL{
  public:
  	typedef JoystickHAL JoystickHal;
	typedef Joystick<JoystickHal> type;

	static type& getInstance(){
		static type instance;
		return instance;
	}	

	typedef void (*EventHandler)();

	void registerLeft(EventHandler leftHandler){this->leftHandler = leftHandler;}
	void registerRight(EventHandler rightHandler){this->rightHandler = rightHandler;}
	void registerUp(EventHandler upHandler){this->upHandler = upHandler;}
	void registerDown(EventHandler downHandler){this->downHandler = downHandler;}
	void registerOK(EventHandler okHandler){this->okHandler = okHandler;}
	void registerESC(EventHandler escHandler){this->escHandler = escHandler;}
	void registerDefault(EventHandler defaultHandler){this->defaultHandler = defaultHandler;}
  	
	void poll();

  private:
  	Joystick(){	this->init(); }

	
	EventHandler leftHandler;
	EventHandler rightHandler;
	EventHandler upHandler;
	EventHandler downHandler;
	EventHandler okHandler;
	EventHandler escHandler;
	EventHandler defaultHandler;
  
	void dispatchMessage(unsigned char key);
//	enum{  ESC = 0x01, UP = 0x02, OK = 0x04, RIGHT = 0x08, DOWN = 0x10, LEFT = 0x20 };
};

template<typename HAL_> inline 
void Joystick<HAL_>
::poll(){
	dispatchMessage(this->getMessage());
}



template<typename HAL_> inline 
void Joystick<HAL_>
::dispatchMessage(unsigned char keycode) {

	switch(keycode) {
	 	case JoystickHal::LEFT: 
			if(leftHandler != 0) 
				leftHandler(); 
				// LeftHandler::handle();
		break;
	 	case JoystickHal::RIGHT: 
			if(rightHandler != 0) 
				rightHandler(); 
		break;
	 	case JoystickHal::UP: 
			if(upHandler != 0) 
				upHandler(); 
		break;
	 	case JoystickHal::DOWN: 
			if(downHandler != 0) 
				downHandler(); 
		break;
	 	case JoystickHal::OK: 
			if(okHandler != 0) 
				okHandler(); 
		break;
	 	case JoystickHal::ESC: 
			if(escHandler != 0) 
				escHandler(); 
		break;
		default: 
			if(defaultHandler != 0) 
				defaultHandler(); 
	}
	keycode = 0;
}


} // end namespace CommonComponents
#endif //__JOYSTICK_H__

