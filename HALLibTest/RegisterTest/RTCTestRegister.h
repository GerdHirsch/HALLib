/*
 * RTCTestRegister.h
 *
 *  Created on: 30.12.2013
 *      Author: Gerd
 */

#ifndef RTCTESTREGISTER_H_
#define RTCTESTREGISTER_H_
#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HALMock/RegisterMock.h>
#include <HALMock/Types.h>
//===================================================================
// RTC
//===================================================================
namespace Mock {
extern unsigned long  Ilr;
extern unsigned long  Ctc;
extern unsigned long  Ccr;
extern unsigned long  Ciir;
extern unsigned long  Amr;
extern unsigned long  CTime0;
extern unsigned long  CTime1;
extern unsigned long  CTime2;
extern unsigned long  Clk_sec;
extern unsigned long  Clk_min;
extern unsigned long  Clk_hour;
extern unsigned long  Clk_dom;
extern unsigned long  Clk_dow;
extern unsigned long  Clk_doy;
extern unsigned long  Clk_month;
extern unsigned long  Clk_year;
extern unsigned long  Al_sec;
extern unsigned long  Al_min;
extern unsigned long  Al_hour;
extern unsigned long  Al_dom;
extern unsigned long  Al_dow;
extern unsigned long  Al_doy;
extern unsigned long  Al_month;
extern unsigned long  Al_year;
extern unsigned long  Preint;
extern unsigned long  Prefrac;

template<class ProzessorType>
struct RTCRegister{
	// register für Clock und Alarm
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef Mock::RegisterMock<Traits, &Ilr>  ilr;
	typedef Mock::RegisterMock<Traits, &Ctc>  ctc;
	typedef Mock::RegisterMock<Traits, &Ccr>  ccr;
	typedef Mock::RegisterMock<Traits, &Ciir>  ciir;
	typedef Mock::RegisterMock<Traits, &Amr>  amr;
	// register für Clock
	typedef Mock::RegisterMock<Traits, &CTime0>  cTime0;
	typedef Mock::RegisterMock<Traits, &CTime1>  cTime1;
	typedef Mock::RegisterMock<Traits, &CTime2>  cTime2;
	typedef Mock::RegisterMock<Traits, &Clk_sec>  Clk_Sec;
	typedef Mock::RegisterMock<Traits, &Clk_min>  Clk_Min;
	typedef Mock::RegisterMock<Traits, &Clk_hour>  Clk_Hour;
	typedef Mock::RegisterMock<Traits, &Clk_dom>  Clk_Dom;
	typedef Mock::RegisterMock<Traits, &Clk_dow>  Clk_Dow;
	typedef Mock::RegisterMock<Traits, &Clk_doy>  Clk_Doy;
	typedef Mock::RegisterMock<Traits, &Clk_month>  Clk_Month;
	typedef Mock::RegisterMock<Traits, &Clk_year>  Clk_Year;
	// register für Alarm
	typedef Mock::RegisterMock<Traits, &Al_sec>  Al_Sec;
	typedef Mock::RegisterMock<Traits, &Al_min>  Al_Min;
	typedef Mock::RegisterMock<Traits, &Al_hour>  Al_Hour;
	typedef Mock::RegisterMock<Traits, &Al_dom>  Al_Dom;
	typedef Mock::RegisterMock<Traits, &Al_dow>  Al_Dow;
	typedef Mock::RegisterMock<Traits, &Al_doy>  Al_Doy;
	typedef Mock::RegisterMock<Traits, &Al_month>  Al_Month;
	typedef Mock::RegisterMock<Traits, &Al_year>  Al_Year;
	// Reference clock divider (prescaler)
	// integer anteil
	typedef Mock::RegisterMock<Traits, &Preint>  PreInt;
	//fractional anteil
	typedef Mock::RegisterMock<Traits, &Prefrac>  PreFrac;

	struct ClockRegister{
		typedef Clk_Sec sec;
		typedef Clk_Min min;
		typedef Clk_Hour hour;
		typedef Clk_Dom dom; // Day of Month
		typedef Clk_Dow dow; // Day of Week
		typedef Clk_Doy doy; // Day of year
		typedef Clk_Month month;
		typedef Clk_Year year;
	};
	struct AlarmRegister{
		typedef Al_Sec sec;
		typedef Al_Min min;
		typedef Al_Hour hour;
		typedef Al_Dom dom;
		typedef Al_Dow dow;
		typedef Al_Doy doy;
		typedef Al_Month month;
		typedef Al_Year year;
	};
};
} // namespace Mock
//-------------------------------------------------------------------
namespace Generator {
// RTC
template<class Origin, class ConfigRepository>
struct Component<
	CS<SS<HAL::RTC, HAL::Register>, Mock::Base>,
	Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef Mock::RTCRegister<ProzessorType> type;
};
} // namespace Generator

#endif /* RTCTESTREGISTER_H_ */
