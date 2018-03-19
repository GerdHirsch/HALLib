#ifndef __EVALBOARD_ZEA7_2_DISPLAY_HAL_H__
#define __EVALBOARD_ZEA7_2_DISPLAY_HAL_H__

/*
|                     OO/Cpp © by Gerd Hirsch                 |
|                      		2011							|
|                    www.gerdhirsch.de                      |
*/
#include <cmath>

#include <Generator/CreateComponent.h>

#include <CommonComponents/CommonComponentTypes.h>

#include <HAL/Typedefs.h>
#include <HAL/Point.h>
#include <EvalBoard_ZEA7_2/Boards.h>

#define LCD_BUS_RST	(1<<3)
#define LCD_BUS_CS	(1<<2)
#define LCD_BUS_RD	(1<<22)
// Port 1
#define LCD_BUS_RS	(1<<25)
#define LCD_BUS_RW	(1<<24)
#define LCD_BUS_DAT	0x00FF0000

/* 
 * DisplayHAL unterste Schicht über dem
 * physikalischen Display
 * konfiguriert die HAL (Controller) und
 * die notwendigen Geräte (PinConnectBlock, GPIO, PWM)
 */
 namespace ZEA7_2_Components{
	template<class HAL_> class DisplayHAL;
 }

namespace Generator { namespace DD {
template<class Origin, class ConfigRepository>
struct Component<
	CommonComponents::Display,
	Generator::CS<Boards::ZEA7_2, LPC21xx::Base>,
	Generator::Adapter,
	Origin, ConfigRepository>
{
	typedef typename Origin::S2::Selector prozessor_type;

//	typedef typename ConfigRepository::Platform::prozessor_type prozessor_type;
//	typedef typename ConfigRepository::Controller Controller;

	typedef typename Generator::SD::Create<prozessor_type, HAL::Layer>::type Hal;
	typedef ZEA7_2_Components::DisplayHAL<Hal> type;
};

} // namespace DD

namespace SD {
//	template<class Origin, class ConfigRepository>
//	struct Component<Boards::ZEA7_2, CommonComponents::DisplayHAL, Origin, ConfigRepository>
//	{
//		typedef typename ConfigRepository::Controller Controller;
//
//		typedef typename Create<Controller, HAL::Layer>::type Hal;
//		typedef ZEA7_2_Components::DisplayHAL<Hal> type;
//	};
}} // namespace Generator::SD


namespace ZEA7_2_Components{

template<class HAL_>
class DisplayHAL{

public:
	typedef DisplayHAL<HAL_> type;
	typedef HAL_ Hal;

	typedef typename HAL::U8 U8;  // Wertebereich der x/y Koordinaten
	typedef typename HAL::U8 size_t;  // Wertebereich der x/y Koordinaten
	typedef typename HAL::Point<size_t> Point;
	typedef typename HAL::U16 Color;
	
	//die physikalische Größe des Displays
	enum { WIDTH=160, HEIGHT=129 };
	
	//Todo: aufräumen oder entfernen, wird von Höheren Schichten verwaltet
	// oder als Grundset von Farben stehen lassen
	enum { 

		Red = 0xF800, Red2 = 0xF9E0, 
		Green = 0x07C0, Green2 = 0x0400, Green3 = 0x0FF0, 
		Blue = 0x003E, Blue2 = 0x051F, 

		White = Red|Green|Blue,
		White2 = 0xF7BC,
		Gray = 0xD718,

		Yellow = 0xFFE0, Yellow2 = 0xF700, 
		Black = 0x0000, 
		Magenta = 0xF81E,  
		Cyan = 0x7FFF,  
		Brown = 0x8400 
	};
	
	// Todo: Alle Operationen static, die höheren Schichten müssen
	// für die Initialisierung sorgen, kein Objekt dieses Templates
	// soll benötigt werden
	static type& getInstance();
	

private:
	// HW Geräte
	typedef typename Hal::GPIOPort0 port0;
	typedef typename Hal::GPIOPort1 port1;
	typedef typename Hal::PinConnectBlock PinConnectBlock;
	typedef typename Hal::PWM PWM;
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
	/*
	 * Füllt den gesamten Sreen mit color
	 */
	static void Clear_Screen( Color color );
	/*
	 * Initialisiert/konfiguriert die HAL,
	 * setzt die GPIOPorts,
	 * initialisiert den LCD Bus
	 *
	 * Todo: eventuell static
	 */
	void init() const;
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
	/*
	 * Initialisiert den PWM (Stromversorgung für das LCD)
	 */
	// Brightness between 0 and 100%
	static void BacklightOn(U8 brightness);
	//======================================================

	//TODO entfernen wird nicht benötigt
//	static void flush(	unsigned int x0=0, unsigned int y0=0, 
//						unsigned int x1=WIDTH, unsigned int y1=HEIGHT);
//	

	template <typename T>
	static void swap(T& v1, T& v2){
	 	v1^=v2;
		v2^=v1;
		v1^=v2;
	}
	// Low Level Register Operations
	static void Bus_Initial();
	static void Reg_Set(unsigned int Cmd,unsigned int Data);
	static void Write_Byte( unsigned char Data );

	// helper
	static void Delay1Ms(unsigned int tmr);

	//======================================================
	// graphic Primitive, überschreiben immer ein
	// Rechteck das durch setArea(...) angegeben wurde
	//======================================================
	static void DrawLine( 	unsigned short x0,
								unsigned short y0,
								unsigned short x1,
								unsigned short y1,
								Color color );
	static void Rectangle( 	unsigned short x0,
							unsigned short y0,
							unsigned short x1,
							unsigned short y1,
							Color color );
	static void Ellipse( 	double x0,
							double y0,
							double h1,
							double h2,
							unsigned int foreground,
							unsigned int background );
	/* x, y Screenposition
		s text
	*/
	static void PutString(unsigned short x, unsigned short y, char *s, Color foreground = White, Color background = Black);
	static void PutNumber(unsigned short x, unsigned short y, unsigned long value, Color foreground = White, Color background = Black, unsigned char base=10);
	static char* value2string(unsigned int value, unsigned char base, char* buffer);

	//Einzelne Zeichen Operationen
	static void PutChar(unsigned short x, unsigned short y, char c, unsigned int f, unsigned int b);
	static void PutChar8x8(unsigned short x, unsigned short y, char c, unsigned int f, unsigned int b);
	static void PutChar8x16(unsigned short x, unsigned short y, char c, unsigned int f, unsigned int b);
	static void PutGB1616(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int f,unsigned int b);


};
//=====================================================================

//---------------------------------------------------------------------------------
// HW Abstraction Layer2 diesen Bereich als lib gestalten
//---------------------------------------------------------------------------------
template<class HAL_>
DisplayHAL<HAL_>& 
DisplayHAL<HAL_>
::getInstance(){
 	//static DisplayHAL<HAL_> display;
 	static type instance;
	return instance;
}
//---------------------------------------------------------------------------------
//*****************************************************
// protected
//*****************************************************
template<class HAL_>
DisplayHAL<HAL_>
::DisplayHAL()
{	
	PinConnectBlock::selectP0_2_GPIO();
	PinConnectBlock::selectP0_3_GPIO();
	PinConnectBlock::selectP0_22_GPIO();
//	PinConnectBlock::selectP1_25_16_GPIO();
//	PinConnectBlock::selectP1_31_26_GPIO();

	PinConnectBlock::selectP0_21_PWM5();

	BacklightOn(50);
	init();
}
//*****************************************************
// private ctor helpers
//*****************************************************
template<class HAL_>
void 
DisplayHAL<HAL_>
::BacklightOn(unsigned char brightness){
	//getPinFunctionSelectRegister().routePWM();
	PWM::setPrescale(0);    // der teiler für den timer (10 bedeutet PWMTC+1 bei jedem 11. pclk)
	PWM::setPWMRate(50);

	PWM::PWM5::enablePWMOutput();
	
	PWM::resetTC_OnMatch();
	PWM::enableCounter();
	PWM::enablePWM();
	setBrightness(brightness);
}

template<class HAL_>
void 
DisplayHAL<HAL_>
::setBrightness(unsigned char brightness) {
 	PWM::PWM5::setPWMDutyRate(brightness/2);
	PWM::PWM5::enableLatch();
}
//---------------------------------------------------
template<class HAL_>
void 
DisplayHAL<HAL_>
::init() const {
	Bus_Initial();

	Reg_Set(0x02,0x86);
	Reg_Set(0x03,0x00);
	Reg_Set(0x05,0x08);
	Reg_Set(0x07,0x7F);
	Reg_Set(0x08,0x17);
	// SRAM control
	Reg_Set(0x09,0x00);
	Reg_Set(0x10,0x00);
	Reg_Set(0x11,0x7F);
	Reg_Set(0x12,0x9F);
	Reg_Set(0x14,0x00);
	Reg_Set(0x16,0x9F);
	Reg_Set(0x17,0x01);
	Reg_Set(0x18,0x00);
	Reg_Set(0x19,0x00);
	// Gamma voltage adjustalbe level
	Reg_Set(0x21,0x88);
	Reg_Set(0x22,0x33);
	Reg_Set(0x23,0xCC);
	Reg_Set(0x24,0xCC);
	Reg_Set(0x25,0xBB);
	Reg_Set(0x26,0xBB);
	Reg_Set(0x27,0x77);
	Reg_Set(0x28,0x77);
	Reg_Set(0x29,0x77);

	Reg_Set(0x06,0xC7);
}

//*****************************************************
// low Level Register Operations
//*****************************************************
template<class HAL_>
void DisplayHAL<HAL_>
::Bus_Initial(){
	port1::setToOutputMode(LCD_BUS_DAT);

	port0::setToOutputMode(LCD_BUS_RST | LCD_BUS_CS | LCD_BUS_RD );
	port1::setToOutputMode(LCD_BUS_RS | LCD_BUS_RW);
	port0::clear(LCD_BUS_RST);
	//Delay1Ms( 20 );
	port0::write(LCD_BUS_RST | LCD_BUS_CS | LCD_BUS_RD);
	port1::write(LCD_BUS_RS | LCD_BUS_RW);
}

template<class HAL_>
void 
DisplayHAL<HAL_>
::Reg_Set(unsigned int Cmd,unsigned int Data){
	port0::clear(LCD_BUS_CS);
	port0::write(LCD_BUS_RD);
	port1::clear(LCD_BUS_RS);

	Write_Byte( Cmd );
	port1::write(LCD_BUS_RS);
	Write_Byte( Data );
	//Delay1Ms( 20 );
}

template<class HAL_>
void DisplayHAL<HAL_>
::Write_Byte( unsigned char Data ){
	// Daten ins 3 Byte schieben
	//unsigned int d = (((unsigned int)Data)<<16);// & LCD_BUS_DAT == 3. Byte FF;
	unsigned int d = static_cast<unsigned int>(Data)<<16;// & LCD_BUS_DAT == 3. Byte FF;
	port1::clear(LCD_BUS_DAT); // 3. Byte loeschen
	port1::write(d);   // Daten schreiben

	port1::clear(LCD_BUS_RW); // RW to LOW   24. bit loeschen
	port1::write(LCD_BUS_RW); // RW to HIGH	24. bit setzen
//	Delay1Ms( 20 );	
}

template<typename HAL>
void DisplayHAL<HAL>
::setPixel(Color color){
 	Write_Byte(color>>8);
	Write_Byte(color);
}
// ---------------------------------------------
// Graphic Operations
// ---------------------------------------------
template<class HAL_>
void 
DisplayHAL<HAL_>
::Clear_Screen( Color color ) {
	
	Rectangle(0,0,159,128, color );
}



template<class HAL_>
void 
DisplayHAL<HAL_>
::Rectangle( 	unsigned short x0, 
				unsigned short y0, 
				unsigned short x1, 
				unsigned short y1, 
				Color color ) {
	int x,y;

	setArea(x0,y0,x1,y1);

	for(x=0;x<=x1-x0;x++){
		for(y=0;y<=y1-y0;y++) {
			Write_Byte( color>>8 );
			Write_Byte( color );
		}
	}
	//port0::write(LCD_BUS_CS);
}

template<class HAL_>
void 
DisplayHAL<HAL_>
::Ellipse( 	double x0, 
			double y0, 
			double h1, 
			double h2, 
			unsigned int foreground,
			unsigned int background ) {
	int x,y;

	double x1 = (x0 + (2 * h1));
	double y1 = (y0 + (2 * h2));

	setArea(x0,y0,x1,y1);

	for(x=0;x<=x1-x0;x++){
		for(y=0;y<=y1-y0;y++) {
			
			double a = std::pow((((1/h1) * x) - 1), 2);
			double f1 = (-h2 * (std::sqrt(1-a) + 1) + (2 * h2));
			double f2 = (h2 * (std::sqrt(1-a) + 1));
			
			if (y > f1 && y < f2){
				Write_Byte( foreground>>8 );
				Write_Byte( foreground );
			} else { 
				Write_Byte( background>>8 );
				Write_Byte( background );
			}
		}
	}
	//port0::write(LCD_BUS_CS);
}

//*****************************************************
// Zeichenausgabe
//*****************************************************
/*
  Parameter
  x/y Position
  s text
  f foreground color(text) b background color
*/
template<class HAL_>
void 
DisplayHAL<HAL_>::
PutString(unsigned short x, unsigned short y, char *s, Color f, Color b) {
	register unsigned char l=0;
	while(*s) {
		if( *s < 0x80 ) { // is ASCII ?
			PutChar(x+l*8,y,*s,f,b);
			++s;++l;
			}
		else {
			PutGB1616(x+l*8,y,(unsigned char *)s,f,b);
			s+=2;l+=2;
			}
		}
}


template<class HAL_>
void 
DisplayHAL<HAL_>
::PutNumber(
		unsigned short x, 
		unsigned short y, 
		unsigned long value, 
		Color foreground, 
		Color background, 
		unsigned char base){
 	char buffer[sizeof(long)*8+1];
	
	//const int MAX = sizeof(buffer);
	//for(int i = 0;i < 33; ++i) buffer[i] = 0;

	PutString(x, y, value2string(value, base, buffer), foreground, background);
}

template<class HAL_>
char* 
DisplayHAL<HAL_>
::value2string(unsigned int value, unsigned char base, char* buffer){
    unsigned char rest = 0;
    unsigned int wert = value;
    unsigned char i = 0;

	// special case
	if(wert == 0){
        buffer[0] = '0';
        buffer[1] = '\0';
    }else{
	    for(; wert > 0; ++i){
	        rest = wert % base;
	        wert /= base;
	        buffer[i] = (rest > 9) ? 'A' + rest - 10 : '0'+ rest;            
	    }
	    buffer[i] = '\0';
	    --i;
		//invert via swap
	    for(unsigned char start = 0; start < i; ++start, --i){
	        buffer[start] ^= buffer[i];
	        buffer[i] ^= buffer[start];
	        buffer[start] ^= buffer[i];
	    }
	}
    return buffer;
}
//*****************************************************
// 
//*****************************************************
template<class HAL_>
void 
DisplayHAL<HAL_>
::setArea( U8 x0, U8 y0, U8 x1, U8 y1 ){
	// SRAM control
	if(x0 > x1) swap(x0, x1);
	if(y0 > y1) swap(y0, y1);
	
	--x1; --y1;

	Reg_Set(0x09,y0);
	Reg_Set(0x10,x0);
	Reg_Set(0x11,y1);
	Reg_Set(0x12,x1);
							
	Reg_Set(0x18,y0);
	Reg_Set(0x19,x0);
}
//*****************************************************
// private Zeichenausgabe
//*****************************************************
template<class HAL_>
void 
DisplayHAL<HAL_>
::PutChar(unsigned short x, unsigned short y, char c, unsigned int f, unsigned int b){
	//TODO small or big Font?
	if( false )
		PutChar8x8( x, y, c, f, b );
	else
		PutChar8x16( x, y, c, f, b );
}

#include <GraphicDevice/8X8h.h>
template<class HAL_>
void 
DisplayHAL<HAL_>
::PutChar8x8(unsigned short x, unsigned short y, char c, unsigned int f, unsigned int b){
	register unsigned int i,j;

	setArea(x,y,x+8-1,y+8-1);
	//prepareRegister();
	for(i=0; i<8;i++) {
		unsigned char m=Font8x8[c][i];
		for(j=0;j<8;j++) {
			if((m&0x80)==0x80) {
				Write_Byte(f>>8);
				Write_Byte(f);
				}
			else {
				Write_Byte(b>>8);
				Write_Byte(b);
				}
			m<<=1;
		}
	}
	//port_0.write(LCD_BUS_CS);
}

#include <GraphicDevice/8X16.h>
template<class HAL_>
void 
DisplayHAL<HAL_>
::PutChar8x16(unsigned short x, unsigned short y, char c, unsigned int f, unsigned int b){
	register unsigned int i,j;

	setArea(x,y,x+8-1,y+16-1);
//-------------------------------------
	//prepareRegister();
	for(i=0; i<16;i++) {
		unsigned char m=Font8x16[c*16+i];
		for(j=0;j<8;j++) {
			//if((m&0x80)==0x80) {
			if((m&0x80) > 0) {
				Write_Byte(f>>8);
				Write_Byte(f);
				}
			else {
				Write_Byte(b>>8);
				Write_Byte(b);
			}
			m<<=1;
		}
	}
	//port_0.write(LCD_BUS_CS);
}


#include <GraphicDevice/GB1616.h>	//16*16º
template<class HAL_>
void 
DisplayHAL<HAL_>
::PutGB1616(	unsigned short x, 
									unsigned short  y, 
									unsigned char c[2], 
									unsigned int f,
									unsigned int b){
	unsigned int i,j,k;

	setArea(x, y, x+16-1, y+16-1);
	for (k=0;k<49;k++) {
	  if ((codeGB_16[k].Index[0]==c[0])&&(codeGB_16[k].Index[1]==c[1])){ 
    	for(i=0;i<32;i++) {
		  unsigned short m=codeGB_16[k].Msk[i];
		  for(j=0;j<8;j++) {
			if((m&0x80)==0x80) {
				Write_Byte(f>>8);
				Write_Byte(f);
				}
			else {
				Write_Byte(b>>8);
				Write_Byte(b);
				}
			m<<=1;
			} 
		  }
		}  
	  }	
	//port_0.write(LCD_BUS_CS);
}

//*****************************************************
// Delay
//*****************************************************
template<class HAL_>
void 
DisplayHAL<HAL_>
::Delay1Ms(unsigned int tmr){
	while( tmr ) {
		//unsigned int i;
		//for(i=0;i<10;i++)
		//	;
		tmr--;
		}
}
} // end namespace GraphicDevice



#endif // __EVALBOARD_ZEA7_2_DISPLAY_HAL_H__
