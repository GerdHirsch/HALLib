/*
 * PCTestRegister.h
 *
 *  Created on: 30.12.2013
 *      Author: Gerd
 */

#ifndef _PCTESTREGISTER_H_
#define _PCTESTREGISTER_H_
#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HALMock/RegisterMock.h>
#include <HALMock/Types.h>

namespace Mock {
// Power Control (PC)
extern unsigned long  PCON_;
extern unsigned long  PCONP_;

template<class ProzessorType>
struct PCRegister{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	// Power Control (PC)
	typedef Mock::RegisterMock<Traits, &PCON_>  PCON;
	typedef Mock::RegisterMock<Traits, &PCONP_>  PCONP;
};
}//namespace Mock

//-------------------------------------------------------------------
namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<
	CS<SS<HAL::PowerControl, HAL::Register>, Mock::Base>,
	Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef Mock::PCRegister<ProzessorType> type;
};
} // namespace Generator

#endif /* _PCTESTREGISTER_H_ */
