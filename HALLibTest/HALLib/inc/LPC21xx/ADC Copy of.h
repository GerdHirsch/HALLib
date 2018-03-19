#ifndef __LPC21xx_ADC_H
#define __LPC21xx_ADC_H

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Bits.h>
#include <LPC21xx/ComponentTypes.h>

namespace LPC21xx
{
template<	class HAL_Traits, class ADCRegister,
			typename HAL_Traits::RegisterType adBit>
struct ADC;
}
namespace Generator {
//---------------------------------------------------------------------
// ADC1
//---------------------------------------------------------------------
template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD0, 1>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository>::type Traits;

	typedef CS<NO<HAL::ADC0Register, 1>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit1> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD0, 2>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC0Register, 2>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit2> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD0, 3>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC0Register, 3>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit3> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD0, 4>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC0Register, 4>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit4> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD0, 6>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC0Register, 6>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit6> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD0, 7>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC0Register, 7>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit7> type;
};
//---------------------------------------------------------------------
// ADC1
//---------------------------------------------------------------------

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD1, 0>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository>::type Traits;

	typedef CS<NO<HAL::ADC1Register, 0>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit0> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD1, 1>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository>::type Traits;

	typedef CS<NO<HAL::ADC1Register, 1>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit1> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD1, 2>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC1Register, 2>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit2> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD1, 3>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC1Register, 3>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit3> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD1, 4>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC1Register, 4>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit4> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD1, 5>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC1Register, 5>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit5> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD1, 6>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC1Register, 6>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit6> type;
};

template<class Origin, class ConfigRepository>
struct Component<CS<NO<HAL::AD1, 7>, LPC21xx::Base>, Origin, ConfigRepository>
{
	typedef typename Origin::template getSelector<>::type ProzessorType;

	typedef CS<HAL::Traits, ProzessorType> TraitsContext;
	typedef typename Create<TraitsContext, ConfigRepository, TraitsContext>::type Traits;

	typedef CS<NO<HAL::ADC1Register, 7>, ProzessorType> RegisterContext;
	typedef typename Create<RegisterContext, ConfigRepository, RegisterContext>::type ADCRegister;

	typedef LPC21xx::ADC<Traits, ADCRegister, Bit7> type;
};
} // namespace Generator

namespace LPC21xx
{

template<	class HAL_Traits, class ADCRegister,
			typename HAL_Traits::RegisterType adBit>
struct ADC{
	typedef typename ADCRegister::AD_CR AD_CR;
	typedef typename ADCRegister::AD_GDR AD_GDR;
	typedef typename ADCRegister::AD_STAT AD_STAT;
	typedef typename ADCRegister::AD_INTEN AD_INTEN;
	typedef typename ADCRegister::AD_DRn AD_DRn;

	enum { 	DATABITS = (Bit15|Bit14|Bit13|Bit12|Bit11|Bit10|Bit9|Bit8|Bit7|Bit6),
			adOperationalBit = Bit21,
			adCLKDivisorBit = Bit10
	};
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
	static bool read(unsigned long &value) {
		value = AD_DRn::read();

		if ((value & Bit31) == 0)
			return false;

		value &= DATABITS;
		value >>= 6;
		return true;
	}

//****************************************************
// AD0_CR
//****************************************************
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
	}
};
} // end namespace LPC21xx

#endif // __LPC21xx_ADC_H
