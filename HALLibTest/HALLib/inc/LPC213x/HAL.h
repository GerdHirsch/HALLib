#ifndef __LPC213x_HAL_H_
#define __LPC213x_HAL_H_

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>

#include <LPC21xx/HAL.h>

#include <LPC213x/Types.h>
#include <LPC213x/PinConnectBlock.h>
#include <LPC213x/ADC.h>
//#include <LPC213x/PWM.h>
//#include <LPC213x/ADC1.h>

namespace LPC213x{

template<class ProzessorType, class ConfigRep>
struct HAL2131;

template<class ProzessorType, class ConfigRep>
struct HAL2132;

template<class ProzessorType, class ConfigRep>
struct HAL2134;

}

namespace Generator {

//=========================================================
template<class Origin, class ConfigRepository>
struct Component<LPC213x::LPC2131, Origin, ConfigRepository>
{
	typedef Origin ProzessorType;
    typedef LPC213x::HAL2131<ProzessorType, ConfigRepository> type;
//    typedef LPC21xx::HAL21x1<ProzessorType, ConfigRepository> type;
};

//=========================================================
template<class Origin, class ConfigRepository>
struct Component<LPC213x::LPC2132, Origin, ConfigRepository>
{
	typedef Origin ProzessorType;
    typedef LPC213x::HAL2132<ProzessorType, ConfigRepository> type;
//    typedef LPC21xx::HAL21x2<LPC21xx::HAL21x1<ProzessorType, ConfigRepository> >
//    type;
};

//=========================================================
template<class Origin, class ConfigRepository>
struct Component<LPC213x::LPC2134, Origin, ConfigRepository>
{
	typedef Origin ProzessorType;
    typedef LPC213x::HAL2134<ProzessorType, ConfigRepository> type;
};

} // namespace Generator

namespace LPC213x{
//Todo: die leeren Implementierungen wieder entfernen,
//im Generator die Hal Typen
//typedef LPC21xx::HAL21x2<LPC21xx::HAL21x1> type erzeugen.
template<class ProzessorType, class ConfigRep>
struct HAL2131 : LPC21xx::HAL21x1<ProzessorType, ConfigRep> {

};

template<class ProzessorType, class ConfigRep>
struct HAL2132 : LPC21xx::HAL21x2<HAL2131<ProzessorType, ConfigRep> > {

};

template<class ProzessorType, class ConfigRep>
struct HAL2134 : LPC21xx::HAL21x4<HAL2132<ProzessorType, ConfigRep> >{

};

}

#endif //__LPC213x_HAL_H_
