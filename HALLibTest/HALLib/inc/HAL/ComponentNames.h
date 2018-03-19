/*
 * ComponentNames.h
 *
 *  Created on: 03.01.2012
 *      Author: Gerd
 *
 *      Enables printing of the names of types via template specialization
 */
#ifndef __HAL_COMPONENTNAMES_H_
#define __HAL_COMPONENTNAMES_H_

#include <Generator/BaseType.h>
#include <HAL/ComponentTypes.h>

namespace Generator{
template<> struct name<HAL::Register>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::Register";
	}
};
template<> struct name<HAL::Traits>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::Traits";
	}
};
template<> struct name<HAL::PinConnectBlock>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::PinConnectBlock";
	}
};
template<> struct name<HAL::GPIO>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::GPIO";
	}
};
template<> struct name<HAL::WDT>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::WDT";
	}
};
template<> struct name<HAL::PWM>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::PWM";
	}
};
template<> struct name<HAL::ADC>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::ADC";
	}
};
template<> struct name<HAL::VIC>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::VIC";
	}
};
template<> struct name<HAL::Timer>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::Timer";
	}
};
//template<> struct name<HAL::AD1>{
//	template<class OStream>
//	static void print(OStream& os){
//		os << "HAL::AD1";
//	}
//};
template<> struct name<HAL::DAC>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::DAC";
	}
};
template<> struct name<HAL::UART>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::UART";
	}
};
template<> struct name<HAL::SPI>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::SPI";
	}
};
template<> struct name<HAL::SSP>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::SSP";
	}
};
template<> struct name<HAL::RTC>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::RTC";
	}
};
template<> struct name<HAL::SystemControl>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::SystemControl";
	}
};
template<> struct name<HAL::ExternalInterrupt>{
	template<class OStream>
	static void print(OStream& os){
		os << "HAL::ExternalInterrupt";
	}
};


}//namespace Generator

#endif /* __HAL_COMPONENTNAMES_H_ */
