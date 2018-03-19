#ifndef __HAL_COMPONENT_TYPES_H__
#define __HAL_COMPONENT_TYPES_H__

#include <Generator/BaseType.h>

/*
    these Types here do only define Types to
    select specific templates
    dieser header definiert die namen der Geräte die auf allen
    Prozessoren typischerweise vorhanden sind
*/

namespace HAL
{
	template<
		class BoardType,
		class ProzessorType,
		class Base = Generator::EmptyRepository>
	struct PlatformRepository : Base {
		typedef PlatformRepository<BoardType, ProzessorType, Base> Platform;
		typedef BoardType board_type;
		typedef ProzessorType prozessor_type;
		typedef Generator::CS<BoardType, ProzessorType> type;
	};
	/*
	 * Anforderung der Register für die Devices mit
	 * CS<SS<PinConnectBlock, Register>, CurrentProcessor>
	 * CS<SS<NO<GPIO, 1>, Register>, CurrentProcessor>
	 */
	struct Register;
	/*
	 * Anforderung der Devices mit
	 * CS<PinConnectBlock, CurrentProcessor>
	 * CS<NO<GPIO, 1>, CurrentProcessor>
	 */
	struct Traits;
	struct PinConnectBlock;
	struct SystemControl;
	struct PowerControl;
	struct PhaseLockedLoop;
	struct GPIO;
	struct VIC;
	struct DAC;

	struct WDT;
	struct Timer;
	struct UART;
	struct PWM;
	struct I2C;
	struct SPI;
	struct SSP;
	struct PLL;
	struct RTC;
	struct ExternalInterrupt;
	struct ADC;


	// Prototypes für zukünftigen Generator
    struct ComponentConfigurator;
    struct ConfigurationLibrary;

    struct Pin;
    typedef Generator::NO<Pin, 0> Pin0;
    typedef Generator::NO<Pin0, 0> Pin0_0;
    typedef Generator::NO<Pin0, 1> Pin0_1;
    typedef Generator::NO<Pin0, 2> Pin0_2;
    typedef Generator::NO<Pin0, 28> Pin0_28;
    //usw
    typedef Generator::NO<Pin, 1> Pin1;
    typedef Generator::NO<Pin1, 0> Pin1_0;
    typedef Generator::NO<Pin1, 1> Pin1_1;
    //usw

//---------------------------------------------------------------------
    // RegisterTypes
//	struct PCBRegister{
//		static char const* name(){return "HAL::PCBRegister"; }
//	};
//	struct GPIORegister{
//		static char const* name(){return "HAL::GPIORegister"; }
//	};
//	struct PWMRegister{
//		static char const* name(){return "HAL::PWMRegister"; }
//	};
	struct PWMnRegister{
		static char const* name(){return "HAL::PWMnRegister"; }
	};

//	struct ADCRegister{
//		static char const* name(){return "HAL::ADCRegister"; }
//	};

/*
 	struct ADC0Register{
		static char const* name(){return "HAL::ADC0Register"; }
	};
	struct ADC1Register{
		static char const* name(){return "HAL::ADC1Register"; }
	};
*/
//	struct DACRegister{
//		static char const* name(){return "HAL::DACRegister"; }
//	};
//
//	struct VICRegister{
//		static char const* name(){return "HAL::VICRegister"; }
//	};
//	struct TimerRegister{
//		static char const* name(){return "HAL::TimerRegister"; }
//	};
//	struct RTCRegister{
//		static char const* name(){return "HAL::RTCRegister"; }
//	};
//	struct SystemControlRegister{
//		static char const* name(){return "HAL::PowerControlRegister"; }
//	};

	struct SPIRegister{
		static char const* name(){return "HAL::SPIRegister"; }
	};
	struct SSPRegister{
		static char const* name(){return "HAL::SSPRegister"; }
	};
	struct EINTRegister{
		static char const* name(){return "HAL::EINTRegister"; }
	};
	struct UARTRegister{
		static char const* name(){return "HAL::UARTRegister"; }
	};

} // end namespace HAL

#endif //__HAL_COMPONENT_TYPES_H__
