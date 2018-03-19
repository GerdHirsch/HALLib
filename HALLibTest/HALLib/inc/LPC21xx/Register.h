#ifndef __LPC21XX_REGISTER_H__
#define __LPC21XX_REGISTER_H__

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/MemoryMappedRegister.h>
#include <LPC21xx/Traits.h>

//===================================================================
// PinConnectBlock
//===================================================================
namespace LPC21xx{
template <class ProzessorType>
struct PinConnectBlockRegistersLPC21xx {
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE002C000> PinSel_0;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002C004> PinSel_1;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002C014> PinSel_2;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<
	CS<SS<HAL::PinConnectBlock, HAL::Register>, LPC21xx::Base>,
	Origin,
	ConfigRepository>
//struct Component<CS<HAL::PCBRegister, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef LPC21xx::PinConnectBlockRegistersLPC21xx<ProzessorType> type;
};
} // namespace Generator
//===================================================================
// GPIOPort
//===================================================================
namespace LPC21xx{
template <class ProzessorType>
struct GPIOPort0Register {
	enum { port = 0 };
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0028000> IOPIN;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0028004> IOSET;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0028008> IODIR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002800C> IOCLR;
};
template <class ProzessorType>
struct GPIOPort1Register {
	enum { port = 1 };
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0028010> IOPIN;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0028014> IOSET;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0028018> IODIR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002801C> IOCLR;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<
	CS< SS<NO<HAL::GPIO, 0>, HAL::Register>, LPC21xx::Base>,
	Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef LPC21xx::GPIOPort0Register<ProzessorType> type;
};
template<class Origin, class ConfigRepository>
struct Component<
	CS<SS<NO<HAL::GPIO, 1>, HAL::Register>, LPC21xx::Base>,
	Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef LPC21xx::GPIOPort1Register<ProzessorType> type;
};
} // namespace Generator
////===================================================================
//// ADC_ALT ???
////===================================================================
namespace LPC21xx {
template<class ProzessorType>
struct ADC0Register{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0034000> CR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034004> GDR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034030> STAT;
	typedef HAL::MemoryMappedRegister<Traits, 0xE003400C> INTEN;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0034008> GSR;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0034010> DR0;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034014> DR1;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034018> DR2;
	typedef HAL::MemoryMappedRegister<Traits, 0xE003401C> DR3;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034020> DR4;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034024> DR5;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034028> DR6;
	typedef HAL::MemoryMappedRegister<Traits, 0xE003402C> DR7;
};

template<class ProzessorType>
struct ADC1Register{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0060000> CR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060004> GDR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060030> STAT;
	typedef HAL::MemoryMappedRegister<Traits, 0xE006000C> INTEN;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0034008> GSR;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0060010> DR0;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060014> DR1;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060018> DR2;
	typedef HAL::MemoryMappedRegister<Traits, 0xE006001C> DR3;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060020> DR4;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060024> DR5;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060028> DR6;
	typedef HAL::MemoryMappedRegister<Traits, 0xE006002C> DR7;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
//---------------------------------------------------------------------
// ADC0
//---------------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<SS<NO<HAL::ADC, 0>, HAL::Register>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef LPC21xx::ADC0Register<ProzessorType> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<SS<NO<HAL::ADC, 1>, HAL::Register>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef LPC21xx::ADC1Register<ProzessorType> type;
};
} // namespace Generator

/*
////===================================================================
//// ADC_ALT
////===================================================================

namespace LPC21xx {

template<class ProzessorType, class AD_DRn_>
struct CommonADC0Register{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0034000> AD_CR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034004> AD_GDR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034030> AD_STAT;
	typedef HAL::MemoryMappedRegister<Traits, 0xE003400C> AD_INTEN;

	typedef AD_DRn_ AD_DRn;
};

template<class ProzessorType, class AD_DRn_>
struct CommonADC1Register{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0060000> AD_CR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060004> AD_GDR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060030> AD_STAT;
	typedef HAL::MemoryMappedRegister<Traits, 0xE006000C> AD_INTEN;

	typedef AD_DRn_ AD_DRn;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
//---------------------------------------------------------------------
// ADC0
//---------------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC0Register, 0>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034010> AD_DRn;
	typedef LPC21xx::CommonADC0Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC0Register, 1>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034014> AD_DRn;
	typedef LPC21xx::CommonADC0Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC0Register, 2>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034018> AD_DRn;
	typedef LPC21xx::CommonADC0Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC0Register, 3>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE003401C> AD_DRn;
	typedef LPC21xx::CommonADC0Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC0Register, 4>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034020> AD_DRn;
	typedef LPC21xx::CommonADC0Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC0Register, 5>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034024> AD_DRn;
	typedef LPC21xx::CommonADC0Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC0Register, 6>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0034028> AD_DRn;
	typedef LPC21xx::CommonADC0Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC0Register, 7>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE003402C> AD_DRn;
	typedef LPC21xx::CommonADC0Register<ProzessorType, AD_DRn> type;
};

//---------------------------------------------------------------------
// ADC1
//---------------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC1Register, 0>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060010> AD_DRn;
	typedef LPC21xx::CommonADC1Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC1Register, 1>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060014> AD_DRn;
	typedef LPC21xx::CommonADC1Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC1Register, 2>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060018> AD_DRn;
	typedef LPC21xx::CommonADC1Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC1Register, 3>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE006001C> AD_DRn;
	typedef LPC21xx::CommonADC1Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC1Register, 4>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060020> AD_DRn;
	typedef LPC21xx::CommonADC1Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC1Register, 5>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060024> AD_DRn;
	typedef LPC21xx::CommonADC1Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC1Register, 6>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0060028> AD_DRn;
	typedef LPC21xx::CommonADC1Register<ProzessorType, AD_DRn> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC1Register, 7>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE006002C> AD_DRn;
	typedef LPC21xx::CommonADC1Register<ProzessorType, AD_DRn> type;
};
} // namespace Generator
*/
//---------------------------------------------------------------------
// Serial Peripheral Interface (SPI) full duplex
//---------------------------------------------------------------------
namespace LPC21xx {
template<class HAL_Traits>
struct CommonSPIRegister {
	typedef HAL_Traits Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0020000> SPCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0020004> SPSR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0020008> SPDR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002000C> SPCCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002001C> SPINT;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::SPIRegister, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef LPC21xx::CommonSPIRegister<Traits> type;
};
} // namespace Generator
//---------------------------------------------------------------------
// Synchronous Serial Port (SSP)
//---------------------------------------------------------------------
namespace LPC21xx {
template<class HAL_Traits>
struct CommonSSPRegister {
	typedef HAL_Traits Traits;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0020000> SPCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0020004> SPSR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0020008> SPDR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002000C> SPCCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002001C> SPINT;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::SSPRegister, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef LPC21xx::CommonSSPRegister<Traits> type;
};
} // namespace Generator
//===================================================================
// VIC
//===================================================================
namespace LPC21xx {

template <class ProzessorType>
struct VICRegistersLPC21xx {
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF000> IRQStatus    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF004> FIQStatus    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF008> RawIntr      ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF00C> IntSelect    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF010> IntEnable    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF014> IntEnClr     ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF018> SoftInt      ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF01C> SoftIntClr   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF020> Protection   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF030> VectAddr     ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF034> DefVectAddr  ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF100> VectAddr0    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF104> VectAddr1    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF108> VectAddr2    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF10C> VectAddr3    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF110> VectAddr4    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF114> VectAddr5    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF118> VectAddr6    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF11C> VectAddr7    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF120> VectAddr8    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF124> VectAddr9    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF128> VectAddr10   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF12C> VectAddr11   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF130> VectAddr12   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF134> VectAddr13   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF138> VectAddr14   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF13C> VectAddr15   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF200> VectCntl0    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF204> VectCntl1    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF208> VectCntl2    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF20C> VectCntl3    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF210> VectCntl4    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF214> VectCntl5    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF218> VectCntl6    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF21C> VectCntl7    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF220> VectCntl8    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF224> VectCntl9    ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF228> VectCntl10   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF22C> VectCntl11   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF230> VectCntl12   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF234> VectCntl13   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF238> VectCntl14   ;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF23C> VectCntl15   ;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<SS<HAL::VIC, HAL::Register>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef LPC21xx::VICRegistersLPC21xx<ProzessorType> type;
};
} // namespace Generator

//===================================================================
// Timer
//===================================================================
namespace LPC21xx {
template <class ProzessorType>
struct Timer0RegistersLPC21xx {
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0004000>  IR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004004>  TCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004008>  TC;
	typedef HAL::MemoryMappedRegister<Traits, 0xE000400C>  PR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004010>  PC;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004014>  MCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004018>  MR0;
	typedef HAL::MemoryMappedRegister<Traits, 0xE000401C>  MR1;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004020>  MR2;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004024>  MR3;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004028>  CCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE000402C>  CR0;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004030>  CR1;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004034>  CR2;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004038>  CR3;
	typedef HAL::MemoryMappedRegister<Traits, 0xE000403C>  EMR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0004070>  CTCR;
};
template <class ProzessorType>
struct Timer1RegistersLPC21xx {
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE0008000>  IR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008004>  TCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008008>  TC;
	typedef HAL::MemoryMappedRegister<Traits, 0xE000800C>  PR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008010>  PC;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008014>  MCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008018>  MR0;
	typedef HAL::MemoryMappedRegister<Traits, 0xE000801C>  MR1;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008020>  MR2;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008024>  MR3;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008028>  CCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE000802C>  CR0;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008030>  CR1;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008034>  CR2;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008038>  CR3;
	typedef HAL::MemoryMappedRegister<Traits, 0xE000803C>  EMR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0008070>  CTCR;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<SS<NO<HAL::Timer, 0>, HAL::Register>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef LPC21xx::Timer0RegistersLPC21xx<ProzessorType> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<SS<NO<HAL::Timer, 1>, HAL::Register>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef LPC21xx::Timer1RegistersLPC21xx<ProzessorType> type;
};
} // namespace Generator
//===================================================================
// RTC
//===================================================================
namespace LPC21xx {
template <class ProzessorType>
struct RTCRegistersLPC21xx {
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;
	// register für Clock und Alarm
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024000>  ilr;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024004>  ctc;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024008>  ccr;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002400C>  ciir;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024010>  amr;
	//Clock
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024014>  cTime0;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024018>  cTime1;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002401C>  cTime2;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024020>  Clk_Sec;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024024>  Clk_Min;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024028>  Clk_Hour;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002402C>  Clk_Dom;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024030>  Clk_Dow;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024034>  Clk_Doy;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024038>  Clk_Month;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002403C>  Clk_Year;
	//Alarm
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024060>  Al_Sec;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024064>  Al_Min;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024068>  Al_Hour;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002406C>  Al_Dom;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024070>  Al_Dow;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024074>  Al_Doy;
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024078>  Al_Month;
	typedef HAL::MemoryMappedRegister<Traits, 0xE002407C>  Al_Year;
	// Reference clock divider (prescaler)
	// integer anteil
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024080>  PreInt;
	// fraction anteil
	typedef HAL::MemoryMappedRegister<Traits, 0xE0024084>  PreFrac;

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
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<
			CS< SS<HAL::RTC, HAL::Register>, LPC21xx::Base>,
			Origin, ConfigRepository
				>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef LPC21xx::RTCRegistersLPC21xx<ProzessorType> type;
};
} // namespace Generator
//===================================================================
// SystemControl
//===================================================================
namespace LPC21xx {
template <class ProzessorType>
struct SCRegistersLPC21xx {
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	// External Interrupts (EXT)
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC140>  EXTINT;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC144>  EXTWAKE;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC148>  EXTMODE;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC14C>  EXTPOLAR;

	// Memory Accelerator Module (MAM) (MEM?? siehe Doku)
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC000>  MAMCR;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC004>  MAMTIM;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC040>  MAMMAP;

	// Phase Locked Loop (PLL)
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC080>  PLLCON;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC084>  PLLCFG;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC088>  PLLSTAT;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC08C>  PLLFEED;
	// IntEnable/Disable wird benötigt um während des feeds alle
	// interrupts auszuschalten
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF010> IntEnable;
	typedef HAL::MemoryMappedRegister<Traits, 0xFFFFF014> IntEnClr;

	// Power Control (PC)
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC0C0>  PCON;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC0C4>  PCONP;

	// VPB Divider (APB Divider?? Doku)
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC100>  VPBDIV;

	// Reset
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC180>  RSIR;

	// Code Security/Debugging
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC184>  CSPR;

	// System Controls and Status
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC1A0>  SCS;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<SS<HAL::SystemControl, HAL::Register>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef LPC21xx::SCRegistersLPC21xx<ProzessorType> type;
};
} // namespace Generator
//===================================================================
// ExternalInterrupt
//===================================================================
namespace LPC21xx {
template <class ProzessorType>
struct EINTRegistersLPC21xx {
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC140>  EXTINT;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC144>  EXTWAKE;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC148>  EXTMODE;
	typedef HAL::MemoryMappedRegister<Traits, 0xE01FC14C>  EXTPOLAR;

};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::EINTRegister, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef LPC21xx::EINTRegistersLPC21xx<ProzessorType> type;
};
} // namespace Generator
////===================================================================
//// DAC
////===================================================================
//namespace LPC21xx{
//
//template <class BoardType>
//struct DACRegisterLPC21xx {
//	typedef typename Generator::SD::Create<BoardType, HAL::Traits>::type Traits;
//
//	typedef HAL::MemoryMappedRegister<Traits, 0xE006C000> DA_CR;
//};
//} // namespace LPC21xx
////-------------------------------------------------------------------
//namespace Generator { namespace SD {
//template<class BoardType, class ConfigRepository>
//struct Component<LPC21xx::Base, LPC21xx::DACRegister, BoardType, ConfigRepository>
//{
//	typedef LPC21xx::DACRegisterLPC21xx<BoardType> type;
//};
//}} // namespace Generator::SD
//

////===================================================================
////
////===================================================================
//namespace LPC21xx{
//
//} // namespace LPC21xx
////-------------------------------------------------------------------
//namespace Generator { namespace SD {
//
//}} // namespace Generator::SD

#endif // __LPC21XX_REGISTER_H__
