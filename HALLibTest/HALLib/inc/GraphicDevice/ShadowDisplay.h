#ifndef __SHADOWDISPLAY_H__
#define __SHADOWDISPLAY_H__

//#define SD_DEBUG_OUT

#ifdef SD_DEBUG_OUT
#include <iostream>
#endif

#include <HAL/Typedefs.h>

#include <Generator/CreateComponent.h>
#include <HAL/ComponentTypes.h>
#include <HAL/Point.h>
#include <CommonComponents/CommonComponentTypes.h>


namespace GraphicDevice{
	// ForwardDeclarations
	template<typename DisplayHAL, HAL::U32 NUMCOLORS_>
	class ShadowDisplay;

	template<typename DisplayHAL, unsigned int NumBitsPerColor>
	struct ColorTraits;
}

namespace Generator {
	template<class Origin, class ConfigRepository>
	struct Component<CS<CommonComponents::ShadowDisplay, SelectorDefault>, Origin, ConfigRepository>
	{
		typedef typename ConfigRepository::Platform::board_type board_type;
		typedef typename ConfigRepository::Platform::prozessor_type prozessor_type;
		typedef DD<CommonComponents::Display, CS<board_type, prozessor_type> > DisplayHALContext;
		typedef typename Create<DisplayHALContext, ConfigRepository, DisplayHALContext>
		::type DisplayHAL;
//		typedef typename Generator::DD::Create<
//				CommonComponents::Display,
//				Generator::CS<board_type, prozessor_type>,
//				Generator::Adapter, ConfigRepository>
//		::type DisplayHAL;
//		typedef typename Create<BoardType, CommonComponents::DisplayHAL, ConfigRepository>::type DisplayHAL;
		typedef GraphicDevice::ShadowDisplay<DisplayHAL, ConfigRepository::Display::NumBitsPerColor> type;
	};
} // namespace Generator

namespace GraphicDevice{

template<typename DisplayHAL>
struct ColorTraits<DisplayHAL, 4>{
	enum {
		WIDTH = ((DisplayHAL::WIDTH + 1) / 2),
		HEIGHT = DisplayHAL::HEIGHT,
		NumColors = 0xF
	};
	typedef unsigned char ColorIndexType;
	typedef typename DisplayHAL::Point Point;
};
template<typename DisplayHAL>
struct ColorTraits<DisplayHAL, 8>{
	enum {
		WIDTH = DisplayHAL::WIDTH,
		HEIGHT = DisplayHAL::HEIGHT,
		NumColors = 0xFF
	};
	typedef unsigned char ColorIndexType;
	typedef typename DisplayHAL::Point Point;
};
template<typename DisplayHAL>
struct ColorTraits<DisplayHAL, 16>{
	enum {
		WIDTH = DisplayHAL::WIDTH,
		HEIGHT = DisplayHAL::HEIGHT,
		NumColors = 0xFFFF
	};
	typedef unsigned short ColorIndexType;
	typedef typename DisplayHAL::Point Point;
};
template<typename DisplayHAL>
struct ColorTraits<DisplayHAL, 32>{
	enum {
		WIDTH = DisplayHAL::WIDTH,
		HEIGHT = DisplayHAL::HEIGHT,
		NumColors = 0xFFFFFFFF
	};
	typedef unsigned int ColorIndexType;
	typedef typename DisplayHAL::Point Point;
};


//=======================================================
template<typename Color_Traits>
class ShadowDisplayBase{
public:
	typedef Color_Traits ColorTraits;
	typedef ShadowDisplayBase<ColorTraits> type;

	enum { HEIGHT = ColorTraits::HEIGHT, WIDTH = ColorTraits::WIDTH };
	enum { NumColors = ColorTraits::NumColors };

	typedef typename ColorTraits::ColorIndexType ColorIndexType;
	typedef typename ColorTraits::Point Point;
	typedef typename Point::sizetype size_t;
protected:
	ColorIndexType display[HEIGHT][WIDTH];
public:
	ShadowDisplayBase() {
		init();
	}

	ShadowDisplayBase(type const& source) {
		copy(source);
	}

	void init() {
		for (size_t y = 0; y < HEIGHT; ++y) {
			for (size_t x = 0; x < WIDTH; ++x) {
				display[y][x] = ColorIndexType();
			}
		}
	}

	void setPixel(Point p, ColorIndexType color) {
		setPixel(p.x, p.y, color);
	}

	void setPixel(size_t x, size_t y, ColorIndexType color) {

#ifdef SD_DEBUG_OUT
		if(x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
			std::cout << std::endl << "Point out of Range<Base> (" << static_cast<int>(x) << ", " << static_cast<int>(y) << ")";
#endif

		display[y][x] = color;
	}

	ColorIndexType getPixel(Point p) {
		return getPixel(p.x, p.y);
	}

	ColorIndexType getPixel(size_t x, size_t y) {
		return display[y][x];
	}

	bool operator==(type const& rhs){
		bool retVal = false;
		for(size_t y = 0; y < HEIGHT; ++y){
			for(size_t x = 0; x < WIDTH; ++x){
				retVal = display[y][x] == rhs.display[y][x];
				if(!retVal) break;
			}
			if(!retVal) break;
		}
		return retVal;
	}
private:
	void copy(type const& source) {
		for (size_t y = 0; y < HEIGHT; ++y) {
			for (size_t x = 0; x < WIDTH; ++x) {
				display[y][x] = source.display[y][x];
			}
		}
	}
};
//=======================================================
template<typename DisplayHAL, unsigned int NumBitsPerColor>
class ShadowDisplay : public ShadowDisplayBase<ColorTraits<DisplayHAL, NumBitsPerColor> >
{};

template<typename DisplayHAL>
class ShadowDisplay<DisplayHAL, 4> : public ShadowDisplayBase<ColorTraits<DisplayHAL, 4> >
{
public:
	typedef ShadowDisplayBase<ColorTraits<DisplayHAL, 4> > base_type;
	typedef ShadowDisplay<DisplayHAL, 4> type;

	typedef typename base_type::ColorIndexType ColorIndexType;
	typedef typename base_type::Point Point;
	typedef typename Point::sizetype size_t;
	using base_type::display;

	enum { MASK = 0x0F };

	void setPixel(size_t x, size_t y, typename base_type::ColorIndexType color) {
		setPixel(Point(x, y), color);
	}

	void setPixel(Point p, ColorIndexType color) {
		size_t x = p.x, y = p.y;

		bool lowerHalfByte = (x % 2 == 0);
		size_t xHalbe = x/2;

#ifdef SD_DEBUG_OUT
		if(x < 0 || x > DisplayHAL::WIDTH || y < 0 || y > DisplayHAL::HEIGHT)
					std::cout << std::endl << "Point out of Range<4> (" << static_cast<int>(x) << ", " << static_cast<int>(y) << ")";
#endif

		if (lowerHalfByte) {
			display[y][xHalbe] &= ~MASK;
			display[y][xHalbe] |= (color & MASK);
		} else {
			display[y][xHalbe] &= ~(MASK << 4);
			display[y][xHalbe] |= (color << 4);
		}
	}
	
	ColorIndexType getPixel(size_t x, size_t y) {
		return getPixel(Point(x, y));
	}

	ColorIndexType getPixel(Point p) {
		size_t x = p.x, y = p.y;
		bool lowerHalfByte = (x % 2 == 0);
		if (lowerHalfByte) {
			return (display[y][x/2] & MASK);
		} else {
			return (display[y][x/2] >> 4);
		}
	}
	
};
} // end namespace GraphicDevice
#endif // __SHADOWDISPLAY_H__
