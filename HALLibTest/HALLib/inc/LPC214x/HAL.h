#ifndef __LPC214x_HAL_H_
#define __LPC214x_HAL_H_

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>

#include <LPC21xx/HAL.h>

#include <LPC214x/Types.h>
#include <LPC214x/PinConnectBlock.h>

namespace LPC214x{

template<class ProzessorType, class ConfigRep>
struct HAL2141;

template<class ProzessorType, class ConfigRep>
struct HAL2142;

template<class ProzessorType, class ConfigRep>
struct HAL2144;

}

namespace Generator {

//=========================================================
template<class Origin, class ConfigRepository>
struct Component<LPC214x::LPC2141, Origin, ConfigRepository>
{
	typedef Origin ProzessorType;
    typedef LPC214x::HAL2141<ProzessorType, ConfigRepository> type;
};

//=========================================================
template<class Origin, class ConfigRepository>
struct Component<LPC214x::LPC2142, Origin, ConfigRepository>
{
	typedef Origin ProzessorType;
    typedef LPC214x::HAL2142<ProzessorType, ConfigRepository> type;
};

//=========================================================
template<class Origin, class ConfigRepository>
struct Component<LPC214x::LPC2144, Origin, ConfigRepository>
{
	typedef Origin ProzessorType;
    typedef LPC214x::HAL2144<ProzessorType, ConfigRepository> type;
};

} // namespace Generator

namespace LPC214x{

template<class ProzessorType, class ConfigRep>
struct HAL2141 : LPC21xx::HAL21x1<ProzessorType, ConfigRep> {

};

template<class ProzessorType, class ConfigRep>
struct HAL2142 : LPC21xx::HAL21x2<HAL2141<ProzessorType, ConfigRep> > {

};

template<class ProzessorType, class ConfigRep>
struct HAL2144 : LPC21xx::HAL21x4<HAL2142<ProzessorType, ConfigRep> >{

};

}

#endif //__LPC214x_HAL_H_
