/*
 * ADCTestRegister.h
 *
 *  Created on: 30.12.2013
 *      Author: Gerd
 */

#ifndef ADCTESTREGISTER_H_
#define ADCTESTREGISTER_H_

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HALMock/RegisterMock.h>
#include <HALMock/Types.h>


//===================================================================
// ADC
//===================================================================
namespace Mock {
// ADCRegister
extern unsigned long ad_cr;
extern unsigned long ad_gdr;
extern unsigned long ad_stat;
extern unsigned long ad_inten;
// für parallele tests des AD ad_dr1..7 definieren
extern unsigned long ad_drn;

template<class ProzessorType, class AD_DRn_>
struct CommonADCRegister{
//	typedef typename Generator::SD::Create<BoardType, HAL::Traits>::type Traits;
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef Mock::RegisterMock<Traits, &ad_cr> 		AD_CR;
	typedef Mock::RegisterMock<Traits, &ad_gdr> 	AD_GDR;
	typedef Mock::RegisterMock<Traits, &ad_stat> 	AD_STAT;
	typedef Mock::RegisterMock<Traits, &ad_inten> 	AD_INTEN;

	typedef AD_DRn_ AD_DRn;
};
} // namespace Mock
//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
// ADC05 existiert nur bei 3x
struct Component<CS<SS<NO<HAL::ADC, 0>, HAL::Register>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef typename Create<CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef Mock::RegisterMock<Traits, &Mock::ad_drn> AD_DRn;

	typedef Mock::CommonADCRegister<ProzessorType, AD_DRn> type;
};
//-------------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<SS<NO<HAL::ADC, 1>, HAL::Register>, Mock::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef typename Create<CS<SS<NO<HAL::ADC, 0>, HAL::Register>, ProzessorType> >::type type;
};
//-------------------------------------------------------------------
} // namespace Generator

#endif /* ADCTESTREGISTER_H_ */
