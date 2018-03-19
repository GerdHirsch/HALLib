#ifndef SPILPC21XX_H_
#define SPILPC21XX_H_

#include <Generator/CreateComponent.h>
#include <HAL/MemoryMappedRegister.h>
#include <HAL/Bits.h>

#include <LPC21xx/Traits.h>
#include <LPC21xx/Types.h>

namespace LPC21xx {
template<class SPIRegister>
struct SPI;

template<int val>
struct TransferType{
	enum { BitsPerTransfer = val<<8 };
};
} // namespace LPC21xx

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<HAL::SPI, LPC21xx::Base>, Origin, ConfigRepository> {
	typedef typename Origin::template getSelector<>::type ProzessorType;
	typedef typename Create<CS<HAL::SPIRegister, ProzessorType>, ConfigRepository>
			::type SPIRegister;

	typedef LPC21xx::SPI<SPIRegister> type;
};
} // namespace Generator

namespace LPC21xx{
template<class SPIRegister>
struct SPI{
	enum{ deviceNo = 10 };

	typedef typename SPIRegister::SPCR SPCR;
	typedef typename SPIRegister::SPSR SPSR;
	typedef typename SPIRegister::SPDR SPDR;
	typedef typename SPIRegister::SPCCR SPCCR;
	typedef typename SPIRegister::SPINT SPINT;

	typedef TransferType<8>  TransferBits_8;
	typedef TransferType<9>  TransferBits_9;
	typedef TransferType<10> TransferBits_10;
	typedef TransferType<11> TransferBits_11;
	typedef TransferType<12> TransferBits_12;
	typedef TransferType<13> TransferBits_13;
	typedef TransferType<14> TransferBits_14;
	typedef TransferType<15> TransferBits_15;
	typedef TransferType<0>  TransferBits_16;

	template<class BitsPerTransfer>
	static void setTransferRate(BitsPerTransfer bPT){
		SPCR::setBit(Bit2);
		SPCR::setBit(bPT.BitsPerTransfer);
	}
	static void setTransferRate(TransferBits_8 bPT){
		SPCR::clearBit(Bit2);
	}
	// set to 0x8 for lcd
	/*
	 * The value of clockRate must always be an
	 * even number. As a result, bit 0 must always be 0.
	 * The value of the register must also
	 * always be greater than or equal to 8.
	 * Violations of this can result in unpredictable behavior.
	 */
	static void setClockRate(unsigned char clockRate){
		clockRate &= ~Bit0;
		clockRate = clockRate < 7 ? 0x8 : clockRate;
		SPCCR::clearBit(Bit1|Bit2|Bit3|Bit4|Bit5|Bit6|Bit7);
		SPCCR::setBit(clockRate);
	}

	static void writeData(unsigned char data){ SPDR::set(data);	}
	// Symbol: CPHA
	static void sampleOnTrailingEdge(){ SPCR::setBit(Bit3); }
	static void sampleOnLeadingEdge(){ SPCR::clearBit(Bit3); }
	// Symbol: CPOL
	static void setSCKActivLow(){ SPCR::setBit(Bit4); }
	static void setSCKActivHigh(){ SPCR::clearBit(Bit4); }
	// Symbol: MSTR
	static void setMasterMode(){ SPCR::setBit(Bit5);}
	static void setSlaveMode(){ SPCR::clearBit(Bit5);}
	// Symbol: LSBF
	static void transferLSBFirst(){ SPCR::setBit(Bit6);	}
	static void transferMSBFirst(){ SPCR::clearBit(Bit6); }
	// Symbol: SPIE
	static void enableInterrupt(){ SPCR::setBit(Bit7); }
	static void disableInterrupt(){	SPCR::clearBit(Bit7); }


	// Symbol: ABRT
	static bool isSlaveAbort(){	return SPSR::readBit(Bit3) != 0; }
	// Symbol: MODF
	static bool isModeFault(){ return SPSR::readBit(Bit4) != 0;	}
	// Symbol: ROVR
	static bool isReadOverrun(){ return SPSR::readBit(Bit5) != 0; }
	// Symbol: WCOL
	static bool isWriteCollision(){	return SPSR::readBit(Bit6) != 0; }
	// Symbol: SPIF
	static bool isTransferComplete(){ return SPSR::readBit(Bit7) != 0; }
};
}

#endif /* SPILPC21XX_H_ */
