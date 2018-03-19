#ifndef __LPC21xx_TIMER_H__
#define __LPC21xx_TIMER_H__

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <HAL/MemoryMappedRegister.h>

#include <LPC21xx/Types.h>
#include <LPC21xx/Traits.h>

#include <HAL/HALMacros.h>

namespace LPC21xx {
template<class Register>
struct Timer;
}

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::Timer, 0>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<SS<NO<HAL::Timer, 0>, HAL::Register>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type Register;

	typedef LPC21xx::Timer<Register> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::Timer, 1>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<SS<NO<HAL::Timer, 1>, HAL::Register>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type Register;

	typedef LPC21xx::Timer<Register> type;
};
} // namespace Generator


namespace LPC21xx {
template<class Traits>
struct TimerBase{
	typedef typename Traits::RegisterType RegisterType;

	static RegisterType& PCLK(){
		static RegisterType pclk = 18431100;
		return pclk;
	}
};

template <class Register>
struct Timer : TimerBase<typename Register::Traits> {

	typedef typename Register::Traits Traits;
	typedef typename Traits::RegisterType RegisterType;

	typedef TimerBase<Traits> base_type;

	template<class DefaultType>
	struct EmptyDefault{
		static void enable(){ DefaultType::disable();}
		static void disable(){}
	};

	struct DefaultRepository{

	};


private:
	//Match Registers
	template<unsigned int MatchNo, class Dummy = int >
	struct MatchRegister;
	template<class Dummy>
	struct MatchRegister<0, Dummy>
	{
		typedef typename Register::MR0 type;
	};
	template<class Dummy>
	struct MatchRegister<1, Dummy>
	{
		typedef typename Register::MR1 type;
	};
	template<class Dummy>
	struct MatchRegister<2, Dummy>
	{
		typedef typename Register::MR2 type;
	};
	template<class Dummy>
	struct MatchRegister<3, Dummy>
	{
		typedef typename Register::MR3 type;
	};
	// Capture Registers
	template<unsigned int CaptureNo, class Dummy = int >
	struct CaptureRegister;
	template<class Dummy>
	struct CaptureRegister<0, Dummy>
	{
		typedef typename Register::CR0 type;
	};
	template<class Dummy>
	struct CaptureRegister<1, Dummy>
	{
		typedef typename Register::CR1 type;
	};
	template<class Dummy>
	struct CaptureRegister<2, Dummy>
	{
		typedef typename Register::CR2 type;
	};
	template<class Dummy>
	struct CaptureRegister<3, Dummy>
	{
		typedef typename Register::CR3 type;
	};
public:
	/*
	 * External Match Output 0/1- When a match register 0/1 (MR3:0)
	 * equals the timer counter (TC) this output can either
	 * toggle, go low, go high, or do nothing.
	 * The External Match Register (EMR) controls the functionality of
	 * this output. Match Output functionality can be selected on a
	 * number of pins in parallel.
	 * It is also possible for example, to have 2 pins selected at the
	 * same time so that they provide MAT1.3 function in parallel.
	 */
	template<int MatchNo>
	struct Match {
		typedef typename MatchRegister<MatchNo>::type MatchRegister;

		enum { 	IRFlag 	= Bit0 << MatchNo,
				MRnI	= Bit0 << (MatchNo * 3),
				MRnR 	= Bit1 << (MatchNo * 3),
				MRnS	= Bit2 << (MatchNo * 3),
		};
		/*
		 * Here is the list of all MATCH signals, together with pins
		 * on where they can be selected:
		 * • MAT0.0 (2 pins) : P0.3 and P0.22
		 * • MAT0.1 (2 pins) : P0.5 and P0.27
		 * • MAT0.2 (2 pin) : P0.16 and P0.28
		 * • MAT0.3 (1 pin) : P0.29
		 * • MAT1.0 (1 pin) : P0.12
		 * • MAT1.1 (1 pin) : P0.13
		 * • MAT1.2 (2 pins) : P0.17 and P0.19
		 * • MAT1.3 (2 pins) : P0.18 and P0.20
		 *
		 * PinConnectBlock::Pin0_29::Match3_Timer0::select()
		 */
		struct ExternalMatch{
			enum {
				//EM0 bis EM3, external Match enabler
				EMn 	= Bit0 << MatchNo,
				//Masks MatchAction
				ACTIONMASK   = (Bit5|Bit4) << (MatchNo * 2)
			};
			static void enable(){
				Register::EMR::setBit(EMn);
			}
			static void disable(){
				Register::EMR::clearBit(EMn);
			}

			enum MatchAction{
				DONOTHING	= 0,
				GOLOW		= Bit4 << (MatchNo * 2),
				GOHIGH		= Bit5 << (MatchNo * 2),
				TOGGLE	 	= (Bit5|Bit4) << (MatchNo * 2)//11
			};
			struct DoNothing{
				static void select(){
					Register::EMR::clearBit(ACTIONMASK);
				}
			};
			struct Toggle{
				static void select(){
					Register::EMR::setBit(TOGGLE);
				}
			};
			struct GoLow{
				static void select(){
					Register::EMR::clearBit(ACTIONMASK);
					Register::EMR::setBit(GOLOW);
				}
			};
			struct GoHigh{
				static void enable(){
					Register::EMR::clearBit(ACTIONMASK);
					Register::EMR::setBit(GOHIGH);
				}
			};
			static void action(MatchAction action=DONOTHING){
				Register::EMR::clearBit(ACTIONMASK);
				Register::EMR::setBit(action);
			}
		};//ExternalMatch

		struct ResetOnMatch{
			static void enable(){
				Register::MCR::setBit(MRnR);
			}
			static void disable(){
				Register::MCR::clearBit(MRnR);
			}
		};
		static void resetOnMatch(){
			Register::MCR::setBit(MRnR);
		}
		//Todo: rename: clearResetOnMatch
		static void disableResetOnMatch(){
			Register::MCR::clearBit(MRnR);
		}

		struct StopOnMatch{
			static void enable(){
				Register::MCR::setBit(MRnS);
			}
			static void disable(){
				Register::MCR::clearBit(MRnS);
			}
		};
		//Todo wie kann das rückgängig gemacht werden
		// eventuell in resetOnMatch oder freeRun
		static void stopOnMatch(){
			Register::MCR::setBit(MRnS);
		}

		// runtime Operations
		static bool isInterruptSource(){
			return Register::IR::readBit(IRFlag);
		}
		static void clearInterruptFlag(){
			Register::IR::setBit(IRFlag);
		}
		//delayTime in units of Time see setSecondDivideUnits(units)
		static void setDelay(RegisterType delayTime){
			if(delayTime <= 0)
				delayTime = 1;
			MatchRegister::set(2 * delayTime - 1);
		}
		static RegisterType getMatch(){
			return MatchRegister::read();
		}
		static void setMatch(RegisterType value){
			MatchRegister::set(value);
		}
		struct Interrupt{
			static void enable(){
				Register::MCR::setBit(MRnI);
			}
			static void disable(){
				Register::MCR::clearBit(MRnI);
			}
		};
		static void enableInterrupt(){
			Register::MCR::setBit(MRnI);
		}
		static void disableInterrupt(){
			Register::MCR::clearBit(MRnI);
		}
	};
	//=================================================================
	/*!
	 * A transition on a capture pin can be configured to load one of
	 * the Capture Registers with the value in the Timer Counter and
	 * optionally generate an interrupt. Capture functionality can be
	 * selected from a number of pins.
	 * NOTE: When more than one pin is selected for a Capture input on a
	 * single TIMER0/1 channel, the pin with the lowest Port number is used.
	 */
	template<int CaptureNo>
	struct Capture{
		typedef typename CaptureRegister<CaptureNo>::type CaptureRegister;
		enum {
			IRFlag 	= Bit0 << (CaptureNo + 4),
			CAPnRE 	= Bit0 << (CaptureNo * 3),
			CAPnFE 	= Bit1 << (CaptureNo * 3),
			CAPnI 	= Bit2 << (CaptureNo * 3)
		};
		/*!
		 * If Counter mode is selected for this Capture input
		 * RisingEdge, FallingEdge and Interrupt will be disabled
		 * and must not be used.
		 * However, capture and/or interrupt can be selected for
		 * the other 3 Capture inputs in the same timer.
		 */
		enum Modes{
			TimerMode		= 0,
			RisingEdge		= Bit0,
			FallingEdge		= Bit1,
			BothEdges		= Bit1|Bit0,
		};
		enum{
			CountingInputMask = Bit3|Bit2, //00 bis 11 CAPn.0 bis CAPn.3
			CountingInputSelect = CaptureNo << 2,
		};
		struct TimerMode{
			static void select(){
				Register::CTCR::clearBit(Bit1|Bit0);
			}
		};
		struct CounterMode{
			static void select(){
				Register::CCR::clearBit(CAPnRE|CAPnFE|CAPnI);
				Register::CTCR::clearBit(Bit1|Bit0);
				Register::CTCR::setBit(FallingEdge);
				Register::CTCR::clearBit(CountingInputMask);
				Register::CTCR::setBit(CountingInputSelect);
			}
		};


		/*
		 * Setting both the rising and falling edge at the
		 * same time is a valid configuration, resulting in
		 * a capture event for both edges.
		 */
		struct RisingEdge{
			static void select(){
				Register::CCR::setBit(CAPnRE);
			}
			static void deselect(){
				Register::CCR::clearBit(CAPnRE);
			}
		};
		struct FallingEdge{
			static void select(){
				Register::CCR::setBit(CAPnFE);
			}
			static void deselect(){
				Register::CCR::clearBit(CAPnFE);
			}
		};
		static void enableInterrupt(){
				Register::CCR::setBit(CAPnI);
		}
		static bool isInterruptSource(){
			return Register::IR::readBit(IRFlag);
		}
		static void disableInterrupt(){
				Register::CCR::clearBit(CAPnI);
		}

		static void clearInterruptFlag(){
			Register::IR::set(IRFlag);
		}
		static RegisterType getValue(){
			return CaptureRegister::read();
		}
	};//Capture

	typedef Match<0> MR0;
	typedef Match<1> MR1;
	typedef Match<2> MR2;
	typedef Match<3> MR3;

	typedef Capture<0> CR0;
	typedef Capture<1> CR1;
	typedef Capture<2> CR2;
	typedef Capture<3> CR3;

//	enum { pclk = /*44234650*/ 18431100 /* 14745600 + 3689350 */ };

	/*
	 *  clears Reset (clear TCR[1]) and enables (set TCR[0]) the timer
	 */
	static void startTimer(){
		Register::TCR::clearBit(Bit1);
		Register::TCR::setBit(Bit0);
	}

	static void counterDisable(){
		Register::TCR::clearBit(Bit0);
	}

	static void counterReset(){
		Register::TCR::setBit(Bit1);
	}

	static void setPrescaleRegister(RegisterType prescaleResetValue = 1000){
		Register::PR::set(prescaleResetValue);
	}

	// erzeugt eine sekundenunterteilung in units für delayTime 1000=ms
	// wenn die PCLK für die aktuelle Frequenz kalibriert ist.
	// see Helper/TimerCalibration
	// delayTime wird in units angegeben
	static void setSecondDivideUnits(RegisterType units = 1000){
		if(units == 0) units = 1;
		Register::PR::set(
				static_cast<RegisterType>(
						(base_type::PCLK()/(2.0 * units)) + 0.5) - 1);
	}

	static RegisterType getPrescaleRegister(){
		return Register::PR::read();
	}

	static void setPrescaleCounter(RegisterType startValue = 0){
		Register::PC::set(startValue);
	}

	static RegisterType getPrescaleCounter(){
		return Register::PC::read();
	}

	static void setTimerCounter(RegisterType value){
		return Register::TC::set(value);
	}

	static RegisterType getTimerCounter(){
		return Register::TC::read();
	}

	static void clearAllInterruptFlags(){
		Register::IR::set(0xFF);
	}

	static RegisterType getIR(){
		return Register::IR::read();
	}
};
} // namespace LPC21xx

#endif /* __LPC21xx_TIMER_H__ */
