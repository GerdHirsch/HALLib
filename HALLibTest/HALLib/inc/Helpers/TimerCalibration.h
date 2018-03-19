#ifndef __TIMERCALIBRATION_H__
#define __TIMERCALIBRATION_H__

#ifdef EMBEDDED
#define IRQ_HF __irq
#else
#define IRQ_HF
#endif

template<class Hal_>
class TimerCalibration{
public:
	static void start(){
		this_type var;
		triggerLED(Bit29);
		while(!var.finished);

		var.backToDefault();
		Timer::PCLK() = var.average;
	}
	template<class Label>
	static void start(Label& avLabel){
		this_type var;

		while(!var.finished);

		var.backToDefault();
		avLabel.showNumber(var.average);
		Timer::PCLK() = var.average;
	}

protected:
	typedef Hal_ Hal;
	typedef TimerCalibration<Hal> this_type;
	typedef typename Hal::Traits Traits;
	typedef typename Traits::ValueType ValueType;

	typedef typename Hal::GPIO0 Port0;
	typedef typename Hal::PinConnectBlock PCB;
	typedef typename PCB::P0_29::GPIO LampenPin;


	typedef typename Hal::Timer0 Timer;
	typedef typename Timer::template Match<0> Match;
	typedef typename Hal::RTC RTC;
	typedef typename Hal::VIC VIC;

	typedef typename
			VIC::template
			Slot<0>::template
			Device<RTC>
	RTCSlot;

	TimerCalibration()
	: finished(false), startMeasure(false), numCalcs(0), lastTC(0), average(0)
	{
		instance() = this;
		LampenPin::select();
		Port0::setToOutputMode(Bit29);
		initTimer();
		initRTC();

	}

//	~TimerCalibration(){
//		backToDefault();
//	}

	volatile bool finished;
	volatile bool startMeasure;
	volatile unsigned long numCalcs;
	volatile unsigned long lastTC;
	volatile unsigned long average;
	enum { PRECOUNTS = 2, MEASURES = 3 };

	/*!
	 * StateMachine: zuerst werden ein paar Sekunden (PRECOUNTS) gewartet
	 * bevor mit der Messung begonnen wird.
	 */
	void measure(){
		ValueType  currentTC = Timer::getTimerCounter();
		if(startMeasure){
			ValueType  diffCountsPerSecond = currentTC - lastTC;
			average = average * numCalcs + diffCountsPerSecond;
			++numCalcs;
			average = (static_cast<double>(average) / numCalcs) + 0.5;
		}else if(numCalcs > PRECOUNTS){
			startMeasure = true;
			numCalcs = 0;
		}else{
		triggerLED(Bit29);
			++numCalcs;
		}
		lastTC = currentTC;
		if(numCalcs > MEASURES){
			finished = true;
			RTCSlot::disableInterrupt();
		}
	}

	static void rtcISR() IRQ_HF {
		triggerLED(Bit29);

		instance()->measure();

		RTC::clearAllInterruptFlags();
		VIC::endOfInterrupt();
	}

	// TODO: wie gewährleisten, dass ursprüngliche einstellungen
	// wieder hergestellt werden??
	void backToDefault(){
		Timer::counterDisable();
		Match::setMatch(0);
		Match::disableResetOnMatch();

//		Timer::template setMatchFor<typename Timer::MR0>(NoneBits);
//		Timer::template disableResetOn<typename Timer::MR0>();

		RTCSlot::release();
//		RTC::disable();
	}

	void initTimer(){
		Timer::counterReset();
		Timer::setPrescaleRegister(0);
		Match::setMatch(AllBits);
		Match::resetOnMatch();

		Timer::startTimer();
	}

	void initRTC(){
		RTC::Clock::enableInterruptOn(RTC::SEC);
		RTCSlot::capture(rtcISR);
		RTCSlot::enableInterrupt();
		RTC::connectWith32KHzClock();

		RTC::startRTC();
	}

	static this_type*& instance(){
		static this_type* pThis;
		return pThis;
	}

	static void triggerLED(unsigned int led){
		bool an = !Port0::readPin(led);
		if(an){
			Port0::write(led);
		}else{
			Port0::clear(led);
		}
	}
};

#endif /* __TIMERCALIBRATION_H__ */
