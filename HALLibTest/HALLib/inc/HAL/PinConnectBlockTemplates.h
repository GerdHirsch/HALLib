#ifndef __HAL_PINCONNECTBLOCKTEMPLATES_H_
#define __HAL_PINCONNECTBLOCKTEMPLATES_H_


namespace HAL {
//==================================================
// Einfaches PinTemplate für 4 Geräte/Pin
// Berechnet die Maske und die Position der deviceBits
//==================================================
template<unsigned char PinNo, class Register>
struct PinMapper{
	enum { MoveBits = (PinNo % 16) * 2, PinMask = 0x3 << MoveBits };
//	enum { PinMask = 0x3 << (PinNo % 16) * 2 };

	template<unsigned char num>
	struct Device{
		enum { mask = PinMask, bits = (num << MoveBits) };
		static void select(){
			Register::clearBit(mask);
			Register::setBit(bits);
		}
	};
};
} // namespace HAL

#endif /* __HAL_PINCONNECTBLOCKTEMPLATES_H_ */
