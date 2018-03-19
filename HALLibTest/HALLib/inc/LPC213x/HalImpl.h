//#ifndef LPC213xHALIMPL_H
//#define LPC213xHALIMPL_H
//
//#include <Generator/CreateComponent.h>
//#include <HAL/ComponentTypes.h>
//
//#include <LPC21xx/Traits.h>
//#include <LPC21xx/SPI.h>
//#include <LPC21xx/GPIOPort.h>
//
//#include <LPC213x/Types.h>
//
//#include <LPC213x/PinConnectBlock.h>
////#include <LPC213x/PWM.h>
////#include <LPC213x/ADC.h>
////#include <LPC213x/ADC1.h>
//
//namespace LPC213x{
//
//template<class BoardType, class ConfigRepository>
//struct HAL2131;
//
//template<class BoardType, class ConfigRepository>
//struct HAL2132;
//
//template<class BoardType, class ConfigRepository>
//struct HAL2134;
//}
//
//namespace Generator { namespace SD {
//
////=========================================================
//template<class BoardType, class ConfigRepository>
//struct Component<LPC213x::LPC2131, HAL::Layer, BoardType, ConfigRepository>
//{
//    typedef LPC213x::HAL2131<BoardType, ConfigRepository> type;
//
//};
////=========================================================
//template<class BoardType, class ConfigRepository>
//struct Component<LPC213x::LPC2132, HAL::Layer, BoardType, ConfigRepository>
//{
//    typedef LPC213x::HAL2132<BoardType, ConfigRepository> type;
//};
////=========================================================
//template<class BoardType, class ConfigRepository>
//struct Component<LPC213x::LPC2134, HAL::Layer, BoardType, ConfigRepository>
//{
//    typedef LPC213x::HAL2134<BoardType, ConfigRepository> type;
//};
////=========================================================
//}} // namespace Generator::SD
//namespace LPC213x{
//
//template<class BoardType, class ConfigRepository>
//struct HAL2131{
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
//struct HAL2132
//: HAL2131<BoardType, ConfigRepository>
//{
//	typedef BoardType board_type;
//    // Geräte
////    typedef typename Generator::SD::Create<board_type, HAL::DAC>::type DAC;
//
//};
//
//template<class BoardType, class ConfigRepository>
//struct HAL2134
//: HAL2132<BoardType, ConfigRepository>
//{
//	typedef BoardType board_type;
//    // weitere Geräte
////    typedef typename Generator::SD::Create<board_type, HAL::AD1>::type AD1;
//};
//
//}
//
//#endif //LPC213xHALIMPL_H
