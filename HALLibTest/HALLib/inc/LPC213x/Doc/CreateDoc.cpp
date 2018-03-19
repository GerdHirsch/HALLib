///*
// * CreateDoku.cpp
// *
// *  Created on: 03.01.2012
// *      Author: Gerd
// */
//
//#include<iostream>
//#include<string>
//#include <fstream>
//
//
//#include <Generator/Tools.h>
//#include <Generator/XMLPrinters.h>
//
//#include "HAL/ComponentTypes.h"
//#include "HAL/ComponentNames.h"
//
//#include <LPC213x/Types.h>
//#include <LPC213x/Hal.h>
//
//#include <RegisterTest/TestRegister.h>
//
//using namespace std;
//using namespace Generator;
//
//namespace LPC213x{
//
//void createContextDoc(){
//	std::ofstream os("LPC2138Doc.xml");
//
//    typedef
//        Loki::TL::
//        MakeTypelist<
//            NO<HAL::ADCRegister, 0>,
//            NO<HAL::ADCRegister, 1>
//                    >
//    ::Result ADCRegisterRows;
//
//    typedef
//        Loki::TL::
//        MakeTypelist<
//            NO<HAL::AD0, 0>,
//            NO<HAL::AD0, 1>,
//            NO<HAL::AD0, 2>,
//            NO<HAL::AD0, 3>,
//            NO<HAL::AD0, 4>,
//            NO<HAL::AD0, 5>,
//            NO<HAL::AD0, 6>,
//            NO<HAL::AD0, 7>,
//            NO<HAL::AD1, 0>,
//            NO<HAL::AD1, 1>,
//            NO<HAL::AD1, 2>,
//            NO<HAL::AD1, 3>,
//            NO<HAL::AD1, 4>,
//            NO<HAL::AD1, 5>,
//            NO<HAL::AD1, 6>,
//            NO<HAL::AD1, 7>
//                    >
//    ::Result ADCRows;
//
//    typedef
//        Loki::TL::
//        MakeTypelist<
//            HAL::SPI,
//            HAL::SPIRegister,
//            HAL::SSP,
//            HAL::SSPRegister
//                    >
//    ::Result SPIRows;
//
//    typedef
//        Loki::TL::
//        MakeTypelist<
//        	HAL::PinConnectBlock,
//        	HAL::Traits,
//            NO<HAL::GPIO, 0>,
//            NO<HAL::GPIO, 1>,
//            NO<HAL::GPIORegister, 0>,
//            NO<HAL::GPIORegister, 1>,
//            HAL::VIC,
//            HAL::VICRegister,
//            HAL::PWM,
//            NO<HAL::PWM, 1>,
//            NO<HAL::PWM, 2>,
//            NO<HAL::PWM, 3>,
//            NO<HAL::PWM, 4>,
//            NO<HAL::PWM, 5>,
//            NO<HAL::PWM, 6>,
//            NO<HAL::DAC, 0>,
//            NO<HAL::UART, 0>,
//            NO<HAL::UART, 1>
//                    >
//    ::Result ComponentRows;
//
//    typedef
//        Loki::TL::
//        MakeTypelist<
//
//            NO<HAL::Timer, 0>,
//            NO<HAL::TimerRegister, 0>
//                    >
//    ::Result ComponentRows2;
//
//    typedef Loki::TL::Append<ComponentRows,
//    		Loki::TL::Append<SPIRows,
//    		Loki::TL::Append<ComponentRows2,
//    		Loki::TL::Append<ADCRows, ADCRegisterRows>
//    	::Result>
//    	::Result>
//    	::Result>
//    	::Result Rows;
//
//    typedef Mock::LPC2134 Context;
//
//    XML::XMLContexts<Context, Rows>::print(os);
//}
//// prototyp zu vereinfachung der listen
//template<class Components>
//struct ComponentList;
//
//template<class List_>
//struct TempList : ComponentList<TempList<List_> >{
//	typedef List_ List;
//};
//template<class Components>
//struct ComponentList{
//    template<class ToAppend>
//    struct append{
//    	typedef TempList<
//    			typename Loki::TL::Append<
//    			typename Components::List,
//    			typename ToAppend::List>::Result> type;
//    };
//
//};
//
//struct ADCRegisterList : ComponentList<ADCRegisterList>{
//    typedef
//        Loki::TL::
//        MakeTypelist<
//            NO<HAL::ADC0Register, 0>,
//            NO<HAL::ADC0Register, 1>,
//            NO<HAL::ADC0Register, 2>,
//            NO<HAL::ADC0Register, 3>,
//            NO<HAL::ADC0Register, 4>,
//            NO<HAL::ADC0Register, 5>,
//            NO<HAL::ADC0Register, 6>,
//            NO<HAL::ADC0Register, 7>,
//            NO<HAL::ADC1Register, 0>,
//            NO<HAL::ADC1Register, 1>,
//            NO<HAL::ADC1Register, 2>,
//            NO<HAL::ADC1Register, 3>,
//            NO<HAL::ADC1Register, 4>,
//            NO<HAL::ADC1Register, 5>,
//            NO<HAL::ADC1Register, 6>,
//            NO<HAL::ADC1Register, 7>
//                    >
//    ::Result List;
//};
//
//struct ADCList : ComponentList<ADCList>{
//    typedef
//        Loki::TL::
//        MakeTypelist<
//            NO<HAL::AD0, 0>,
//            NO<HAL::AD0, 1>,
//            NO<HAL::AD0, 2>,
//            NO<HAL::AD0, 3>,
//            NO<HAL::AD0, 4>,
//            NO<HAL::AD0, 5>,
//            NO<HAL::AD0, 6>,
//            NO<HAL::AD0, 7>,
//            NO<HAL::AD1, 0>,
//            NO<HAL::AD1, 1>,
//            NO<HAL::AD1, 2>,
//            NO<HAL::AD1, 3>,
//            NO<HAL::AD1, 4>,
//            NO<HAL::AD1, 5>,
//            NO<HAL::AD1, 6>,
//            NO<HAL::AD1, 7>
//                    >
//    ::Result List;
//};
//struct PWMList : ComponentList<ADCList>{
//    typedef
//        Loki::TL::
//        MakeTypelist<
//            NO<HAL::PWM, 0>,
//            NO<HAL::PWM, 1>,
//            NO<HAL::PWM, 2>,
//            NO<HAL::PWM, 3>,
//            NO<HAL::PWM, 4>,
//            NO<HAL::PWM, 5>,
//            NO<HAL::PWM, 6>
//                    >
//    ::Result List;
//};
//
////void createContextDoc_(){
////	std::ofstream os("LPC2138Doc.xml");
////
//////	typedef ADCList::List Rows;
////
////	typedef ADCList
////			::append<ADCRegisterList
////			::append<SPIList
//////			::append<PWMList
//////		>::type
////		>::type
////		>::type
////	::List Rows;
////
////    typedef Mock::LPC2134 Context;
////
////    XML::XMLContexts<Context, Rows>::print(os);
////}
//} //namespace LPC214x

