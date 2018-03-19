//#ifndef VIC_H
//#define VIC_H
//
//#include <HAL/Bits.h>
//
//
//struct VIC{
//	typedef RegisterType<ActualBoardType>::type *Register;
//
////****************************************************
//// VIC_IntEnable
////****************************************************
//	static void enableTimer0Interrupt() {
//	 	*reinterpret_cast<Register>(VIC_IntEnable) |= Bit4;
//	}
//	static void enableTimer1Interrupt() {
//	 	*reinterpret_cast<Register>(VIC_IntEnable) |= Bit5;
//	}
//	static void enableEINT0Interrupt() {
//	 	*reinterpret_cast<Register>(VIC_IntEnable) |= Bit14;
//	}
//	static void enableAD0Interrupt() {
//	 	*reinterpret_cast<Register>(VIC_IntEnable) |= Bit18;
//	}
//
////****************************************************
//// VIC_VectAddr0
////****************************************************
//	static void setVectAddr0(insigned long adr) {
//	 	*reinterpret_cast<Register>(VIC_VectAddr0) = adr;
//	}
////****************************************************
//// VIC_VectCntl0
////****************************************************
//	static void setVectAddr0(insigned long adr) {
//	 	*reinterpret_cast<Register>(VIC_VectAddr0) = adr;
//	}
//
//};
//
//#endif // VIC_H
