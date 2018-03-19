#include<iostream>
#include<string>
#include <fstream>


#include <Generator/Tools.h>
#include <Generator/XMLPrinters.h>

#include <HAL/ComponentTypes.h>
#include <HAL/ComponentNames.h>

#include <LPC214x/Types.h>
#include <LPC214x/Hal.h>

#include <RegisterTest/TestRegister.h>
#include <RegisterTest/PCBTestRegister.h>

using namespace std;
using namespace Generator;

namespace LPC214x{

void createContextDoc(){
	std::ofstream os("LPC2148Doc.xml");

	// Noch nicht implmenentiere Components
    typedef
        Loki::TL::
        MakeTypelist<
            NO<HAL::UARTRegister, 0>,
            NO<HAL::UART, 0>,
            NO<HAL::UARTRegister, 1>,
            NO<HAL::UART, 1>
                    >
    ::Result UnimplementedRows;

    // RegisterComponents alphabetisch
    typedef
        Loki::TL::
        MakeTypelist<
			HAL::EINTRegister,
            SS<NO<HAL::GPIO, 0>, HAL::Register>,
            SS<NO<HAL::GPIO, 1>, HAL::Register>,
			SS<HAL::RTC, HAL::Register>,
            HAL::SPIRegister,
            HAL::SSPRegister,
			SS<HAL::SystemControl, HAL::Register>,
            SS<NO<HAL::Timer, 0>, HAL::Register>,
            SS<NO<HAL::Timer, 1>, HAL::Register>,
            SS<HAL::VIC, HAL::Register>
                    >
    ::Result RegisterRows;

    typedef
        Loki::TL::
        MakeTypelist<
			SS<NO<HAL::ADC, 0>, HAL::Register>,
            NO<HAL::ADC, 0>,
			SS<NO<HAL::ADC, 1>, HAL::Register>,
            NO<HAL::ADC, 1>,
			SS<HAL::DAC, HAL::Register>,
            HAL::DAC,
			SS<NO<HAL::DAC, 0>, HAL::Register>,
            NO<HAL::DAC, 0>,
			SS<NO<HAL::DAC, 1>, HAL::Register>,
            NO<HAL::DAC, 1>
                    >
    ::Result ADC_DAC_Rows;

    typedef
        Loki::TL::
        MakeTypelist<
            SS<HAL::PWM, HAL::Register>,
            HAL::PWM,
            NO<HAL::PWM, 1>,
            NO<HAL::PWM, 2>,
            NO<HAL::PWM, 3>,
            NO<HAL::PWM, 4>,
            NO<HAL::PWM, 5>,
            NO<HAL::PWM, 6>
                    >
    ::Result PWM_Rows;

    typedef
        Loki::TL::
        MakeTypelist<
        	HAL::Traits,
        	SS<HAL::PinConnectBlock, HAL::Register>,
        	HAL::PinConnectBlock,
            HAL::VIC,

            NO<HAL::GPIO, 0>,
            NO<HAL::GPIO, 1>,
			HAL::RTC,
			HAL::SystemControl,
            NO<HAL::Timer, 0>,
            NO<HAL::Timer, 1>,
			HAL::ExternalInterrupt,
            HAL::SPI,
            HAL::SSP
                    >
    ::Result BasicComponentRows;

    typedef Loki::TL::Append<BasicComponentRows,
    		Loki::TL::Append<RegisterRows,
    		Loki::TL::Append<PWM_Rows,
    		Loki::TL::Append<ADC_DAC_Rows, UnimplementedRows>
    	::Result>
    	::Result>
    	::Result>
    	::Result Rows;

    typedef Mock::LPC2144 Context;

    XML::XMLContexts<Context, Rows>::print(os);
}

} //namespace LPC214x

