#ifndef REGISTERMOCK_H_
#define REGISTERMOCK_H_

#include <HAL/MemoryMappedRegister.h>

namespace Mock
{
template<	typename Traits,
			typename Traits::RegisterType* pointer
		>
struct PointerRegisterAddress{
	typedef typename Traits::RegisterType* AddressType;
	constexpr static AddressType value=pointer;
};

//template<	typename Traits,
//			typename Traits::RegisterType* pointer>
//typename Traits::RegisterType*
//PointerRegisterAddress<Traits, pointer>::value(pointer);

template<class HAL_Traits, typename HAL_Traits::ValueType * address>
struct RegisterMock
: HAL::MemoryMappedRegisterImpl<HAL_Traits, PointerRegisterAddress<HAL_Traits, address> >
{};

} // namespace Mock

#endif /* REGISTERMOCK_H_ */
