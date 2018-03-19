#ifndef __LPC21XX_RTC_H__
#define __LPC21XX_RTC_H__

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <HAL/MemoryMappedRegister.h>

#include <LPC21xx/Types.h>
#include <LPC21xx/Traits.h>

namespace LPC21xx {
template <class Register, class SystemControl>
struct RTC;
}

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::RTC, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::SystemControl, ProzessorType> SCContext;
	typedef typename Create<SCContext, ConfigRepository>::type SC;

	typedef CS<SS<HAL::RTC, HAL::Register>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type Register;

	typedef LPC21xx::RTC<Register, SC> type;
};
} // namespace Generator

namespace LPC21xx {
/*!
 * Any of the various Resets can bring the microcontroller out
 * of power-down mode, as can the external interrupts EINT3:0,
 * plus the RTC interrupt if the RTC is operating from its own
 * oscillator on the RTCX1-2 pins.
 * When one of these interrupts is enabled for wakeup and
 * its selected event occurs, an oscillator wakeup cycle is started.
 * The actual interrupt (if any) occurs after the wakeup timer
 * expires, and is handled by the Vectored Interrupt Controller.
 * If the RTC is used to wake up from Power-down mode,
 * the PLL will be disabled. If needed in the application,
 * the PLL must be enabled and connected again before it can be used as
 * a clock source after waking up from Power-down mode
 *
 * To put the device in Power-down mode and allow activity on one or
 * more of these buses or lines to power it back up, software should
 * reprogram the pin function to External Interrupt, select the
 * appropriate mode and polarity for the Interrupt, and then select
 * Power-down mode. Upon wakeup software should restore the pin
 * multiplexing to the peripheral function.
 */
template <class Register,  class SystemControl>
struct RTC {
	enum IRMask{NONE = 0x0, AllInterrupts = 0xFF,
				SEC	= 0x01, MIN = 0x02, HOUR = 0x04,
				DOM = 0x08, DOW = 0x10, DOY = 0x20,
				MON = 0x40, YEAR = 0x80 };
private:
	typedef typename Register::Traits Traits;
	typedef typename Traits::ValueType ValueType;
	typedef SystemControl SC;

	struct ClockPolicy
	{
		enum{ irBit = Bit0 };
		typedef typename Register::ClockRegister TimeRegister;

		/*! enables exactly the Interrupts specified by mask.
		 * Previous enabled Interrupts will be disabled */
		static void enableInterruptOn(IRMask mask){
			Register::ciir::set(mask);
		}
		/*! enables the Interrupts specified by mask
		 * in addition to previous enabled Interrupts */
		static void addInterruptOn(IRMask mask){
			Register::ciir::setBit(mask);
		}
		static void disableAllInterrupts(){
			Register::ciir::set(NONE);
		}
		/*! disables the Interrupts specified by mask
		 * other Interrupts remain */
		static void removeInterruptOn(IRMask mask){
			Register::ciir::clearBit(mask);
		}
		/*! provides the current mask of interrupts
		 * as specified via enable and addInterruptOn(mask) */
		static ValueType getEnabledInterrupts(){
			return Register::ciir::read();
		}
		//Todo: Schnittstelle mit Tuple mit drei werten zur Verfügung stellen.
		// oder vier Werte mit dem Registerinhalt und den extrahierten einzelwerten
		// Nachteil: es muss immer extrahiert werden
		/*!
		 * Seconds Bit 5:0 [0-59]
		 * Minutes Bit 13:8 [0-59]
		 * Hours Bit 20:16 [0-23]
		 * Day of Week Bit 26:24 [0-6]
		 */
		static ValueType getConsolidatedTime(){
			return Register::cTime0::read();
		}
		/*!
		 * Day of Month Bit 4:0 [1-28|29|30|31]
		 * Month Bit 7:5 [1-12]
		 * Year Bit 27:16 [0-4095]
		 */
		static ValueType getConsolidatedDate(){
			return Register::cTime1::read();
		}
		/*!
		 * Day of Year Bit 11:0 [1-265|366 for leap years]
		 */
		static ValueType getConsolidatedDayOfYear(){
			return Register::cTime2::read();
		}
	};

	struct AlarmPolicy
	{
		enum{ irBit = Bit1 };
		typedef typename Register::AlarmRegister TimeRegister;

		/*! enables exactly the Interrupts specified by mask.
		 * Previous enabled Interrupts will be disabled
		 *  If all the unmasked alarm registers match their
		 *  corresponding time counters then an interrupt is generated.
		 * */
		static void enableInterruptOn(IRMask mask){
			Register::amr::set(AllInterrupts);
			Register::amr::clearBit(mask);
		}
		/*! enables the Interrupts specified by mask
		 * in addition to previous enabled Interrupts */
		static void addInterruptOn(IRMask mask){
			Register::amr::clearBit(mask);
		}
		static void disableAllInterrupts(){
			Register::amr::set(AllInterrupts);
		}
		/*! disables the Interrupts specified by mask
		 * other Interrupts remain */
		static void removeInterruptOn(IRMask mask){
			Register::amr::setBit(mask);
		}
		/*! provides the current mask of interrupts
		 * as specified via enable and addInterruptOn(mask) */
		static ValueType getEnabledInterrupts(){
			return ~Register::amr::read() & AllInterrupts;
		}
	};

	/*! Policy: Clock oder Alarm */
	template<class Policy>
	struct CommonFeatures : Policy
	{
		typedef CommonFeatures<Policy> this_type;
		typedef typename Policy::TimeRegister TimeRegister;
		enum { irBit = Policy::irBit };

		static bool isInterruptSource(){
			return Register::ilr::readBit(irBit);
		}
		/*!
		 * clears Interrupt for Clock or Alarm depending on
		 * RTC::Clock::clearInterruptFlag() or
		 * RTC::Alarm::clearInterruptFlag()
		 */
		static void clearInterruptFlag(){
			//  Writing a one to the appropriate bit clears the
			// corresponding interrupt. Writing a zero has no effect.
			Register::ilr::set(irBit);
		}

		static void setTime(ValueType h, ValueType min, ValueType sec){
			TimeRegister::hour::set(h);
			TimeRegister::min::set(min);
			TimeRegister::sec::set(sec);
		}

		static ValueType getSec(){
			return TimeRegister::sec::read();
		}
		static ValueType getMin(){
			return TimeRegister::min::read();
		}
		static ValueType getHour(){
			return TimeRegister::hour::read();
		}

		static void setDate(ValueType year, ValueType month, ValueType day){
			TimeRegister::year::set(year);
			TimeRegister::month::set(month);
			TimeRegister::dom::set(day);
		}
		/*!
		 * leap years in the range of 1901 to 2099 are correct,
		 * 2100 is not a leap year but will be handle as leap year.
		 * The RTC does a simple bit comparison to see
		 * if the two lowest order bits of the year
		 * counter are zero. If true, then the RTC
		 * considers that year a leap year.
		 */
		static ValueType getDayOfMonth(){
			return TimeRegister::dom::read();
		}
		static ValueType getDayOfYear(){
			return TimeRegister::doy::read();
		}
		static ValueType getMonth(){
			return TimeRegister::month::read();
		}
		static ValueType getYear(){
			return TimeRegister::year::read();
		}
	};
public:
	typedef CommonFeatures<ClockPolicy> Clock;
	typedef CommonFeatures<AlarmPolicy> Alarm;
	//=====================================================================
	// Schnittstelle von RTC für Clock und Alarm
	//=====================================================================
	/*! Interrupt source Bit 1:0 Bit0:Clock Bit1:Alarm */
	static ValueType getInterruptSource(){
		return Register::ilr::read();
	}
	/*! clears Clock and Alarm Interrupt */
	static void clearAllInterruptFlags(){
		Register::ilr::set(Bit1|Bit0);
	}
	//=================================================================
	// Switch between PCLK and 32KHz Oszillator
	//=================================================================
	/*! RTC wird mit internem 32KHz Oszillator betrieben */
	static void connectWith32KHzClock(){
		Register::ccr::setBit(Bit4);
	}
	/*! RTC wird mit PCLK dem Clock der Peripheriegeräte verbunden
	 * 	korrekte Zeit ist von der Einstellung des Prescalers abhängig
	 * 	\see initPrescalerFromPeripheralClock()  */
	static void connectWithPeripheralClock(){
		Register::ccr::clearBit(Bit4);
	}
	/*! \return true wenn RTC mit 32KHz Oszillator betrieben wird */
	static bool isConnectedWith32KHzClock(){
		return Register::ccr::readBit(Bit4);
	}
	//=================================================================
	// Start, Stop RTC, Reset CTRC
	//=================================================================
	/*! startet die RTC mit den gesetzten Werten in den Countern */
	static void startRTC(){
		Register::ccr::setBit(Bit0);
	}

	/*! stoppt die RTC, die Werte in den Countern bleiben erhalten */
	static void stopRTC(){
		Register::ccr::clearBit(Bit0);
	}
	/*! \return true wenn die Uhr läuft \see start*/
	static bool isClockEnabled(){
		return Register::ccr::readBit(Bit0);
	}
	/*! resets ClockTickCounterRegister CTRC to zero an starts it immediately */
	static void resetClockTickCounter(){
	/* Bit1 ccr
	* When one, the elements in the Clock Tick Counter (CTCR) are
	* reset. The elements remain reset until CCR[1] is changed to zero.
	*/
		Register::ccr::setBit(Bit1);
		Register::ccr::clearBit(Bit1);
	}
	//=================================================================
	// Prescaler für Anpassungen an PCLK Frequenz
	//=================================================================
	/*! calculates Integer and Fraction Part of the Prescaler
	 * and initializes the corresponding Registers */
	static void initPrescalerFromPeripheralClock(){
		ValueType preInt = static_cast<ValueType>((SC::PCLK() / 32768));
		Register::PreInt::set(preInt -1);
		Register::PreFrac::set( SC::PCLK() - (preInt * 32768));
	}
	static void setPrescalerIntValue(ValueType value){
		// 13 Bit Register
		Register::PreInt::set(value & 0x1FFF);
	}

	static ValueType getPrescalerIntValue(){
		return Register::PreInt::read();
	}

	static void setPrescalerFractionValue(ValueType value){
		// 15 Bit Register
		Register::PreFrac::set(value & 0x7FFF);
	}

	static ValueType getPrescalerFractionValue(){
		return Register::PreFrac::read();
	}
	//=================================================================
	// sonstiges testMode ?
	//=================================================================
	static void testMode(){
		Register::ccr::setBit(Bit2);
	}
};
} // namespace LPC21xx

#endif /* __LPC21XX_RTC_H__ */
