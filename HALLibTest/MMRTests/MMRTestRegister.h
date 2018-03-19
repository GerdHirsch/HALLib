#ifndef __MMR_TESTMOCKREGISTER_H_
#define __MMR_TESTMOCKREGISTER_H_

#include "../HALLibTestApp.h"

//===================================================================
// Test für das TestMockRegister
//===================================================================
namespace Mock {
extern unsigned long testMockRegister;

template<class ProzessorType, class Selector, class Origin, class ConfigRep>
struct TestMockRegister : Generator::TestImpl<Selector, Origin, ConfigRep> {

	typedef typename Generator::Create<Generator::CS<HAL::Traits, ProzessorType> >::type Traits;
	typedef typename Traits::RegisterType RegType;
	typedef Mock::RegisterMock<Traits, &testMockRegister> TestRegister;
};
} // namespace Mock
//-------------------------------------------------------------------
namespace Generator {
//TestMockRegister
template<class Origin, class ConfigRep>
struct Component<CS<Mock::Register, Mock::Base>, Origin, ConfigRep>
{
	typedef CS<Mock::Register, Mock::Base> Selector;
	typedef Mock::TestMockRegister<typename Origin::Selector, Selector, Origin, ConfigRep> type;
};
} // namespace Generator

#endif /* __MMR_TESTMOCKREGISTER_H_ */
