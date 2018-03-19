/*
 * GPIOTestRegister.h
 *
 *  Created on: 30.12.2013
 *      Author: Gerd
 */

#ifndef GPIOTESTREGISTER_H_
#define GPIOTESTREGISTER_H_
#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HALMock/RegisterMock.h>
#include <HALMock/Types.h>
//===================================================================
// GPIOPort
//===================================================================
namespace Mock {
extern unsigned long ioPin;
extern unsigned long ioSet;
extern unsigned long ioDir;
extern unsigned long ioClr;

template<class ProzessorType>
struct GPIOPortRegisters{
	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;

	typedef Mock::RegisterMock<Traits, &ioPin> IOPIN;
	typedef Mock::RegisterMock<Traits, &ioSet> IOSET;
	typedef Mock::RegisterMock<Traits, &ioDir> IODIR;
	typedef Mock::RegisterMock<Traits, &ioClr> IOCLR;
};
} // namespace Mock
//-------------------------------------------------------------------
namespace Generator {
//GPIOPort
template<class Origin, class ConfigRepository>
struct Component<
	CS<SS<NO<HAL::GPIO, 0>, HAL::Register>, Mock::Base>,
	Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef Mock::GPIOPortRegisters<ProzessorType> type;
};
template<class Origin, class ConfigRepository>
struct Component<
	CS<SS<NO<HAL::GPIO, 1>, HAL::Register>, Mock::Base>,
	Origin, ConfigRepository>
{
	typedef typename Origin::Selector ProzessorType;
	typedef Mock::GPIOPortRegisters<ProzessorType> type;
};
} // namespace Generator



#endif /* GPIOTESTREGISTER_H_ */
