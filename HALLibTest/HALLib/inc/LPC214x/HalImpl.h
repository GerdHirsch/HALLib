//#ifndef LPC214xHALIMPL_H
//#define LPC214xHALIMPL_H
//
//#include <Generator/CreateComponent.h>
//#include <HAL/ComponentTypes.h>
//
//#include <LPC21xx/Traits.h>
//#include <LPC21xx/SPI.h>
//#include <LPC21xx/GPIOPort.h>
//
//#include <LPC214x/Types.h>
//
//#include <LPC214x/PinConnectBlock.h>
//#include <LPC214x/PWM.h>
//#include <LPC214x/ADC.h>
//
//namespace LPC214x{
//
//template<class BoardType, class ConfigRepository>
//struct HAL2141;
//
//template<class BoardType, class ConfigRepository>
//struct HAL2142;
//
//template<class BoardType, class ConfigRepository>
//struct HAL2144;
//}
//
//namespace Generator { namespace SD {
//
////=========================================================
//template<class BoardType, class ConfigRepository>
//struct Component<LPC214x::LPC2141, HAL::Layer, BoardType, ConfigRepository>
//{
//    typedef LPC214x::HAL2141<BoardType, ConfigRepository> type;
//
//};
////=========================================================
//template<class BoardType, class ConfigRepository>
//struct Component<LPC214x::LPC2142, HAL::Layer, BoardType, ConfigRepository>
//{
//    typedef LPC214x::HAL2142<BoardType, ConfigRepository> type;
//};
////=========================================================
//template<class BoardType, class ConfigRepository>
//struct Component<LPC214x::LPC2144, HAL::Layer, BoardType, ConfigRepository>
//{
//    typedef LPC214x::HAL2144<BoardType, ConfigRepository> type;
//};
//
////=========================================================
//}} // namespace Generator::SD
//
//namespace LPC214x{
//
//template<class BoardType, class ConfigRepository>
//struct HAL2141{
//    typedef BoardType board_type;
//
//    typedef typename Generator::SD::Create<board_type, HAL::Traits>::type traits;
//    typedef typename traits::RegisterType RegisterType;
//
//    // geräte
//    typedef typename Generator::SD::Create<board_type, HAL::PinConnectBlock>::type PinConnectBlock;
//    typedef typename Generator::SD::Create<board_type, HAL::GPIOPort0>::type GPIOPort0;
//    typedef typename Generator::SD::Create<board_type, HAL::GPIOPort1>::type GPIOPort1;
//
//    typedef typename Generator::SD::Create<board_type, HAL::PWM>::type PWM;
//
//    typedef typename Generator::SD::Create<board_type, HAL::AD0_1>::type AD0;
//	typedef typename Generator::SD::Create<board_type, HAL::UART0>::type UART0;
//    typedef typename Generator::SD::Create<board_type, HAL::UART1>::type UART1;
//
//    typedef typename Generator::SD::Create<board_type, HAL::SPI0>::type SPI0;
//};
//
//template<class BoardType, class ConfigRepository>
//struct HAL2142
//: HAL2141<BoardType, ConfigRepository>
//{
//	typedef BoardType board_type;
//    // Geräte
//    typedef typename Generator::SD::Create<board_type, HAL::DAC>::type dac;
//
//};
//
//template<class BoardType, class ConfigRepository>
//struct HAL2144
//: HAL2142<BoardType, ConfigRepository>
//{
//	typedef BoardType board_type;
//    // weitere Geräte
//    typedef typename Generator::SD::Create<board_type, HAL::AD1>::type AD1;
//};
//
//}
//
//#endif //LPC214xHALIMPL_H
