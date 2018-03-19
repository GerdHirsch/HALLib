#ifndef __COMMON_COMPONENT_TYPES_H__
#define __COMMON_COMPONENT_TYPES_H__

#include <Generator/BaseType.h>

namespace CommonComponents {

	struct Display : Generator::SelectorBase<>{};
//	struct Display;
//	struct DisplayHAL;
	struct ShadowDisplay;

	struct Poti;
	struct PotiHAL;

	struct Joystick;
	struct JoystickHAL;
} // end namespace CommonComponents


#endif //__COMMON_COMPONENT_TYPES_H__
