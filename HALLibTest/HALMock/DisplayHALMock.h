#ifndef DISPLAYHALMOCK_H_
#define DISPLAYHALMOCK_H_

#include <iostream>
#include <Generator/CreateComponent.h>
#include <Generator/BaseType.h>
#include <CommonComponents/CommonComponentTypes.h>
#include <HAL/Point.h>

#include <HALMock/Types.h>
//#include <LPC21xx/Types.h>

#include "GraphicDevice/ShadowDisplay.h"

namespace Mock
{
	struct BoardMock:Generator::SelectorBase<>{};

	class DisplayHALMock;
}

namespace Generator {
template<class Origin, class ConfigRepository>
struct Component<DD<CommonComponents::Display, CS<Mock::BoardMock, Mock::Base> >, Origin, ConfigRepository>
{
	typedef Mock::DisplayHALMock type;
};
//} // namespace DD
////namespace SD {
////	template<class BoardType, class ConfigRepository>
////	struct Component<Mock::BoardMock, CommonComponents::DisplayHAL, BoardType, ConfigRepository>
////	{
////		typedef Mock::DisplayHALMock type;
////	};
} // namespace Generator

namespace Mock
{
	class DisplayHALMock {

	public:
		typedef HAL::U16 Color;
		typedef HAL::U8 size_t;
		struct EmptyDisplay{
			enum{ HEIGHT = 50, WIDTH = 50 };
			typedef HAL::Point<size_t> Point;
		};
		typedef EmptyDisplay::Point Point;
		typedef GraphicDevice::ShadowDisplay<EmptyDisplay, 16> ShadowDisplay_;

		enum {

				Red = 0xF800, Red2 = 0xFC00,
				Green = 0x07C0, Green2 = 0x0400, Green3 = 0x0FF0,
				Blue = 0x003E, Blue2 = 0x051F,

				White = Red|Green|Blue,
				White2 = 0xF7BC,
				Gray = 0xE738,

				Yellow = 0xFFE0, Yellow2 = 0xF700,
				Black = 0x0000,
				Magenta = 0xF81F,
				Cyan = 0x7FFF,
				Brown = 0x8400
			};
	private:
		struct Area{
			Point p0, p1;
//			size_t x0, y0;
//			size_t x1, y1;
			bool operator==(Area const& rhs){
				return p0 == rhs.p0 && p1 == rhs.p1;
			}
		};

		Point currentPoint;

	public:

		DisplayHALMock():currentPoint(0,0), state(NoTracking) {}
		// -----------------------
		//DisplayHALInterface
		enum{ HEIGHT = EmptyDisplay::HEIGHT, WIDTH = EmptyDisplay::WIDTH};

		static void setPixel(Color color){
			instance->setPixel_(color);
		}

		void setPixel_(Color color) {
			switch(state) {
				case BeginInit:
					expected.setPixel(currentPoint, color);
					++currentPoint.x;
					if(currentPoint.x >= initArea.p1.x) {
						currentPoint.x = initArea.p0.x;
						++currentPoint.y;
					}
				break;
				case BeginTest:
					result.setPixel(currentPoint, color);
					++currentPoint.x;
					if(currentPoint.x >= initArea.p1.x) {
						currentPoint.x = initArea.p0.x;
						++currentPoint.y;
					}
				break;
				default:
				break;
			}
		}

		static void setArea(size_t x0, size_t y0, size_t x1, size_t y1){
			instance->setArea(Point(x0,y0), Point(x1, y1));
		}

		static void setArea(Point p0, Point p1) {
			instance->setArea_(p0, p1);
		}

		void setArea_(Point p0, Point p1) {
			switch(state) {
				case BeginInit:
					initArea.p0 = p0;
					initArea.p1 = p1;
					currentPoint = p0;
					break;
				case BeginTest:
//					testArea.p0 = Point(p0.x, p0.y);
//					testArea.p1 = Point(p1.x - 2, p1.y - 2);
					testArea.p0 = p0;
					testArea.p1 = p1;
					currentPoint = p0;
					break;
				default:
				break;
			}
		}

	private:
		enum State {
				BeginInit, NoTracking, BeginTest
		};

		State state;


		// -----------------------
		// MockInterface
	public:
		static DisplayHALMock* instance;
		Area initArea;
		Area testArea;
		ShadowDisplay_ expected;
		ShadowDisplay_ result;

		void setPixel(Point p, Color color){
			expected.setPixel(p, color);
		}

		bool wasSuccesful() {
			// TODO expected == result
			bool retVal = false;

			bool bArea = initArea == testArea;
			bool bContent = expected == result;

			retVal = bArea && bContent;

			return retVal;
		}

		void beginInit() {
			// aufrufe speichen in expected
			state = BeginInit;
	//		expected.init();
	//		result.init();
		}

		void endInit() {
			// keine weitere Speicherung der Aufrufe
			state = NoTracking;
		}

		void beginTest() {
			// die aufrufe in resultMessageInfos speichern
			state = BeginTest;
		}

		void endTest() {
			state = NoTracking;
		}
		void print(){
			std::cout << std::endl << "Expected:"<< std::endl;
			print(expected);
			std::cout << "Result:"<< std::endl;
			print(result);
		}
		void print(ShadowDisplay_& sD){
			Color color;
			for(size_t y = 0; y < ShadowDisplay_::HEIGHT; ++y){
				for(size_t x = 0; x < ShadowDisplay_::WIDTH; ++x){
					color = sD.getPixel(x, y);
					if(color == 0 || color == '0')
						std::cout << ".";
					else
						std::cout << static_cast<unsigned char>(color);
				}
				std::cout << std::endl;
			}
		}
	};
}
#endif /* DISPLAYHALMOCK_H_ */
