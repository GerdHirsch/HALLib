#ifndef __LPC21xx_ADC_H
#define __LPC21xx_ADC_H

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>

/*!
 * \file ADC.h
 *
 * \author Gerd Hirsch
 *
 * Class to use ADC on LPC21xx.
 */

namespace LPC21xx
{
template<class Registers, unsigned char deciceNo>
struct ADC;
}

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC, 0>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<SS<NO<HAL::ADC, 0>, HAL::Register>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type ADCRegister;

	typedef LPC21xx::ADC<ADCRegister, 18> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::ADC, 1>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS< SS< NO<HAL::ADC, 1>, HAL::Register>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<ADCRegister, 21> type;
};
} // namespace Generator

namespace LPC21xx {

template<class Registers, unsigned char deciceNo_>
struct ADC{
	typedef typename Registers::Traits Traits;
	typedef typename Traits::RegisterType RegisterType;

	enum { 	DATABITS = (Bit15|Bit14|Bit13|Bit12|Bit11|Bit10|Bit9|Bit8|Bit7|Bit6),
			adOperationalBit = Bit21,
			adCLKDivisorBit = (17 << 8)//Bit10
	};

	template<int val, class Register_>
	struct ADSourceInfo{
		typedef Register_ Register;
		enum { value = Bit0 << val, deviceNo = deciceNo_ };
	};
	typedef ADSourceInfo<0, typename Registers::DR0> AD_0;
	typedef ADSourceInfo<1, typename Registers::DR1> AD_1;
	typedef ADSourceInfo<2, typename Registers::DR2> AD_2;
	typedef ADSourceInfo<3, typename Registers::DR3> AD_3;
	typedef ADSourceInfo<4, typename Registers::DR4> AD_4;
	typedef ADSourceInfo<5, typename Registers::DR5> AD_5;
	typedef ADSourceInfo<6, typename Registers::DR6> AD_6;
	typedef ADSourceInfo<7, typename Registers::DR7> AD_7;
	typedef ADSourceInfo<8, typename Registers::GDR> Global;

	template<int val>
	struct StartOption{
		enum { value = val };
	};

	typedef StartOption<0> Stop;
	typedef StartOption<Bit16> Burst;
	typedef StartOption<Bit24> StartNow;
	typedef StartOption<Bit25> StartOnP0_16;
	typedef StartOption<Bit25|Bit24> StartOnP0_22;
	typedef StartOption<Bit26> StartOnMAT0_1;
	typedef StartOption<Bit26|Bit24> StartOnMAT0_3;
	typedef StartOption<Bit26|Bit25> StartOnMAT1_0;
	typedef StartOption<Bit26|Bit25|Bit24> StartOnMAT1_1;

	template<class ADSrcInfo>
	static void select(){
		Registers::CR::setBit(ADSrcInfo::value);
	}
	template<class ADSrcInfo>
	static void enableInterruptOn(){
		Registers::INTEN::setBit(ADSrcInfo::value);
	}

	template<class StartOpt>
	static void conversion(){
		Registers::CR::clearBit(Bit26|Bit25|Bit24|Bit16);
		Registers::CR::setBit(StartOpt::value);
	}
	template<class StartOpt>
	static void globalConversion(){
		Registers::GSR::clearBit(Bit26|Bit25|Bit24|Bit16);
		Registers::GSR::setBit(StartOpt::value);
	}

	static void setStartOnFallingEdge(bool falling = true){
		if(falling)	Registers::CR::setBit(Bit27);
		else Registers::CR::clearBit(Bit27);
	}


	template<class ADSrcInfo>
	static RegisterType read(){
		return ADSrcInfo::Register::read();
//		return (ADSourceInfo::Register::read() & DATABITS) >> 6;
	}

	template<class ADSrcInfo>
	static bool read(unsigned long &value) {
		value = ADSrcInfo::Register::read();

		if ((value & Bit31) == 0)
			return false;

		value &= DATABITS;
		value >>= 6;
		return true;
	}

	// TODO: übedenken
	static void selectCLKDivisor() {
		Registers::CR::setBit(adCLKDivisorBit);
	}

	static void setOperationalMode() {
		Registers::CR::setBit(adOperationalBit);
	}

	static void setPowerDownMode() {
		Registers::CR::clearBit(adOperationalBit);
	}
/*
AD0.1 schreibt dass Ergebnis der Konvertierung in Bit6 bis Bit15 vom AD0_DR1 Register
Das Ende der Konvertierung wird durch 1 in Bit31 signalisiert
*/
/*
read(long &value) liefert true wenn die Konvertierung abgeschlossen ist.
in value steht der Wert der Konvertierung.
Ist die Konvertierung noch nicht abgeschlossen, wird false geliefert,
der Wert in value ist ungültig.
*/
/*	static bool read(unsigned long &value) {
		value = AD_DRn::read();

		if ((value & Bit31) == 0)
			return false;

		value &= DATABITS;
		value >>= 6;
		return true;
	}
//=========================================================
// AD0_CR
//=========================================================
  	static void selectAD() {
		AD_CR::clearBit(0xFF);
		AD_CR::setBit(adBit);
	}
	static void selectCLKDivisor() {
		AD_CR::setBit(adCLKDivisorBit);
	}
	// ADC wird aktiviert (nicht im PowerDownMode)
	static void setOperationalMode() {
		AD_CR::setBit(adOperationalBit);
	}
	static void setPowerDownMode() {
		AD_CR::clearBit(adOperationalBit);
	}
	static void startConversion() {
		AD_CR::clearBit(Bit26|Bit25|Bit24);
		AD_CR::setBit(Bit24);
	}
	static void stopConversion() {
		AD_CR::clearBit(Bit26|Bit25|Bit24);
	}
	static bool isConverting(){
	 	return AD_DRn::readBit(Bit31) == 0;
	}*/
};
} // end namespace LPC21xx

#endif // __LPC21xx_ADC_H
