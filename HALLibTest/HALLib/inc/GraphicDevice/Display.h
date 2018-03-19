#ifndef __DISPLAY_H__
#define __DISPLAY_H__

//#define DISPLAY_DEBUG_OUT

#include <cmath>
#include <algorithm>

#include <Generator/CreateComponent.h>
#include <Generator/BaseType.h>

#include <CommonComponents/CommonComponentTypes.h>

//#include <HAL/ComponentTypes.h>
#include <HAL/Typedefs.h>
#include <GraphicDevice/8x16.h>
#include <GraphicDevice/ShadowDisplay.h>


namespace GraphicDevice{
	// forward Declaration
	template<typename DisplayHAL, typename ShadowDisplay, bool trueColor=false>
	class Display;
	
	template<long NUMBITSPERCOLOR = 4, class Base = Generator::EmptyRepository>
	struct DisplayConfigurationRepository : Base {
		typedef DisplayConfigurationRepository<NUMBITSPERCOLOR> Display;
		enum { NumBitsPerColor = NUMBITSPERCOLOR};
	};

}
namespace Generator {
	//==============================================================
	// Display Components
	//--------------------------------------------------------------
	template<class Origin, class ConfigRepository>
	struct Component<CommonComponents::Display, Origin, ConfigRepository>
	{
		typedef typename ConfigRepository::Platform::board_type board_type;
		typedef typename ConfigRepository::Platform::prozessor_type prozessor_type;

		typedef DD<CommonComponents::Display, CS<board_type, prozessor_type> > DisplayHALContext;
		typedef typename Create<DisplayHALContext, ConfigRepository, DisplayHALContext>
		::type DisplayHAL;


//		typedef typename Create<
//				Origin,
//				CommonComponents::DisplayHAL,
//				ConfigRepository>
//		::type DisplayHAL;
		typedef CS<CommonComponents::ShadowDisplay, prozessor_type> ShadowDisplayContext;
		typedef typename Create<ShadowDisplayContext, ConfigRepository, ShadowDisplayContext>
		::type ShadowDisplay;

//		typedef typename Create<
//				prozessor_type,
//				CommonComponents::ShadowDisplay,
//				ConfigRepository>
//		::type ShadowDisplay;

		typedef GraphicDevice::Display<DisplayHAL, ShadowDisplay,
				false
//				sizeof(typename ShadowDisplay::ColorIndexType) == sizeof(typename DisplayHAL::Color)
		>type;
	};
} // namespace Generator

namespace GraphicDevice{

//Todo TrueColor Display implementieren
template<typename ShadowDisplay, typename DisplayHAL>
class Display<ShadowDisplay, DisplayHAL, true> 
: public DisplayHAL
{
	// ohne Palette
};


template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
class Display : public DisplayHAL
{
public:
	typedef Display<DisplayHAL, ShadowDisplay, trueColor> type;

	static type& getInstance(){
	 	static type instance;
		return instance;
	}
    
	typedef typename DisplayHAL::Color ColorHAL;
    typedef typename DisplayHAL::Point PointHAL;
    typedef typename DisplayHAL::size_t size_t;
	enum { WIDTH=DisplayHAL::WIDTH, HEIGHT=DisplayHAL::HEIGHT};

    typedef typename ShadowDisplay::ColorIndexType IndexType;
    typedef typename ShadowDisplay::ColorIndexType Color;
    enum{NumColors = ShadowDisplay::NumColors};
// TODO: doubles für definition von koords
    typedef HAL::Point<double> Point;
//    typedef PointHAL Point;

	enum {FLUSH = true};
    static HAL::CHAR* value2string(HAL::U32 value, HAL::CHAR* buffer, HAL::U8 base=10);
    // TODO: usigned char mit std::string nicht möglich!?
    //    static HAL::U8* value2string(HAL::U32 value, HAL::U8* buffer, HAL::U8 base=10);

	//GraphicPrimitives
	void flush(Point p0=Point(), Point p1=Point(WIDTH, HEIGHT));
	void setPixel(Point p, Color color, bool bflush =  FLUSH);
	IndexType getPixel(Point p){
		return sD.getPixel(p);
	}
	IndexType getPixel(size_t x, size_t y){
		return getPixel(Point(x, y));
	}

    void drawLine( Point p0, Point p1, Color color, bool flush = FLUSH);
    void fillRectangle(Point p0, Point p1, Color color, bool flush = FLUSH);
    void drawRectangle(Point p0, Point p1, Color color, bool flush = FLUSH);
    void fillEllipse(Point p0, Point p1, Color color, bool flush = FLUSH);
    void drawEllipse(Point p0, Point p1, Color color, bool flush = FLUSH);

    void putString(Point p, const HAL::CHAR* s, Color textColor, bool flush = FLUSH);
    void putNumber(	Point p, HAL::U64 value, Color foreground,
    				HAL::U8 base = 10, bool flush = FLUSH);
    void convolute();

    ColorHAL getColor(Color color){
    	return palette[color];
    }
    void setColor(size_t idx, ColorHAL color){
    	palette[idx] = color;
    }
    void clear(){
    	sD.init();
    }
protected:
	Display();
private:
    ColorHAL palette[NumColors];

    //ShadowDisplay sD;
	static ShadowDisplay& createShadowDisplay(){
		static ShadowDisplay instance;
		//static ShadowDisplay& instance = *new ShadowDisplay();
		return instance;
	}
	ShadowDisplay& sD;
    //---------------------------------------
	void adjustParams(Point& p0, Point& p1); 
    void adjustPoints(Point& p0, Point& p1);
	void adjustRanges(Point& p0, Point& p1);
    //---------------------------------------	
	void drawHorizontalLine(Point p0, size_t x1, Color color);
	void drawVerticalLine(Point p0, size_t y1, Color color);
    //---------------------------------------
	void putChar8x16(Point p0, unsigned char c, Color textColor);
    //---------------------------------------
};
//------------------------------------------
//ctor
//todo für 16/256 Farben algo definieren
//------------------------------------------
template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
Display<DisplayHAL, ShadowDisplay, trueColor>
::Display():DisplayHAL(), sD(createShadowDisplay())
{	HAL::U8 idx = 0;
	palette[  idx] = DisplayHAL::Black;
	palette[++idx] = DisplayHAL::Brown;
	palette[++idx] = DisplayHAL::Blue;
	palette[++idx] = DisplayHAL::Blue2;
	palette[++idx] = DisplayHAL::Cyan;
	palette[++idx] = DisplayHAL::Green2;
	palette[++idx] = DisplayHAL::Green;
	palette[++idx] = DisplayHAL::Green3;
	palette[++idx] = DisplayHAL::Magenta;
	palette[++idx] = DisplayHAL::Red;
	palette[++idx] = DisplayHAL::Red2;
	palette[++idx] = DisplayHAL::Yellow2;
	palette[++idx] = DisplayHAL::Yellow;
	palette[++idx] = DisplayHAL::Gray;
	palette[++idx] = DisplayHAL::White2;
	palette[++idx] = DisplayHAL::White;

}
//------------------------------------------
// private Helpers
//------------------------------------------
template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
void
Display<DisplayHAL, ShadowDisplay, trueColor>
::adjustParams(Point& p0, Point& p1) {
    if(p1.x > DisplayHAL::WIDTH) p1.x = DisplayHAL::WIDTH;
    if(p1.y > DisplayHAL::HEIGHT) p1.y = DisplayHAL::HEIGHT;
    if(p0.x < 0) p0.x = 0;
    if(p0.y < 0) p0.y = 0;
}

template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
void
Display<DisplayHAL, ShadowDisplay, trueColor>
::adjustPoints(Point& p0, Point& p1){
    if(p1.x < p0.x) std::swap(p0.x, p1.x);
    if(p1.y < p0.y) std::swap(p0.y, p1.y);

}

template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
void
Display<DisplayHAL, ShadowDisplay, trueColor>
::adjustRanges(Point& p0, Point& p1){
	typedef typename Point::sizetype size_t;
	const size_t MIN = 0;
    if(p0.x < MIN) p0.x = MIN;
    if(p0.y < MIN) p0.y = MIN; 
    if(p1.x < MIN) p1.x = MIN;
    if(p1.y < MIN) p1.y = MIN; 
    
    if(p0.x > ShadowDisplay::WIDTH) p0.x = ShadowDisplay::WIDTH;
    if(p0.y > ShadowDisplay::HEIGHT) p0.y = ShadowDisplay::HEIGHT;
    if(p1.x > ShadowDisplay::WIDTH) p1.x = ShadowDisplay::WIDTH;
    if(p1.y > ShadowDisplay::HEIGHT) p1.y = ShadowDisplay::HEIGHT;
}

template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
void
Display<DisplayHAL, ShadowDisplay, trueColor>
::drawHorizontalLine(Point p0, size_t x1, Color color) {

	int x = p0.x < 0 ? 0 : p0.x;
	int xMax = x1 > WIDTH ? WIDTH : x1;

	for(; x < xMax; ++x)
		sD.setPixel(x, p0.y, color);
}                    

template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
void
Display<DisplayHAL, ShadowDisplay, trueColor>
::drawVerticalLine(Point p0, size_t y1, Color color) {

	int y = p0.y < 0 ? 0 : p0.y;
	int yMax = y1 > HEIGHT ? HEIGHT : y1;

	for(; y < yMax; ++y)
		sD.setPixel(p0.x, y, color);
}    

template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
void
Display<DisplayHAL, ShadowDisplay, trueColor>
::putChar8x16(Point p0, unsigned char c, Color textColor) {
	register HAL::U8 x, y;

	for(y = 0; y < 16; ++y) {

		HAL::U8 m = Font8x16[c * 16 + y];

		for(x = 0; x < 8; ++x) {
			if( (m & 0x80) > 0 ) {
				sD.setPixel(Point(x + p0.x, y + p0.y), textColor);
			}
//			else {
//          	sD.setPixel(Point(x + p0.x, y + p0.y), background);
//          }
			m <<= 1;
		}
	}
}
                
//---------------------------
// public Helpers
//---------------------------
template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
HAL::CHAR*
Display<DisplayHAL, ShadowDisplay, trueColor>
::value2string(HAL::U32 value, HAL::CHAR* buffer, HAL::U8 base) {
	HAL::U8 rest = 0;
	HAL::U32 wert = value;
	HAL::U8 i = 0;

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
		for(HAL::U8 start = 0; start < i; ++start, --i){
			buffer[start] ^= buffer[i];
			buffer[i] ^= buffer[start];
			buffer[start] ^= buffer[i];
		}
	}
	return buffer;
}

//---------------------------
// public Graphic Primitives
//---------------------------
template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
void
Display<DisplayHAL, ShadowDisplay, trueColor>
::flush(Point p0, Point p1) {
	//DisplayHAL::SetArea(p0, p1);
	DisplayHAL::setArea(p0.x, p0.y, p1.x, p1.y);
	for(size_t y = p0.y; y < p1.y; ++y)
		for(size_t x = p0.x; x < p1.x; ++x)
			DisplayHAL::setPixel(palette[sD.getPixel(x, y)]);
//			DisplayHAL::setPixel(sD.getPixel(x, y));
}

template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
void
Display<DisplayHAL, ShadowDisplay, trueColor>
::setPixel(Point p, Color color, bool bflush){
	bool outOfRange =
			p.x < 0 || p.x >= WIDTH
			|| p.y < 0 || p.y >= HEIGHT;
	if (outOfRange) return;
    sD.setPixel(p, color);
    if(bflush)
        flush(p, Point(p.x+1, p.y+1));
}	

//template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
////Display<DisplayHAL, ShadowDisplay, trueColor>::IndexType
//HAL::U16
////void
//Display<DisplayHAL, ShadowDisplay, trueColor>
//::getPixel(Point p){
//	return sD.getPixel(p);
//}

//template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
//Display<DisplayHAL, ShadowDisplay, trueColor>::IndexType
//Display<DisplayHAL, ShadowDisplay, trueColor>
//::getPixel(size_t x, size_t y){
//	return sD.getPixel(x, y);
//}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void 
Display<ShadowDisplay, DisplayHAL, trueColor>
::drawLine( Point p0, Point p1, Color color, bool bflush) {

	bool verticalLine = p0.x == p1.x;
    bool horizontalLine = p0.y == p1.y;
    // bool onlyOnePoint = verticalLine && horizontalLine;
    Point p_0(p0), p_1(p1);

    //von rechts nach links zeichnen
    if(p_0.x > p_1.x || (p_0.x == p_1.x && p_0.y > p_1.y))
        std::swap(p_0, p_1);

    // TODO: params muss hier berechnet werden
    adjustRanges(p_0, p_1);

//    size_t x0 = p_0.x, y0 = p_0.y, x1 = p_1.x, y1 = p_1.y;

    if(horizontalLine) {
        drawHorizontalLine(p0, p1.x, color);
    } else if(verticalLine) {
        drawVerticalLine(p0, p1.y, color);
	} else {
		double x = p0.x;
		double y = p0.y;

		double m = ((static_cast<double>(p1.y) - p0.y)
                    / (p1.x - p0.x));

		//flache Steigungen < 45Grad
        if (m <= 1 && m >= -1) {
			for(size_t u = p0.x; u < p1.x; u++) {
				sD.setPixel(u, static_cast<int>(y), color);
				y += m;
                if(y >= ShadowDisplay::HEIGHT) break;
			}
		} else {//steile Steigungen > 45Grad
			m = 1/m;
			for(size_t u = p0.y; u < p1.y; u++) {
				sD.setPixel(static_cast<int>(x), u, color);
				x += m;
                if(x >= ShadowDisplay::WIDTH) break;
			}
		}
	}

	if(bflush) {
		if (horizontalLine || verticalLine)
			flush (p0, Point(p1.x + 1, p1.y + 1));
		else
			flush(p0, p1);
	}
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void 
Display<ShadowDisplay, DisplayHAL, trueColor>
::fillRectangle(Point p0, Point p1, Color color, bool bflush){
    adjustPoints(p0, p1);
    adjustParams(p0, p1);

    for(size_t x = p0.x; x < p1.x; ++x)
        for(size_t y = p0.y; y < p1.y; ++y)
            sD.setPixel(x, y, color);

    if(bflush) flush(p0, p1);
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void 
Display<ShadowDisplay, DisplayHAL, trueColor>
::drawRectangle(Point p0, Point p1, Color color, bool bflush){
    adjustPoints(p0, p1);
    //adjustRanges
//    U16 x0 = p0.x, y0 = p0.y, x1 = p1.x, y1 = p1.y;
    //rechter Rand
    //U16 x
    Point p0Flush, p1Flush;

    bool outOfRange =
    		p0.x >= WIDTH || p0.y >= HEIGHT
    		|| p1.x < 0 || p1.y < 0;
    if (outOfRange) return;

    bool drawTopLine = !(p0.y < 0);
	if (drawTopLine) {
		p0Flush = p0;
		p1Flush = Point(p1.x + 1, p0.y + 1);
		drawHorizontalLine(p0, p1.x, color);
	}
	bool drawBottomLine = !(p1.y > HEIGHT);
	if (drawBottomLine){
		if (!drawTopLine)
			p0Flush = Point(p0.x, p1.y - 1);
		p1Flush = p1;
		drawHorizontalLine(Point(p0.x, p1.y-1), p1.x, color);
	}
	bool drawLeftLine = !(p0.x < 0);
	if (drawLeftLine){
		p0Flush = p0;
		if (!drawBottomLine)
			p1Flush = Point(p0.x + 1, p1.y + 1);
		drawVerticalLine(p0, p1.y, color);
	}
	bool drawRightLine = !(p1.x > WIDTH);
	if (drawRightLine){
		if (!(drawTopLine || drawLeftLine))
			p0Flush = Point(p1.x - 1, p0.y);

		if (drawBottomLine)
			p0Flush = p0;
		p1Flush = p1;
		drawVerticalLine(Point(p1.x-1, p0.y), p1.y, color);
	}

	bool flushNeeded = drawTopLine || drawBottomLine
						|| drawLeftLine || drawRightLine;
    if (bflush && flushNeeded){
		adjustParams(p0Flush, p1Flush);
		flush(p0Flush, p1Flush);
    }
}


/*
4 Fälle die für XMAX / YMAX unterschieden werden müssen
Mit 
WIDTH = 50

der Startwert für x
x = x0 < 0 ? std::abs(x0) : 0;
der setPixel Wert für x
int xVal = x0 + x;

Fälle für XMAX:
1. x0 > 0 && x1 <= WIDTH Innerhalb des Displays
Bsp:
    x0=10, x1=30
    x = 0
    => XMAX = x1-x0  == 20// x läuft von 0 bis 19
    xVal = 10 + x

2. x0 < 0 && x1 <= WIDTH links ausserhalb -
    x0=-10; x1=10
    x = abs(x0) == 10
    => XMAX =  x1-x0 == 20// x läuft von 10 bis 19
        xVal = -10 + x

3. x0 > 0 && x1 > WIDTH rechts ausserhalb
    x0=45; x1=70
    x = 0
    => XMAX = WIDTH-x0 == 5// x läuft von 0 bis 4
        xVal = 45 + x

4. x0 < 0 && x1 > WIDTH links und rechts ausserhalb
    x0=-100; x1=70
    x = abs(x0) == 100
    => XMAX =  WIDTH-x0 == 150 // x läuft von 100 bis 149
        xVal = -100 + x

bei 1 und 2 kann x1-x0 genommen werden (x1 <= WIDTH)
bei 3 und 4 kann x+WIDTH genommen werden (x1>WIDTH)

XMAX kann wie folgt berechnet werden
x = x0 < 0 ? std::abs(x0) : 0;
const int XMAX = x1 > WIDTH ? WIDTH-x0 : (x1 - x0); 


Für YMAX
Mit 
WIDTH = 50

der Startwert für y
int y = y0 < 0 ? std::abs(y0) : f1;
der setPixel Wert für y
int yVal = y0 + y;

Fälle für yMAX:
1. y0 > 0 && y1 <= HEIGHT Innerhalb des Displays
Bsp:
    y0=10, y1=30
    y = 0
    => YMAX = y1-y0  == 20// y läuft von 0 bis 19
    yVal = 10 + x

*/
template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void 
Display<ShadowDisplay, DisplayHAL, trueColor>
::fillEllipse(Point p0, Point p1, Color color, bool bflush){

	adjustPoints(p0, p1);

	// TODO: typedef int
	double x0 = p0.x, y0 = p0.y, x1 = p1.x, y1 = p1.y;

//	adjustParams(p0, p1);

	// hx/hy const machen
	const double XHA = (static_cast<double>(x1 - x0) / 2);
	const double YHA = (static_cast<double>(y1 - y0) / 2);

	int x = x0 < 0 ? std::abs(x0) : 0;
	const int XMAX = x1 > WIDTH ? WIDTH - x0 : (x1 - x0);
#ifdef DISPLAY_DEBUG_OUT
	std::cout << std::endl << "########## x " << x << "  y0 " << y0 << "  x0 " << x0 << "  XMAX " << XMAX << "  WIDTH " << WIDTH << "  HEIGHT " << HEIGHT;
#endif
	for(; x < XMAX; ++x) {

		int xVal = x0 + x;
//		if (xVal < 0 || xVal > WIDTH) continue;

		double a = std::pow((((1/XHA) * (x + 0.5)) - 1), 2);
		double b = (std::sqrt(1-a) + 1);
		int f1 = static_cast<int>((-YHA * b + (2 * YHA)));
		int f2 = static_cast<int>(YHA * b);

		int y = y0 < 0 ? std::abs(y0) : f1;
		const int YMAX = (y0 + f2) > HEIGHT ? HEIGHT - y0 : f2 + 1;
#ifdef DISPLAY_DEBUG_OUT
		std::cout << std::endl << "########## y " << y << "  YMAX " << YMAX << "  f1 " << f1 << "  f2 " << f2;
#endif
		for(; y < YMAX ; ++y) {
			int yVal = y0 + y;
#ifdef DISPLAY_DEBUG_OUT
			std::cout << std::endl << "      #### xVal " << xVal << "  yVal " << yVal;
#endif
//			if (yVal < 0 || yVal > HEIGHT) continue;
//			std::cout << std::endl << "    #### xVal " << xVal << " yVal " << yVal;
			sD.setPixel(xVal, yVal, color);
		}
	}
	adjustParams(p0, p1);
    if(bflush) flush(p0, p1);
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void 
Display<ShadowDisplay, DisplayHAL, trueColor>
::drawEllipse(Point p0, Point p1, Color color, bool bflush){
	int x,y;

	size_t x0 = p0.x, y0 = p0.y, x1 = p1.x, y1 = p1.y;

	adjustParams(p0, p1);

	const int XMAX = x1 - x0;
	const int YMAX = y1 - y0;

	double hx = (static_cast<double>(XMAX) / 2);
	double hy = (static_cast<double>(YMAX) / 2);

	for(x = 0; x < XMAX; ++x) {

		double a = std::pow((((1/hx) * (x + 0.5)) - 1), 2);
		double b = (std::sqrt(1-a) + 1);
		int f1 = static_cast<int>((-hy * b + (2 * hy)));
		int f2 = static_cast<int>((hy * b));

		sD.setPixel(x + x0, y0 + static_cast<int>(f1), color);

		if(f2 < YMAX) {
			sD.setPixel(x + x0, y0 + static_cast<int>(f2), color);
		} else {
			sD.setPixel(x + x0, y0 + static_cast<int>(f2) - 1, color);
		}
	}

	std::swap(hx, hy);

	for(y = 0; y < YMAX; ++y) {

		double a = std::pow((((1/hx) * (y + 0.5)) - 1), 2);
		double b = (std::sqrt(1-a) + 1);
		int f1 = static_cast<int>((-hy * b + (2 * hy)));
		int f2 = static_cast<int>((hy * b));

		sD.setPixel(x0 + static_cast<int>(f1), y0 + y, color);

		if(f2 < XMAX) {
			sD.setPixel(x0 + static_cast<int>(f2), y0 + y, color);
		} else {
			sD.setPixel(x0 + static_cast<int>(f2) - 1, y0 + y, color);
		}
	}
    if(bflush) flush(p0, p1);
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void 
Display<ShadowDisplay, DisplayHAL, trueColor>
::putString(Point p, const HAL::CHAR* s, Color textColor, bool bflush) {
	HAL::U8 l = 0;

	while (*s) {
		putChar8x16(Point(p.x + l * 8, p.y), *s, textColor);
			++s;
			++l;
	}
//	if(bflush) flush(Point(p.x, p.y), Point(p.x + 8, p.y + 16));
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void 
Display<ShadowDisplay, DisplayHAL, trueColor>
::putNumber(Point p, HAL::U64 value, Color foreground, HAL::U8 base, bool flush)
{
        HAL::CHAR buffer[sizeof(HAL::U64) * 8 + 1];
        putString(
			p, 
			value2string(value, buffer, base), 
			foreground, 
			flush);
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void
Display<ShadowDisplay, DisplayHAL, trueColor>
::convolute(){
	int filter[3][3] = {{1, 2, 1},
						{2, 4, 2},
						{1, 2, 1}};
	int scalingFactor;
	int value;

	for(int picCol = 0; picCol < WIDTH; ++picCol)
		for(int picRow = 0; picRow < HEIGHT; ++picRow){
			value = 0;
			scalingFactor = 0;
			for(int filterCol = -1; filterCol < 2; ++filterCol) {
				int xPos = picCol + filterCol;

				if(xPos < 0) return;
				if(xPos > WIDTH) return;

				for(int filterRow = -1; filterRow < 2; ++filterRow) {
					int yPos = picRow + filterRow;

					if(yPos < 0) return;
					if(yPos > HEIGHT) return;

					value += (sD.getPixel(xPos, yPos) * filter[filterCol][filterRow]);
					scalingFactor += filter[filterCol][filterRow];
				}
			}
			sD.setPixel(picCol, picRow, value/scalingFactor);
		}
}

/*
template<typename DisplayHAL, typename ShadowDisplay, bool trueColor>
class Display : public DisplayHAL{
public:
    static const bool FLUSH = true;
    typedef typename DisplayHAL::Color Color;
    typedef typename DisplayHAL::Point Point;
    typedef typename DisplayHAL::size_t size_t;

    typedef typename ShadowDisplay::ColorIndexType IndexType;
    enum{NumColors = ShadowDisplay::NumColors};

    static char* value2string(HAL::U32 value, HAL::U8 base, char* buffer) {
        HAL::U8 rest = 0;
        HAL::U32 wert = value;
        HAL::U8 i = 0;

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
            for(HAL::U8 start = 0; start < i; ++start, --i){
                buffer[start] ^= buffer[i];
                buffer[i] ^= buffer[start];
                buffer[start] ^= buffer[i];
            }
        }
        return buffer;
    }

private:
    Color palette[NumColors];

    ShadowDisplay sD;

    void adjustParams(Point& p0, Point& p1) 
	{
        if(p1.x < p0.x) std::swap(p0.x, p1.x);
        if(p1.y < p0.y) std::swap(p0.y, p1.y);

        if(p1.x > ShadowDisplay::WIDTH) p1.x = ShadowDisplay::WIDTH;
        if(p1.y > ShadowDisplay::HEIGHT) p1.y = ShadowDisplay::HEIGHT;
    }
    
	void adjustPoints(Point& p0, Point& p1)
	{
        if(p1.x < p0.x) std::swap(p0.x, p1.x);
        if(p1.y < p0.y) std::swap(p0.y, p1.y);

    }
    
	void adjustRanges(Point& p_0, Point& p_1){
        if(p_0.x < 0) p_0.x = 0;
        if(p_0.y < 0) p_0.y = 0; 
        if(p_1.x < 0) p_1.x = 0;
        if(p_1.y < 0) p_1.y = 0; 
        
        if(p_0.x > ShadowDisplay::WIDTH) p_0.x = ShadowDisplay::WIDTH;
        if(p_0.y > ShadowDisplay::HEIGHT) p_0.y = ShadowDisplay::HEIGHT;
        if(p_1.x > ShadowDisplay::WIDTH) p_1.x = ShadowDisplay::WIDTH;
        if(p_1.y > ShadowDisplay::HEIGHT) p_1.y = ShadowDisplay::HEIGHT;

    }
    void drawHorizontalLine(Point p0, size_t x1, Color color) {
            for(size_t x = p0.x; x < x1; ++x)
                sD.setPixel(x, p0.y, color);
    }                    

    void drawVerticalLine(Point p0, size_t y1, Color color) {
            for(size_t y = p0.y; y < y1; ++y)
                sD.setPixel(p0.x, y, color);
    }                    

    // TODO: bg-color entfernen und characterType definieren
    void putChar8x16(Point p0, unsigned char c, Color textColor, Color background) {
            register HAL::U8 x, y;

            for(y = 0; y < 16; ++y) {

            	HAL::U8 m = Font8x16[c * 16 + y];

                for(x = 0; x < 8; ++x) {
                    if( (m & 0x80) > 0 ) {
                        sD.setPixel(Point(x + p0.x, y + p0.y), textColor);
                    } else {
                        sD.setPixel(Point(x + p0.x, y + p0.y), background);
                    }
                    m <<= 1;
                }
            }
    }

protected:
    //Todo es darf nur eines geben -> Singleton create() usw
    Display():DisplayHAL() {
        //std::cout << "Display()" << std::endl;

   		palette[0] = DisplayHAL::White;
   		palette[1] = DisplayHAL::Black;

        for (IndexType i = 2; i < NumColors; ++i){
        	if(i < 10)
                palette[i] = i + '0';
            else
                palette[i] = i + 'a' - 10;
        }
		//DisplayHAL::Init();  todo: entfernen -> erfolgt mit dem ctor
    }
public:

    ~Display() {
        //std::cout << "~Display()" << std::endl;
    }

    void flush(Point p0, Point p1) {
		DisplayHAL::SetArea(p0, p1);
		for(size_t y = p0.y; y < p1.y; ++y)
			for(size_t x = p0.x; x < p1.x; ++x)
				DisplayHAL::setPixel(palette[sD.getPixel(x, y)]);
	}
	
    void setPixel(Point p, Color color, bool bflush =  FLUSH){
        sD.setPixel(p, color);
        if(bflush)
            flush(p, Point(p.x+1, p.y+1));
    }	

    IndexType getPixel(Point p){
    	return sD.getPixel(p);
    }

    IndexType getPixel(size_t x, size_t y){
    	return sD.getPixel(x, y);
    }

    void drawLine( Point p0, Point p1, Color color, bool flush = FLUSH);

    void fillRectangle(Point p0, Point p1, Color color, bool flush = FLUSH);

    void drawRectangle(Point p0, Point p1, Color color, bool flush = FLUSH);

    void fillEllipse(Point p0, Point p1, Color color, bool flush = FLUSH);

    void drawEllipse(Point p0, Point p1, Color color, bool flush = FLUSH);

    // TODO: BackgroundColor entfernen
    void putString(Point p, char const *s, Color textColor, Color background, bool flush = FLUSH);

    // TODO: BackgroundColor entfernen
    void putNumber(	Point p, HAL::U64 value, Color foreground, Color background,
    				HAL::U8 base = 10, bool flush = FLUSH);
};

//Todo TrueColor Display implementieren
template<typename ShadowDisplay, typename DisplayHAL>
class Display<ShadowDisplay, DisplayHAL, true> 
: public DisplayHAL
{
	// ohne Palette
};

//=====================================================================
template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void Display<ShadowDisplay, DisplayHAL, trueColor>::drawLine( Point p0, Point p1,
						Color color, bool bflush) {

	bool verticalLine = p0.x == p1.x;
    bool horizontalLine = p0.y == p1.y;
    // bool onlyOnePoint = verticalLine && horizontalLine;
    Point p_0(p0), p_1(p1);

    //von rechts nach links zeichnen
    if(p_0.x > p_1.x || (p_0.x == p_1.x && p_0.y > p_1.y))
        std::swap(p_0, p_1);

    adjustRanges(p_0, p_1);

//    size_t x0 = p_0.x, y0 = p_0.y, x1 = p_1.x, y1 = p_1.y;

    if(horizontalLine) {
        drawHorizontalLine(p0, p1.x, color);
    } else if(verticalLine) {
        drawVerticalLine(p0, p1.y, color);
	} else {
		double x = p0.x;
		double y = p0.y;

		double m = ((static_cast<double>(p1.y) - p0.y)
                    / (p1.x - p0.x));

		//flache Steigungen < 45Grad
        if (m <= 1 && m >= -1) {
			for(size_t u = p0.x; u < p1.x; u++) {
				sD.setPixel(u, static_cast<int>(y), color);
				y += m;
                if(y >= ShadowDisplay::HEIGHT) break;
			}
		} else {//steile Steigungen > 45Grad
			m = 1/m;
			for(size_t u = p0.y; u < p1.y; u++) {
				sD.setPixel(static_cast<int>(x), u, color);
				x += m;
                if(x >= ShadowDisplay::WIDTH) break;
			}
		}
	}
	if(bflush) flush(p0, p1);
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void Display<ShadowDisplay, DisplayHAL, trueColor>::fillRectangle(
							Point p0, Point p1, Color color, bool bflush)
{
    adjustParams(p0, p1);

    for(size_t x = p0.x; x < p1.x; ++x)
        for(size_t y = p0.y; y < p1.y; ++y)
            sD.setPixel(x, y, color);

    if(bflush) flush(p0, p1);
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void Display<ShadowDisplay, DisplayHAL, trueColor>::drawRectangle(
					Point p0, Point p1, Color color, bool bflush)
{
    adjustPoints(p0, p1);
    //adjustRanges
//    U16 x0 = p0.x, y0 = p0.y, x1 = p1.x, y1 = p1.y;
    //rechter Rand
    //U16 x

    drawHorizontalLine(p0, p1.x, color);
    drawHorizontalLine(Point(p0.x, p1.y-1), p1.x, color);
    drawVerticalLine(p0, p1.y, color);

    if(p1.x < ShadowDisplay::WIDTH)
        drawVerticalLine(Point(p1.x-1, p0.y), p1.y, color);

	if(bflush) flush(p0, p1);
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void Display<ShadowDisplay, DisplayHAL, trueColor>::fillEllipse(
			Point p0, Point p1, Color color, bool bflush)
{
	int x,y;

	size_t x0 = p0.x, y0 = p0.y, x1 = p1.x, y1 = p1.y;

	adjustParams(p0, p1);

	const int XMAX = x1 - x0;
	const int YMAX = y1 - y0;

	double hx = (static_cast<double>(XMAX) / 2);
	double hy = (static_cast<double>(YMAX) / 2);

	for(x = 0; x < XMAX; ++x) {

		double a = std::pow((((1/hx) * (x + 0.5)) - 1), 2);
		double b = (std::sqrt(1-a) + 1);
		int f1 = static_cast<int>((-hy * b + (2 * hy)));
		int f2 = static_cast<int>((hy * b));

		for(y = f1; y <= f2 && y < YMAX ; ++y) {
			sD.setPixel(x + x0, y + y0, color);
		}
	}
    if(bflush) flush(p0, p1);
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void Display<ShadowDisplay, DisplayHAL, trueColor>::drawEllipse(
				Point p0, Point p1, Color color, bool bflush)
{
	int x,y;

	size_t x0 = p0.x, y0 = p0.y, x1 = p1.x, y1 = p1.y;

	adjustParams(p0, p1);

	const int XMAX = x1 - x0;
	const int YMAX = y1 - y0;

	double hx = (static_cast<double>(XMAX) / 2);
	double hy = (static_cast<double>(YMAX) / 2);

	for(x = 0; x < XMAX; ++x) {

		double a = std::pow((((1/hx) * (x + 0.5)) - 1), 2);
		double b = (std::sqrt(1-a) + 1);
		int f1 = static_cast<int>((-hy * b + (2 * hy)));
		int f2 = static_cast<int>((hy * b));

		sD.setPixel(x + x0, y0 + static_cast<int>(f1), color);

		if(f2 < YMAX) {
			sD.setPixel(x + x0, y0 + static_cast<int>(f2), color);
		} else {
			sD.setPixel(x + x0, y0 + static_cast<int>(f2) - 1, color);
		}
	}

	std::swap(hx, hy);

	for(y = 0; y < YMAX; ++y) {

		double a = std::pow((((1/hx) * (y + 0.5)) - 1), 2);
		double b = (std::sqrt(1-a) + 1);
		int f1 = static_cast<int>((-hy * b + (2 * hy)));
		int f2 = static_cast<int>((hy * b));

		sD.setPixel(x0 + static_cast<int>(f1), y0 + y, color);

		if(f2 < XMAX) {
			sD.setPixel(x0 + static_cast<int>(f2), y0 + y, color);
		} else {
			sD.setPixel(x0 + static_cast<int>(f2) - 1, y0 + y, color);
		}
	}
    if(bflush) flush(p0, p1);
}

//TODO: background entfernen
template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void Display<ShadowDisplay, DisplayHAL, trueColor>::putString(
				Point p, char const *s, Color textColor, Color background, bool bflush) {
	HAL::U8 l = 0;

	while (*s) {
		putChar8x16(Point(p.x + l * 8, p.y), *s, textColor, background);
			++s;
			++l;
	}
	// if(bflush) flush(x0, y0, x0 + 8, y0 + 16);
}

template<typename ShadowDisplay, typename DisplayHAL, bool trueColor>
void Display<ShadowDisplay, DisplayHAL, trueColor>::putNumber(
				Point p, HAL::U64 value,
				Color foreground, Color background, HAL::U8 base, bool flush)
    {
            char buffer[sizeof(HAL::U64) * 8 + 1];
            putString(p, value2string(value, base, buffer), foreground, background, flush);
    }
// template <typename T>
// void swap(T& v1, T& v2){
// }
*/
}//end namespace GraphicDevice
#endif // __DISPLAY_H__ 
