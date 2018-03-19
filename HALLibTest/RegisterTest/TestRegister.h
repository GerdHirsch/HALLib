#ifndef TESTREGISTER_H_
#define TESTREGISTER_H_

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HALMock/RegisterMock.h>
#include <HALMock/Types.h>


//===================================================================
// PWM
//===================================================================
namespace Mock {
// Allgemeine PWM Register
extern unsigned long  pwm_tcr;
extern unsigned long  pwm_tc;
extern unsigned long  pwm_pr;
extern unsigned long  pwm_pc;
//wird von allen benötigt
extern unsigned long  pwm_ir;
extern unsigned long  pwm_mcr;
extern unsigned long  pwm_ler;
extern unsigned long  pwm_mr0;

//PWMn spezifische
extern unsigned long  pwm_pcr;
extern unsigned long  pwm_mrn;

template<class HAL_Traits>
struct CommonPWMnRegister{
	typedef HAL_Traits Traits;

	typedef RegisterMock<Traits, &pwm_ir> PWM_IR;
	typedef RegisterMock<Traits, &pwm_mcr> PWM_MCR;
	typedef RegisterMock<Traits, &pwm_pcr> PWM_PCR;
	typedef RegisterMock<Traits, &pwm_ler> PWM_LER;
	typedef RegisterMock<Traits, &pwm_mr0> PWM_MR0;
	typedef RegisterMock<Traits, &pwm_mrn> PWM_MRn;
};
template<class HAL_Traits>
struct CommonPWMRegister {
	typedef HAL_Traits Traits;

	typedef RegisterMock<Traits, &pwm_ir> PWM_IR;
	typedef RegisterMock<Traits, &pwm_tcr> PWM_TCR;
	typedef RegisterMock<Traits, &pwm_tc> PWM_TC;
	typedef RegisterMock<Traits, &pwm_pr> PWM_PR;
	typedef RegisterMock<Traits, &pwm_pc> PWM_PC;
	typedef RegisterMock<Traits, &pwm_mcr> PWM_MCR;
	typedef RegisterMock<Traits, &pwm_ler> PWM_LER;
	typedef RegisterMock<Traits, &pwm_mr0> PWM_MR0;
};
} // namespace Mock
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<SS<HAL::PWM, HAL::Register>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef Mock::CommonPWMRegister<Traits> type;
};
//-------------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 1>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef Mock::CommonPWMnRegister<Traits> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 2>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef Mock::CommonPWMnRegister<Traits> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 3>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef Mock::CommonPWMnRegister<Traits> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 4>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef Mock::CommonPWMnRegister<Traits> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 5>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef Mock::CommonPWMnRegister<Traits> type;
};
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::PWMnRegister, 6>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef Mock::CommonPWMnRegister<Traits> type;
};
} // namespace Generator
//===================================================================
// SPI
//===================================================================
namespace Mock {
extern unsigned long  s0spcr;
extern unsigned long  s0spsr;
extern unsigned long  s0spdr;
extern unsigned long  s0spccr;
extern unsigned long  s0spint;

template<class HAL_Traits>
struct CommonSPIRegister {
	typedef HAL_Traits Traits;

	typedef RegisterMock<Traits, &s0spcr> SPCR;
	typedef RegisterMock<Traits, &s0spsr> SPSR;
	typedef RegisterMock<Traits, &s0spdr> SPDR;
	typedef RegisterMock<Traits, &s0spccr> SPCCR;
	typedef RegisterMock<Traits, &s0spint> SPINT;
};
} // namespace Mock
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::SPIRegister, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::Traits, ProzessorType>, ConfigRepository>
		::type Traits;

	typedef Mock::CommonSPIRegister<Traits> type;
};
} // namespace Generator
//===================================================================
// DAC Todo
//===================================================================
namespace Mock {

} // namespace Mock
//-------------------------------------------------------------------
namespace Generator {

} // namespace Generator

//===================================================================
// VIC
//===================================================================
namespace Mock {
extern unsigned long vicIRQStatus  ;
extern unsigned long vicFIQStatus  ;
extern unsigned long vicRawIntr    ;
extern unsigned long vicIntSelect  ;
extern unsigned long vicIntEnable  ;
extern unsigned long vicIntEnClr   ;
extern unsigned long vicSoftInt    ;
extern unsigned long vicSoftIntClr ;
extern unsigned long vicProtection ;
extern unsigned long vicVectAddr   ;
extern unsigned long vicDefVectAddr;
extern unsigned long vicVectAddr0  ;
extern unsigned long vicVectAddr1  ;
extern unsigned long vicVectAddr2  ;
extern unsigned long vicVectAddr3  ;
extern unsigned long vicVectAddr4  ;
extern unsigned long vicVectAddr5  ;
extern unsigned long vicVectAddr6  ;
extern unsigned long vicVectAddr7  ;
extern unsigned long vicVectAddr8  ;
extern unsigned long vicVectAddr9  ;
extern unsigned long vicVectAddr10 ;
extern unsigned long vicVectAddr11 ;
extern unsigned long vicVectAddr12 ;
extern unsigned long vicVectAddr13 ;
extern unsigned long vicVectAddr14 ;
extern unsigned long vicVectAddr15 ;
extern unsigned long vicVectCntl0  ;
extern unsigned long vicVectCntl1  ;
extern unsigned long vicVectCntl2  ;
extern unsigned long vicVectCntl3  ;
extern unsigned long vicVectCntl4  ;
extern unsigned long vicVectCntl5  ;
extern unsigned long vicVectCntl6  ;
extern unsigned long vicVectCntl7  ;
extern unsigned long vicVectCntl8  ;
extern unsigned long vicVectCntl9  ;
extern unsigned long vicVectCntl10 ;
extern unsigned long vicVectCntl11 ;
extern unsigned long vicVectCntl12 ;
extern unsigned long vicVectCntl13 ;
extern unsigned long vicVectCntl14 ;
extern unsigned long vicVectCntl15 ;

template<class ProzessorType>
struct VICMockRegisters{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef RegisterMock<Traits, &vicIRQStatus    > IRQStatus    ;
	typedef RegisterMock<Traits, &vicFIQStatus    > FIQStatus    ;
	typedef RegisterMock<Traits, &vicRawIntr      > RawIntr      ;
	typedef RegisterMock<Traits, &vicIntSelect    > IntSelect    ;
	typedef RegisterMock<Traits, &vicIntEnable    > IntEnable    ;
	typedef RegisterMock<Traits, &vicIntEnClr     > IntEnClr     ;
	typedef RegisterMock<Traits, &vicSoftInt      > SoftInt      ;
	typedef RegisterMock<Traits, &vicSoftIntClr   > SoftIntClr   ;
	typedef RegisterMock<Traits, &vicProtection   > Protection   ;
	typedef RegisterMock<Traits, &vicVectAddr     > VectAddr     ;
	typedef RegisterMock<Traits, &vicDefVectAddr  > DefVectAddr  ;
	typedef RegisterMock<Traits, &vicVectAddr0    > VectAddr0    ;
	typedef RegisterMock<Traits, &vicVectAddr1    > VectAddr1    ;
	typedef RegisterMock<Traits, &vicVectAddr2    > VectAddr2    ;
	typedef RegisterMock<Traits, &vicVectAddr3    > VectAddr3    ;
	typedef RegisterMock<Traits, &vicVectAddr4    > VectAddr4    ;
	typedef RegisterMock<Traits, &vicVectAddr5    > VectAddr5    ;
	typedef RegisterMock<Traits, &vicVectAddr6    > VectAddr6    ;
	typedef RegisterMock<Traits, &vicVectAddr7    > VectAddr7    ;
	typedef RegisterMock<Traits, &vicVectAddr8    > VectAddr8    ;
	typedef RegisterMock<Traits, &vicVectAddr9    > VectAddr9    ;
	typedef RegisterMock<Traits, &vicVectAddr10   > VectAddr10   ;
	typedef RegisterMock<Traits, &vicVectAddr11   > VectAddr11   ;
	typedef RegisterMock<Traits, &vicVectAddr12   > VectAddr12   ;
	typedef RegisterMock<Traits, &vicVectAddr13   > VectAddr13   ;
	typedef RegisterMock<Traits, &vicVectAddr14   > VectAddr14   ;
	typedef RegisterMock<Traits, &vicVectAddr15   > VectAddr15   ;
	typedef RegisterMock<Traits, &vicVectCntl0    > VectCntl0    ;
	typedef RegisterMock<Traits, &vicVectCntl1    > VectCntl1    ;
	typedef RegisterMock<Traits, &vicVectCntl2    > VectCntl2    ;
	typedef RegisterMock<Traits, &vicVectCntl3    > VectCntl3    ;
	typedef RegisterMock<Traits, &vicVectCntl4    > VectCntl4    ;
	typedef RegisterMock<Traits, &vicVectCntl5    > VectCntl5    ;
	typedef RegisterMock<Traits, &vicVectCntl6    > VectCntl6    ;
	typedef RegisterMock<Traits, &vicVectCntl7    > VectCntl7    ;
	typedef RegisterMock<Traits, &vicVectCntl8    > VectCntl8    ;
	typedef RegisterMock<Traits, &vicVectCntl9    > VectCntl9    ;
	typedef RegisterMock<Traits, &vicVectCntl10   > VectCntl10   ;
	typedef RegisterMock<Traits, &vicVectCntl11   > VectCntl11   ;
	typedef RegisterMock<Traits, &vicVectCntl12   > VectCntl12   ;
	typedef RegisterMock<Traits, &vicVectCntl13   > VectCntl13   ;
	typedef RegisterMock<Traits, &vicVectCntl14   > VectCntl14   ;
	typedef RegisterMock<Traits, &vicVectCntl15   > VectCntl15   ;
};
} // namespace Mock
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<SS<HAL::VIC, HAL::Register>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef Mock::VICMockRegisters<ProzessorType> type;
};
} // namespace Generator

//===================================================================
// Timer
//===================================================================
namespace Mock{
extern unsigned long ir;
extern unsigned long tcr;
extern unsigned long tc;
extern unsigned long pr;
extern unsigned long pc;
extern unsigned long mcr;
extern unsigned long mr0;
extern unsigned long mr1;
extern unsigned long mr2;
extern unsigned long mr3;
extern unsigned long ccr;
extern unsigned long cr0;
extern unsigned long cr1;
extern unsigned long cr2;
extern unsigned long cr3;
extern unsigned long emr;
extern unsigned long ctcr;

template <class ProzessorType>
struct TimerMockRegister {
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef RegisterMock<Traits, &ir>   IR;
	typedef RegisterMock<Traits, &tcr>  TCR;
	typedef RegisterMock<Traits, &tc>   TC;
	typedef RegisterMock<Traits, &pr>   PR;
	typedef RegisterMock<Traits, &pc>   PC;
	typedef RegisterMock<Traits, &mcr>  MCR;
	typedef RegisterMock<Traits, &mr0>  MR0;
	typedef RegisterMock<Traits, &mr1>  MR1;
	typedef RegisterMock<Traits, &mr2>  MR2;
	typedef RegisterMock<Traits, &mr3>  MR3;
	typedef RegisterMock<Traits, &ccr>  CCR;
	typedef RegisterMock<Traits, &cr0>  CR0;
	typedef RegisterMock<Traits, &cr1>  CR1;
	typedef RegisterMock<Traits, &cr2>  CR2;
	typedef RegisterMock<Traits, &cr3>  CR3;
	typedef RegisterMock<Traits, &emr>  EMR;
	typedef RegisterMock<Traits, &ctcr> CTCR;
};
} // namespace LPC21xx
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<SS<NO<HAL::Timer, 0>, HAL::Register>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef Mock::TimerMockRegister<ProzessorType> type;
};
} // namespace Generator

#endif /* TESTREGISTER_H_ */
