#ifndef __VIC_H__
#define __VIC_H__

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <HAL/MemoryMappedRegister.h>

#include <LPC21xx/Types.h>
#include <LPC21xx/Traits.h>

/*!
 * \file
 *
 * \author Gerd Hirsch
 * \date 31.10.2012
 * \remark Selector: CS<HAL::VIC, LPC21xx::Base>
 * Generator fuer LPC21xx::Base und
 * Implementierung des VIC fuer die LPC21xx Reihe.
 */

namespace LPC21xx {
template <class Register, class Hal>
struct VIC;
}
/*!
 * \brief Erzeugt die Implementierung für den Vectored Interrupt Controller
 * der Familie LPC21xx
 */
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::VIC, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef typename Create<ProzessorType, ConfigRepository>::type Hal;

	typedef CS<SS<HAL::VIC, HAL::Register>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type Register;

	typedef LPC21xx::VIC<Register, Hal> type;
};
} // namespace Generator

/*!
 * \namespace Alle Implementierungen und Abstraktionen die für
 * die gesamte Familie LPC21xx gültigkeit haben, sind im
 * namespace LPC21xx. Die Spezialisierungen für die einzelnen
 * Unterfamilien befinden sich in entsprechenden namespaces
 * z.B. namespace LPC214x oder namespace LPC213x
 */
namespace LPC21xx {
namespace VIC_Private{

template<unsigned int SlotNo, class Register>
struct SlotRegister;

template<class Hal>
struct DeviceNumbers;

} // end namespace VIC_Private
/*!
 * \class VIC
 *
 * \brief VIC Vectored Interrupt Controller Implementierung fuer
 * die Familie LPC21xx.
 * \remark Selector: CS<HAL::VIC, LPC21xx::Base>
 */
template <class Register, class Hal>
struct VIC {
	typedef typename Register::Traits Traits;
	typedef typename Traits::ValueType ValueType;

	/*!
	 * Table 63 lists the interrupt sources for each peripheral
	 * function. Each peripheral device has one interrupt line
	 * connected to the Vectored Interrupt Controller, but may have
	 * several internal interrupt flags. Individual interrupt flags may
	 * also represent more than one interrupt source.
	 */
	/*! DeviceBit::value Abbildungsfunktion DeviceNumber->DeviceBit */
	template<ValueType deviceNumber>
	struct DeviceBit{
		enum { deviceNo = deviceNumber, value = 0x1<<deviceNumber };
	};
	/*! DeviceNumber::value Abbildungsfunktion Device->VIC DeviceNumber
	 * Generiert die Spezialisierungen für die
	 * type function DeviceNumber<Device>::value */
	typedef VIC_Private::DeviceNumbers<Hal> deviceNumbers;

	//Todo Non-Vectored Interrupts unterstützen
	// In IntEnable das Device enablen, die Default ISR setzen
	// und dort den Interrupt abfragen

	//Todo Software Interrupts SWI unterstützen

	/*!
	 * The Vectored Interrupt Controller (VIC) takes 32 interrupt
	 * request inputs and programmably assigns them into 3 categories,
	 * FIQ, vectored IRQ, and non-vectored IRQ. The programmable
	 * assignment scheme means that priorities of interrupts from the
	 * various peripherals can be dynamically assigned and adjusted
	 */
	//-----------------------------------------------------------------
	/*! Policies für FIQ und IRQ=default Policystruct */
	struct FIQ{
		static void init(ValueType deviceBit){
			Register::IntSelect::setBit(deviceBit);
		}
	};
	struct IRQ{
		static void init(ValueType deviceBit){
			Register::IntSelect::clearBit(deviceBit);
		}
	};
	//-----------------------------------------------------------------
	/*!
	 * Vectored IRQs have the middle priority, but only 16 of the 32
	 * requests can be assigned to this category. Any of the 32
	 * requests can be assigned to any of the 16 vectored IRQ slots,
	 * among which slot 0 has the highest priority and
	 * slot 15 has the lowest.
	 */
	template<unsigned char SlotNo>
	struct SlotImpl{
		typedef VIC_Private::SlotRegister<SlotNo, Register> slot_register;

		typedef typename slot_register::VectAddr VectAddr_n;
		typedef typename slot_register::VectCntl VectCntl_n;

		static void release(){
			VectAddr_n::set(0);
			VectCntl_n::set(0);
		}
		static void endOfInterrupt(){
			Register::VectAddr::set(0);
		}
	};
	// Schnittstelle des VIC
	template<unsigned char SlotNo>
	struct Slot : SlotImpl<SlotNo>
	{
		typedef typename SlotImpl<SlotNo>::VectAddr_n VectAddr_n;
		typedef typename SlotImpl<SlotNo>::VectCntl_n VectCntl_n;

		template<class deviceType>
		struct DeviceImpl {
			enum { 	deviceNo = deviceNumbers::template DeviceNumber<deviceType>::value,
					deviceBit = DeviceBit<deviceNo>::value
			};
			template<class PIRQ_>
			static void capture(PIRQ_* pISR){
				VectAddr_n::set(reinterpret_cast<ValueType>(pISR));
				// Bit5 enable interrupt 4:0 Device Number
				VectCntl_n::setBit(Bit5|deviceNo);
			}
			static void enableInterrupt(){
				Register::IntEnable::setBit(deviceBit);
			}
			static void disableInterrupt(){
				Register::IntEnClr::setBit(deviceBit);
			}
		};//DeviceImpl

		template<class deviceType>
		struct Device : DeviceImpl<deviceType>, SlotImpl<SlotNo>{

			template<class categoryType = IRQ>
			struct Category : DeviceImpl<deviceType>, SlotImpl<SlotNo> {
				template<class PIRQ_>
				static void capture(PIRQ_* pISR){
					categoryType::init(DeviceImpl<deviceType>::deviceBit);
					DeviceImpl<deviceType>::capture(pISR);
				}
			};

			template<class PIRQ_>
			static void capture(PIRQ_* pISR){
				// IRQ default Policy
				IRQ::init(DeviceImpl<deviceType>::deviceBit);
				DeviceImpl<deviceType>::capture(pISR);
			}
		};
// Für die Syntax VIC::Slot<No>::Category<FIQ>::Device<RTC>::capture(function);
		template<class categoryType = IRQ>
		struct Category	: SlotImpl<SlotNo>{

			template<class deviceType>
			struct Device :	DeviceImpl<deviceType>, SlotImpl<SlotNo>{

				template<class PIRQ_>
				static void capture(PIRQ_* pISR){
					categoryType::init(DeviceImpl<deviceType>::deviceBit);
					DeviceImpl<deviceType>::capture(pISR);
				}
			};
		};
	};

	template<class DeviceType>
	static void enableInterrupt(){
		Register::IntEnable::setBit(
				DeviceBit<deviceNumbers::template DeviceNumber<DeviceType>::value>::value);
	}
	template<class DeviceType>
	static void disableInterrupt(){
		Register::IntEnClr::setBit(
				DeviceBit<deviceNumbers::template DeviceNumber<DeviceType>::value>::value);
	}
	template<class PIRQ>
	static void initIRQDefault(PIRQ* pISR){
		Register::DefVectAddr::set(reinterpret_cast<ValueType>(pISR));
	}

	static ValueType getEnabledInterrupts(){
		return Register::IntEnable::read();
	}
	static ValueType disableAllInterrupts(){
		ValueType interrupts = Register::IntEnable::read();
		Register::IntEnClr::set(AllBits);
		return interrupts;
	}
	static void enableInterrupts(ValueType interrupts){
		Register::IntEnable::set(interrupts);
	}
	// Clear the VectAddr. Need to be done at the end of all interrupts
	static void endOfInterrupt(){
		Register::VectAddr::set(0);
	}

	static ValueType getIRQStatus(){
		return Register::IRQStatus::read();
	}
	static ValueType getFIQStatus(){
		return Register::FIQStatus::read();
	}
	//=================================================================
	// Software interrupts
	//=================================================================
	template<class DeviceType>
	static void triggerSWInterrupt(){
		Register::SoftInt::setBit(
				DeviceBit<deviceNumbers::template DeviceNumber<DeviceType>::value>::value
		);
	}
	static bool isSoftInterrupt(){
		return Register::SoftInt::read();
	}
	template<class DeviceType>
	static bool isSoftInterrupt(){
		return Register::SoftInt::readBit(
				DeviceBit<deviceNumbers::template DeviceNumber<DeviceType>::value>::value
		);
	}
	template<class DeviceType>
	static void clearSWInterrupt(){
		Register::SoftIntClr::setBit(
				DeviceBit<deviceNumbers::template DeviceNumber<DeviceType>::value>::value
		);
	}
	static void clearAllSWInterrupts(){
		Register::SoftIntClr::set(AllBits);
	}
};

namespace VIC_Private{
//=====================================================================
// SlotRegister
//=====================================================================
template<unsigned int SlotNo, class Register>
struct SlotRegister;

template<class Register>
struct SlotRegister<0, Register>
{
	typedef typename Register::VectAddr0 VectAddr;
	typedef typename Register::VectCntl0 VectCntl;
};

template<class Register>
struct SlotRegister<1, Register>
{
	typedef typename Register::VectAddr1 VectAddr;
	typedef typename Register::VectCntl1 VectCntl;
};
template<class Register>
struct SlotRegister<2, Register>
{
	typedef typename Register::VectAddr2 VectAddr;
	typedef typename Register::VectCntl2 VectCntl;
};
template<class Register>
struct SlotRegister<3, Register>
{
	typedef typename Register::VectAddr3 VectAddr;
	typedef typename Register::VectCntl3 VectCntl;
};
template<class Register>
struct SlotRegister<4, Register>
{
	typedef typename Register::VectAddr4 VectAddr;
	typedef typename Register::VectCntl4 VectCntl;
};
template<class Register>
struct SlotRegister<5, Register>
{
	typedef typename Register::VectAddr5 VectAddr;
	typedef typename Register::VectCntl5 VectCntl;
};
template<class Register>
struct SlotRegister<6, Register>
{
	typedef typename Register::VectAddr6 VectAddr;
	typedef typename Register::VectCntl6 VectCntl;
};
template<class Register>
struct SlotRegister<7, Register>
{
	typedef typename Register::VectAddr7 VectAddr;
	typedef typename Register::VectCntl7 VectCntl;
};
template<class Register>
struct SlotRegister<8, Register>
{
	typedef typename Register::VectAddr8 VectAddr;
	typedef typename Register::VectCntl8 VectCntl;
};
template<class Register>
struct SlotRegister<9, Register>
{
	typedef typename Register::VectAddr9 VectAddr;
	typedef typename Register::VectCntl9 VectCntl;
};
template<class Register>
struct SlotRegister<10, Register>
{
	typedef typename Register::VectAddr10 VectAddr;
	typedef typename Register::VectCntl10 VectCntl;
};
template<class Register>
struct SlotRegister<11, Register>
{
	typedef typename Register::VectAddr11 VectAddr;
	typedef typename Register::VectCntl11 VectCntl;
};
template<class Register>
struct SlotRegister<12, Register>
{
	typedef typename Register::VectAddr12 VectAddr;
	typedef typename Register::VectCntl12 VectCntl;
};
template<class Register>
struct SlotRegister<13, Register>
{
	typedef typename Register::VectAddr13 VectAddr;
	typedef typename Register::VectCntl13 VectCntl;
};
template<class Register>
struct SlotRegister<14, Register>
{
	typedef typename Register::VectAddr14 VectAddr;
	typedef typename Register::VectCntl14 VectCntl;
};
template<class Register>
struct SlotRegister<15, Register>
{
	typedef typename Register::VectAddr15 VectAddr;
	typedef typename Register::VectCntl15 VectCntl;
};
//=====================================================================
/*!DeviceNumbers<Hal> generiert die Spezialisierungen für die
 * type function DeviceNumber<Device>::value
 */
template<class Hal>
struct DeviceNumbers{
//=====================================================================
	template<class Device, class Dummy=int>
	struct DeviceNumber;

	// noch nicht in Hal
	template<class Dummy>
	struct DeviceNumber<typename Hal::WDT, Dummy >{
		enum{value = 0 };
	};
	/*
	template<class Dummy>
	struct DeviceNumber<typename Hal::ARMCore0, Dummy >{
		enum{value = 2 };
	};
	template<class Dummy>
	struct DeviceNumber<typename Hal::ARMCore1, Dummy >{
		enum{value = 3 };
	};*/

	template<class Dummy>
	struct DeviceNumber<typename Hal::Timer0, Dummy >{
		enum{value = 4 };
	};
	template<class Dummy>
	struct DeviceNumber<typename Hal::Timer1, Dummy>{
		enum{value = 5 };
	};
	template<class Dummy>
	struct DeviceNumber<typename Hal::UART0, Dummy>{
		enum{value = 6 };
	};
	template<class Dummy>
	struct DeviceNumber<typename Hal::UART1, Dummy>{
		enum{value = 7 };
	};
	template<class Dummy>
	struct DeviceNumber<typename Hal::PWM, Dummy>{
		enum{value = 8 };
	};
	template<class Dummy>
	struct DeviceNumber<typename Hal::I2C0, Dummy>{
		enum{value = 9 };
	};
	template<class Dummy>
	struct DeviceNumber<typename Hal::SPI, Dummy>{
		enum{value = 10 };
	};
	template<class Dummy>
	struct DeviceNumber<typename Hal::SSP, Dummy>{
		enum{value = 11 };
	};
	/*
	template<class Dummy>
	struct DeviceNumber<typename Hal::PLL, Dummy>{
		enum{value =12 };
	};*/

	template<class Dummy>
	struct DeviceNumber<typename Hal::RTC, Dummy>{
		enum{value = 13 };
	};
	//EINT<0 - 3>: DeviceNumber: 14, 15, 16, 17
	template<unsigned int No, class Sensitivity, class Dummy>
	struct DeviceNumber<typename Hal::EINT::template EINT<No, Sensitivity>, Dummy>{
		enum{value = 14 + No };
	};

	template<class Dummy>
	struct DeviceNumber<typename Hal::ADC0, Dummy>{
		enum{value = 18 };
	};
	template<class Dummy>
	struct DeviceNumber<typename Hal::I2C1, Dummy>{
		enum{value = 19 };
	};
	/*
	template<class Dummy>
	struct DeviceNumber<typename Hal::BOD, Dummy>{
		enum{value = 20 };
	};*/
	template<class Dummy>
	struct DeviceNumber<typename Hal::ADC1, Dummy>{
		enum{value = 21 };
	};
	/*
	template<class Dummy>
	struct DeviceNumber<typename Hal::USB, Dummy>{
		enum{value = 22 };
	};*/
};
} // namespace VIC_Private

} // namespace LPC21xx

#endif /* __VIC_H__ */
