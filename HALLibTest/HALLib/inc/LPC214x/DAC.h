#ifndef DAC_H
#define DAC_H

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <LPC21xx/ComponentTypes.h>

/* D/A Converter */
//#define DA_CR            (0xE006C000)
namespace LPC214x
{
	template<class HAL_Traits, typename DACRegister>
	struct DAC;
}

namespace Generator { namespace SD {
template<class BoardType, class ConfigRepository>
struct Component<LPC214x::LPC2141, HAL::DAC, BoardType, ConfigRepository>
{
	// Todo Register via Generator erzeugen zum Testen
	typedef typename Create<BoardType, HAL::Traits>::type Traits;
	typedef typename Create<BoardType, LPC21xx::DACRegister>::type DACRegister;

	typedef LPC214x::DAC<Traits, DACRegister> type;
};
//--------------------------------------------------------------

}} // namespace Generator::SD

namespace LPC214x{
	template<class HAL_Traits, class DACRegister>
	struct DAC{

	    typedef typename HAL_Traits::BoardType BoardType;
		typedef typename HAL_Traits::RegisterType *Register;

		typedef typename DACRegister::DA_CR da_cr;

		static void convert(unsigned long value) {
//			*reinterpret_cast<Register>(da_cr) = value;
			da_cr::set(value);
		}

	/*
	Mode1
	The settling time of the DAC is 1 µs max, and the maximum
	current is 700 µA.
	Mode2
	The settling time of the DAC is 2.5 µs and the maximum
	current is 350 µA.
	*/
		static void setOutputMode1() {
//			*reinterpret_cast<Register>(da_cr) |= Bit16;
			da_cr::setBit(Bit16);
		}
		static void setOutputMode2() {
//			*reinterpret_cast<Register>(da_cr) &= ~Bit16;
			da_cr::clearBit(Bit16);
		}

	};
}//end namespace
#endif // DAC_H
