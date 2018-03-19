#ifndef __EA_LPC2138_EduBoard_DISPLAY_HAL_H__
#define __EA_LPC2138_EduBoard_DISPLAY_HAL_H__

#include <cmath>

#include <Generator/CreateComponent.h>

#include <CommonComponents/CommonComponentTypes.h>

#include <Education_Board/Boards.h>

#include <HAL/Typedefs.h>
#include <HAL/Point.h>

/******************************************************************************
 * Typedefs and defines
 *****************************************************************************/
#define LCD_CMD_SWRESET   0x01
#define LCD_CMD_BSTRON    0x03
#define LCD_CMD_SLEEPIN   0x10
#define LCD_CMD_SLEEPOUT  0x11
#define LCD_CMD_INVON     0x21
#define LCD_CMD_SETCON    0x25
#define LCD_CMD_DISPON    0x29
#define LCD_CMD_CASET     0x2A
#define LCD_CMD_PASET     0x2B
#define LCD_CMD_RAMWR     0x2C // (Bit5|Bit3|Bit2)
#define LCD_CMD_RGBSET    0x2D // (Bit5|Bit3|Bit2|Bit0)
#define LCD_CMD_MADCTL    0x36
#define LCD_CMD_COLMOD    0x3A

#define MADCTL_HORIZ      0x48
#define MADCTL_VERT       0x68

#define LCD_CS     0x00000080
#define LCD_CLK    0x00000010
#define LCD_MOSI   0x00000040


/* 
 * DisplayHAL unterste Schicht über dem
 * physikalischen Display
 * konfiguriert die HAL (Controller) und
 * die notwendigen Geräte (PinConnectBlock, GPIO, PWM)
 */
 namespace EA_LPC2138_EduBoard_Components{
	template<class HAL_> class DisplayHAL;
 }

namespace Generator {

template<class Origin, class ConfigRepository>
struct Component<DD<CommonComponents::Display, CS<Boards::EA_LPC2138_EduBoard, LPC21xx::Base> >, Origin, ConfigRepository>
{

	typedef typename ConfigRepository::Platform::prozessor_type prozessor_type;
//	typedef typename ConfigRepository::Controller Controller;
//	typedef typename Generator::SD::Create<prozessor_type, HAL::Layer>::type Hal;

	typedef typename Generator::Create<prozessor_type>::type Hal;
	typedef EA_LPC2138_EduBoard_Components::DisplayHAL<Hal> type;
};
//} // namespace DD
//namespace SD {
//
////template<class Origin, class ConfigRepository>
////struct Component<Boards::EA_LPC2138_EduBoard, CommonComponents::DisplayHAL, Origin, ConfigRepository>
////{
////	typedef typename ConfigRepository::Controller Controller;
////
////	typedef typename Create<Controller, HAL::Layer>::type Hal;
////	typedef EA_LPC2138_EduBoard_Components::DisplayHAL<Hal> type;
////};
} // namespace Generator


namespace EA_LPC2138_EduBoard_Components{

template<class HAL_>
class DisplayHAL{

public:
	typedef DisplayHAL<HAL_> type;
	type& getInstance(){
	 	static type instance;
		return instance;
	}

	typedef HAL_ Hal;

	typedef typename HAL::U8 U8;  // Wertebereich der x/y Koordinaten
	typedef typename HAL::U8 size_t;  // Wertebereich der x/y Koordinaten
	typedef typename HAL::Point<size_t> Point;
	typedef typename HAL::U8 Color;

	//die physikalische Größe des Displays
	enum { WIDTH=130, HEIGHT=130 };
	
	//Todo: aufräumen oder entfernen, wird von Höheren Schichten verwaltet
	// oder als Grundset von Farben stehen lassen
	enum {

		Red = 0xF8, Red2 = 0xF9,
		Green = 0x07, Green2 = 0x04, Green3 = 0x0F,
		Blue = 0x00, Blue2 = 0x05,

		White = Red|Green|Blue,
		White2 = 0xF7,
		Gray = 0xD7,

		Yellow = 0xFF, Yellow2 = 0xF7,
		Black = 0x00,
		Magenta = 0xF8,
		Cyan = 0x7F,
		Brown = 0x84
	};
//	enum {
//
//		Red = 0xF800, Red2 = 0xF9E0,
//		Green = 0x07C0, Green2 = 0x0400, Green3 = 0x0FF0,
//		Blue = 0x003E, Blue2 = 0x051F,
//
//		White = Red|Green|Blue,
//		White2 = 0xF7BC,
//		Gray = 0xD718,
//
//		Yellow = 0xFFE0, Yellow2 = 0xF700,
//		Black = 0x0000,
//		Magenta = 0xF81E,
//		Cyan = 0x7FFF,
//		Brown = 0x8400
//	};
	
private:
	// HW Geräte
	typedef typename Hal::GPIO0 Port0;
	typedef typename Hal::GPIO1 Port1;
	typedef typename Hal::PinConnectBlock PCB;

	typedef typename PCB::P0_4::GPIO GPIO0_4;
	typedef typename PCB::P0_5::GPIO GPIO0_5;
	typedef typename PCB::P0_6::GPIO GPIO0_6;

	typedef typename PCB::P0_4::SCK0_SPI0 SCK0;
	typedef typename PCB::P0_5::MISO0_SPI0 MISO0;
	typedef typename PCB::P0_6::MOSI0_SPI0 MOSI0;

	typedef typename Hal::SPI SPI;

//	typedef typename Hal::PWM PWM;
protected:
	DisplayHAL();
	
	//======================================================
	// HW spezifischen Primitiven
	//======================================================
public:	
	/*
	 * stellt die Helligkeit des Displays ein
	 * 0 bis 100 Prozent
	 */
	static void setBrightness(unsigned char brightness);
	// Brightness between 0 and 100%
	static void backlightOn(unsigned char brightness);
	/*
	 * Füllt den gesamten Sreen mit color
	 */
//	static void clearScreen( Color color ){
//
//	}
	/*
	 * Initialisiert/konfiguriert die HAL,
	 * setzt die GPIOPorts,
	 * initialisiert den LCD Bus
	 *
	 * Todo: eventuell static
	 */
	static void init();
	static void initSPI();
	/*
	 * wählt einen Bereich aus, in dem
	 * für alle Pixel mit setPixel(Color)
	 * ein Farbwert angegeben werden muss.
	 */
	static void setArea( U8 x0, U8 y0, U8 x1, U8 y1 );
	/*
	 * schreibt an die aktuelle Positioin mit writeByte
	 * einen Farbwert (2 Bytes)
	 */
	static void setPixel(Color color);
	static void setContrast(unsigned char contrast);
	//======================================================

	static void selectLCD(bool select);
	static void sendData(Color data);
	static void sendCommand(Color data);
	template <typename T>
	static void swap(T& v1, T& v2){
	 	v1^=v2;
		v2^=v1;
		v1^=v2;
	}
	// Low Level Register Operations
	static void writeByte(bool isData, Color Data );
};
//=====================================================================

//---------------------------------------------------------------------------------
//*****************************************************
// protected
//*****************************************************
template<class HAL_>
DisplayHAL<HAL_>
::DisplayHAL()
{
	init();
}

//*****************************************************
// private ctor helpers
//*****************************************************
template<class HAL_>
void 
DisplayHAL<HAL_>
::init() {
	//init SPI interface
	initSPI();

	//select controller
	selectLCD(true);

	sendCommand(LCD_CMD_SWRESET);

//	osSleep(1);
	sendCommand(LCD_CMD_SLEEPOUT);
	sendCommand(LCD_CMD_DISPON);
	sendCommand(LCD_CMD_BSTRON);
//	osSleep(1);

	sendCommand(LCD_CMD_MADCTL);   //Memory data acces control
	sendData(MADCTL_HORIZ);    //X Mirror and BGR format
	sendCommand(LCD_CMD_COLMOD);   //Colour mode
	sendData(0x02);            //256 colour mode select
//	sendData(0xff);            //2 byte colour mode select (versuch)
	sendCommand(LCD_CMD_INVON);    //Non Invert mode

	sendCommand(LCD_CMD_RGBSET);   //LUT write
	sendData(0);               //Red
	sendData(2);
	sendData(4);
	sendData(6);
	sendData(9);
	sendData(11);
	sendData(13);
	sendData(15);
	sendData(0);               //Green
	sendData(2);
	sendData(4);
	sendData(6);
	sendData(9);
	sendData(11);
	sendData(13);
	sendData(15);
	sendData(0);               //Blue
	sendData(6);
	sendData(10);
	sendData(15);

	//deselect controller
	selectLCD(false);

	setContrast(56);

	//clearScreen(Blue);
}

template<class HAL_>
void
DisplayHAL<HAL_>
::initSPI(void)
{
	//make SPI slave chip select an output and set signal high
	Port0::setToOutputMode(LCD_CS | LCD_CLK | LCD_MOSI); // P0_4,6,7

	//deselect controller
	selectLCD(false);

	//connect SPI bus to IO-pins
	SCK0::select();
	MISO0::select();
	MOSI0::select();

	//initialize SPI interface
//	SPI::setTransferRate(SPI::TransferBits_8());
	SPI::setClockRate(0x8);
	SPI::setMasterMode();
}
template<class HAL_>
void
DisplayHAL<HAL_>
::backlightOn(unsigned char brightness){

}
//---------------------------------------------------


template<class HAL_>
void
DisplayHAL<HAL_>
::sendCommand(Color data)
{
	writeByte(0, data);
}


/*****************************************************************************
 *
 * Description:
 *    Send data byte to LCD controller
 *
 ****************************************************************************/
template<class HAL_>
void
DisplayHAL<HAL_>
::sendData(Color data)
{
	writeByte(1, data);
}

/*****************************************************************************
 *
 * Description:
 *    Select/deselect LCD controller (by controlling chip select signal)
 *
 ****************************************************************************/
template<class HAL_>
void
DisplayHAL<HAL_>
::selectLCD(bool select)
{
	if (select)
		Port0::clear(Bit7);
	else
		Port0::write(Bit7);
}

template<class HAL_>
void DisplayHAL<HAL_>
::writeByte(bool isData, Color data ){
	//disable SPI
	Port0::clear(LCD_CLK); // P0_4

	GPIO0_4::select();
	GPIO0_5::select();
	GPIO0_6::select();

	if (isData)
		Port0::write(LCD_MOSI);   //set MOSI P0_6
	else
		Port0::clear(LCD_MOSI);   //reset MOSI P0_6

	//Set clock high
	Port0::write(LCD_CLK);

	//Set clock low
	Port0::clear(LCD_CLK);

	//Enable SPI again
	//initialize SPI interface
	SPI::setClockRate(8);
	SPI::setMasterMode();

	//connect SPI bus to IO-pins
	SCK0::select();
	MISO0::select();
	MOSI0::select();

	//send byte
	SPI::writeData(data);
	while(!SPI::isTransferComplete());
}

template<typename HAL>
void DisplayHAL<HAL>
::setPixel(Color color){
	selectLCD(true);

	sendData(color);

	selectLCD(false);
}

//*****************************************************
// 
//*****************************************************
template<class HAL_>
void 
DisplayHAL<HAL_>
::setArea( U8 x0, U8 y0, U8 x1, U8 y1 ){
	selectLCD(true);

	if(x0 > x1) swap(x0, x1);
	if(y0 > y1) swap(y0, y1);

	--x1; --y1;

	sendCommand(LCD_CMD_CASET);    //set X
	sendData(x0+1);
	sendData(x1+1);

	writeByte(0, LCD_CMD_PASET);    //set Y
	sendData(y0+1);
	sendData(y1+1);

	sendCommand(LCD_CMD_RAMWR);

	selectLCD(false);
}
template<class HAL_>
void
DisplayHAL<HAL_>
::setContrast(unsigned char contrast) //vary between 0 - 127
{
	//select controller
	selectLCD(true);

	//set contrast cmd.
	sendCommand(LCD_CMD_SETCON);
	sendData(contrast);

	//deselect controller
	selectLCD(false);
}
} // end namespace GraphicDevice



#endif // __EA_LPC2138_EduBoard_DISPLAY_HAL_H__
