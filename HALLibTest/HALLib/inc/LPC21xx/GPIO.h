#ifndef LPC21xxGPIO_H
#define LPC21xxGPIO_H

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <HAL/MemoryMappedRegister.h>

#include <LPC21xx/Traits.h>

//--------------------------------------------------------------
//forward declaration
namespace LPC21xx
{
/*
Todo: checking Policy die überprüft, ob set2Input/OutputMode
bzw. read/write/clear sinnvoll sind, was nur für GPIO konfigurierte
Pins zutrifft. Wird über den Pin konfiguriert und zugegriffen
ist das per interface gewährleistet
*/
	template<class GPIORegister>
	struct GPIO;
}
//--------------------------------------------------------------
namespace Generator {
	//==============================================================
	// GPIO Components
	//--------------------------------------------------------------
	template<class Origin, class ConfigRepository>
	struct Component<CS<NO<HAL::GPIO, 0>, LPC21xx::Base>, Origin, ConfigRepository>
	{
		typedef typename Origin::template getSelector<>::type ProzessorType;
		typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;

		typedef typename Create<CS<SS<NO<HAL::GPIO, 0>, HAL::Register>, ProzessorType>, ConfigRepository>
				::type Register;

		typedef LPC21xx::GPIO<Register> type;
	};
	//--------------------------------------------------------------
	template<class Origin, class ConfigRepository>
	struct Component<CS<NO<HAL::GPIO, 1>, LPC21xx::Base>, Origin, ConfigRepository>
	{
		typedef typename Origin::template getSelector<>::type ProzessorType;
		typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;

		typedef typename Create<CS<SS<NO<HAL::GPIO, 1>, HAL::Register>, ProzessorType>, ConfigRepository>
				::type Register;

		typedef LPC21xx::GPIO<Register> type;
	};
	//--------------------------------------------------------------
} // namespace Generator
namespace LPC21xx{
//==============================================================
template<class GPIORegister>
struct GPIO{
	typedef typename GPIORegister::Traits Traits;
	typedef typename Traits::ValueType ValueType;
	typedef typename GPIORegister::IOPIN ioPin;
	typedef typename GPIORegister::IOSET ioSet;
	typedef typename GPIORegister::IODIR ioDir;
	typedef typename GPIORegister::IOCLR ioClr;

	//0 Controlled pin is input.
	static void setToInputMode(ValueType bits) {
		ioDir::clearBit(bits);
	}	
	//1 Controlled pin is output
	static void setToOutputMode(ValueType bits) {
		ioDir::setBit(bits);
	}
	static bool isOutputMode(ValueType pins){
		return ioDir::read() & pins;
	}
	// the value of the port
	static ValueType read(){
		return ioPin::read();
	}
	//Todo overload verwenden read(ValueType pins)
	static ValueType readPin(ValueType bits){
		return ioPin::read() & bits;
	}
	// sets the corresponding Bits in ioPin, Writing zeroes has no effect 
	static void write(ValueType bits) {
		ioSet::setBit(bits);
	}
	// zeros the corresponding Bits in ioPin, Writing zeroes has no effect 
	static void clear(ValueType bits) {
		ioClr::setBit(bits);
	}
};
//==============================================================
}
#endif //LPC21xxGPIO_H
