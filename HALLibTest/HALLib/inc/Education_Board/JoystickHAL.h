#ifndef __EDU_BOARD_JOYSTICK_HAL_H__
#define __EDU_BOARD_JOYSTICK_HAL_H__

#include <Generator/CreateComponent.h>
#include <CommonComponents/CommonComponentTypes.h>

#ifdef EMBEDDED
#define IRQ_JOYSTICK __irq
#else
#define IRQ_JOYSTICK
#endif

namespace EA_LPC2138_EduBoard_Components{
	template<typename HAL_>
	struct JoystickHAL;
}

namespace Generator
template<class Origin, class ConfigRepository>
struct Component<DD<CommonComponents::Joystick, CS<Boards::EA_LPC2138_EduBoard, LPC21xx::Base> >, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<ProzessorType>::type Hal;
	typedef EA_LPC2138_EduBoard_Components::JoystickHAL<Hal> type;
};
} // namespace Generator


namespace EA_LPC2138_EduBoard_Components{
template<typename HAL_>
struct JoystickHAL{
	typedef HAL_ Hal;

	enum { MASK = Bit12|Bit11|Bit10|Bit9|Bit8 };

	void initEINT0(){
		PCB::selectP0_20_EINT3();
		EINT::setEdgeSensitive<EINT::EINT3>();

		typedef VIC::Slot1::Device<VIC::EINT3> Slot;
		Slot::init(eint3ISR);
		VIC::enableInterrupt<VIC::EINT3>();
	}
	void initJoystick(){
		Port0::setToInputMode(MASK);
	}
	void eint3ISR() IRQ_JOYSTICK  {
		port = Port0::readPin(MASK);

		portLabel.showNumber(port >> 8, 2);

		if((port & Bit8) == 0)triggerLED(Bit0);
		else if((port & Bit9) == 0)triggerLED(Bit2);
		else if((port & Bit10) == 0)triggerLED(Bit3);
		else if((port & Bit11) == 0)triggerLED(Bit22);
		else if((port & Bit12) == 0)triggerLED(Bit26);

		EINT::clearInterruptFlag<EINT::EINT3>();
		VIC::endOfInterrupt();
	}
};
} // namespace EA_LPC2138_EduBoard_Components

#undef IRQ_JOYSTICK
#endif // __EDU_BOARD_JOYSTICK_HAL_H__

