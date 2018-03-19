#ifndef MEMORYMAPPEDREGISTER_H_
#define MEMORYMAPPEDREGISTER_H_

namespace HAL {
// =======================================================
// RegisterAddress
// Abstrahiert die Konstante eines Memory Mapped Registers,
// so dass wahlweise für Testzwecke die Adresse einer
// externen Variablen verwendet werden kann
// =======================================================
template<	typename Traits,
			typename Traits::RegisterAddressType address
		>
struct RegisterAddress{
	enum{value=address};
};
// =======================================================
// MemoryMappedRegister
// Abstrahiert ein im Memory gemapptes Prozessorregister
// =======================================================
template<	class HAL_Traits,
			class Address, // RegisterAddress
			typename RegisterType_ = typename HAL_Traits::RegisterType>
struct MemoryMappedRegisterImpl
{
//	typedef typename HAL_Traits::RegisterAddressType RegisterAddressType;
	typedef RegisterType_ RegisterType;
	typedef RegisterType* RegisterPointer;
	typedef typename HAL_Traits::ValueType ValueType;

//	constexpr static RegisterPointer address =
//			reinterpret_cast<RegisterPointer>(Address::value);


	static void setBit(ValueType b){
//		*address |= b;
		*reinterpret_cast<RegisterPointer>(Address::value) |= b;
	}
	static void set(ValueType value){
//		*address = value;
		*reinterpret_cast<RegisterPointer>(Address::value) = value;
	}
	static void clearBit(ValueType b){
//		*address &= ~b;
		*reinterpret_cast<RegisterPointer>(Address::value) &= ~b;
	}

	static void clear(){
//		*address = static_cast<ValueType >(0x0);
		*reinterpret_cast<RegisterPointer>(Address::value)
			= static_cast<ValueType >(0x0);
	}

	static ValueType readBit(ValueType b){
//		return *address & b;
		return *reinterpret_cast<RegisterPointer>(Address::value) & b;
	}
	static ValueType read(){
//		return *address;
		return *reinterpret_cast<RegisterPointer>(Address::value);
	}
};

template<	class HW_Traits,
			typename HW_Traits::RegisterAddressType address,
			typename RegisterType_ = typename HW_Traits::RegisterType>
struct MemoryMappedRegister
: MemoryMappedRegisterImpl<HW_Traits, HAL::RegisterAddress<HW_Traits, address>, RegisterType_>
{};
} // namespace HAL
#endif /* MEMORYMAPPEDREGISTER_H_ */
