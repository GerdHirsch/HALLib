#ifndef __HELPERFUNCTIONS_H__
#define __HELPERFUNCTIONS_H__

#include <Hal/Bits.h>

template<class Port0, class Port1>
struct App{
	static void waitForProgramAbort(){
		// init Abort-Button
		Port0::setToInputMode(Bit14);
		// init LEDs
		Port1::setToOutputMode(Bit16);
		Port1::setToOutputMode(Bit17);

		Port1::write(Bit17);
		Port1::clear(Bit16);

		for(unsigned long l = 0; l < 500000; ++l){
			if(Port0::readPin(Bit14) == 0){
				Port1::clear(Bit17);
				while(true);
			}
		}
		// set everything back to default
		Port1::setToInputMode(Bit16);
		Port1::setToInputMode(Bit17);
		Port1::clear(Bit17);
	}
};

#endif /* __HELPERFUNCTIONS_H__ */
