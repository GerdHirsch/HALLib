#ifndef __LPC21XX_POWERCONTROL_H__
#define __LPC21XX_POWERCONTROL_H__

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <HAL/MemoryMappedRegister.h>

#include <LPC21xx/Types.h>
#include <LPC21xx/Traits.h>

namespace LPC21xx {
template <class Register, class Hal>
struct PC;
}

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::PowerControl, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProcessorType;
	typedef typename Create<ProcessorType>::type Hal;
	typedef CS<SS<HAL::PowerControl, HAL::Register>, ProcessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type Register;

	typedef LPC21xx::PC<Register, Hal> type;
};
} // namespace Generator

namespace LPC21xx {

namespace PC_Private{

template<class Device, class Hal_>
struct DeviceBit;
} // end namespace SC_Private

template <class Register, class Hal>
struct PC {
	typedef typename Register::Traits Traits;
	typedef typename Traits::ProcessorType ProcessorType;
	typedef typename Traits::RegisterType RegisterType;
	typedef typename Traits::ValueType ValueType;
//===================================================================
// PowerControl
//===================================================================
private:
	// DeviceBit::value Abbildungsfunktion Typ->SystemControl DeviceBit
	template<class Device, class Hal_ = Hal>
	struct DeviceBit : SC_Private::DeviceBit<Device, Hal_>{};
//	template<class Device, class dummy = int>
//	struct DeviceBit;

//	template<class dummy>
//	struct DeviceBit<typename Hal::Timer0, dummy>{
//		enum{value = Bit1};
//	};
public:
		template<class DeviceType>
		static bool isConnectedPCLK(){
			return Register::PCONP::readBit(DeviceBit<DeviceType>::value);
		}
		/*! Note: Clear the PDN bit in the AD0CR before clearing this
		 * bit, and set this bit before setting PDN. */
		template<class DeviceType>
		static void disconnectPCLK(){
			Register::PCONP::clearBit(DeviceBit<DeviceType>::value);
		}

		/*! Note: Clear the PDN bit in the AD0CR before clearing this
		 * bit, and set this bit before setting PDN. */
		template<class DeviceType>
		static void connectPCLK(){
			Register::PCONP::setBit(DeviceBit<DeviceType>::value);
		}
};

namespace PC_Private{
template<class Hal>
struct DeviceBit<typename Hal::Timer0, Hal>{
	enum{value = Bit1};
};
template<class Hal>
struct DeviceBit<typename Hal::Timer1, Hal>{
	enum{value = Bit2};
};
template<class Hal>
struct DeviceBit<typename Hal::UART0, Hal>{
	enum{value = Bit3};
};
template<class Hal>
struct DeviceBit<typename Hal::UART1, Hal>{
	enum{value = Bit4};
};
template<class Hal>
struct DeviceBit<typename Hal::PWM, Hal>{
	enum{value = Bit5};
};
//Reserved Bit6
template<class Hal>
struct DeviceBit<typename Hal::I2C0, Hal>{
	enum{value = Bit7};
};
template<class Hal>
struct DeviceBit<typename Hal::SPI, Hal>{
	enum{value = Bit8};
};
template<class Hal>
struct DeviceBit<typename Hal::RTC, Hal>{
	enum{value = Bit9};
};
template<class Hal>
struct DeviceBit<typename Hal::SSP, Hal>{
	enum{value = Bit10};
};
//Reserved Bit11
template<class Hal>
struct DeviceBit<typename Hal::ADC0, Hal>{
	enum{value = Bit12};
};
//Reserved Bit13 bis Bit18
template<class Hal>
struct DeviceBit<typename Hal::I2C1, Hal>{
	enum{value = Bit19};
};
} // end namespace PC_Private

} // namespace LPC21xx


#endif /* __LPC21XX_POWERCONTROL_H__ */
