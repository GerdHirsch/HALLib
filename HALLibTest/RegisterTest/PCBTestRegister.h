/*
 * TestRegisterPCB.h
 *
 *  Created on: 20.12.2013
 *      Author: Gerd
 */

#ifndef TESTREGISTERPCB_H_
#define TESTREGISTERPCB_H_

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HALMock/RegisterMock.h>
#include <HALMock/Types.h>
//===================================================================
// PinConnectBlock
//===================================================================
namespace Mock {
extern unsigned long pinsel0;
extern unsigned long pinsel1;
extern unsigned long pinsel2;

template<class ProzessorType,
		 class HWTraits = typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type>
struct PCBMockRegisters{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef typename HWTraits::ValueType ValueType;
	// experiment, statt globaler statische pinsel zu nehmen und mit dem
	// richtigen Typ aus Traits zu deklarieren
	// Tests schlugen fehl, die static pinsel wurden nicht richtig verwendet
	// auch wenn der speicher für die static Variablen im PinConnectBlockTest.cpp
	// Definiert wurden, Warum?
	// build war ok, kein linker error
//	static ValueType pinsel0;
//	static ValueType pinsel1;
//	static ValueType pinsel2;

	typedef Mock::RegisterMock<Traits, &pinsel0> PinSel_0;
	typedef Mock::RegisterMock<Traits, &pinsel1> PinSel_1;
	typedef Mock::RegisterMock<Traits, &pinsel2> PinSel_2;
};
// speicher für static Variablen
//template<class ProzessorType, class HWTraits>
//typename HWTraits::ValueType PCBMockRegisters<ProzessorType, HWTraits>::pinsel0 = 0;
//template<class ProzessorType, class HWTraits>
//typename HWTraits::ValueType PCBMockRegisters<ProzessorType, HWTraits>::pinsel1 = 0;
//template<class ProzessorType, class HWTraits>
//typename HWTraits::ValueType PCBMockRegisters<ProzessorType, HWTraits>::pinsel2 = 0;



} // namespace Mock
//-------------------------------------------------------------------
namespace Generator {
//PinConnectBlock
template<class Origin, class ConfigRepository>
struct Component<
	CS<SS<HAL::PinConnectBlock, HAL::Register>, Mock::Base>,
	Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef Mock::PCBMockRegisters<ProzessorType> type;
};
} // namespace Generator



#endif /* TESTREGISTERPCB_H_ */
