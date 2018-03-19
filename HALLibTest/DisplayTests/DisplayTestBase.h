#ifndef DISPLAYTESTBASE_H_
#define DISPLAYTESTBASE_H_

#include "DisplayTestApp.h"

class DisplayTestBase : public CPPUNIT_NS::TestFixture {
public:
	typedef HAL::PlatformRepository<
			Mock::BoardMock,
			Mock::Base,
			GraphicDevice::DisplayConfigurationRepository<4> >
	ConfigRep;
//	struct ConfigRep : GraphicDevice::DisplayConfigurationRepository<4>{
//		typedef ConfigRep Platform;
//		typedef LPC21xx::Base prozessor_type;
//		typedef Mock::BoardMock board_type;
//	};
	typedef Generator::Create<CommonComponents::Display, ConfigRep>
	::type Display;
	typedef Generator::Create<
			Generator::DD<CommonComponents::Display,
			Generator::CS<ConfigRep::board_type, ConfigRep::prozessor_type> >,
			ConfigRep>
	::type DisplayHALMock;

	typedef Display::ColorHAL ExpectedType;
	typedef Display::size_t size_t;
	typedef Display::Point Point;

	enum {WIDTH = Display::WIDTH, HEIGHT = Display::HEIGHT};

	void setUp (void);
	void tearDown (void);

protected:
	Display* testDisplay;
	DisplayHALMock* mock;
	void compareExpectedResult();

	// TODO: statt double typ von Pont nehmen
	void drawHorizontalLine(Point p0, double x1, ExpectedType color) {
		for(int x = p0.x; x < x1; ++x)
			mock->setPixel(Point(x, p0.y), color);
	}

	// TODO: statt double typ von Pont nehmen
	void drawVerticalLine(Point p0, double y1, ExpectedType color) {
		for(int y = p0.y; y < y1; ++y)
			mock->setPixel(Point(p0.x, y), color);
	}
};

#endif /* DISPLAYTESTBASE_H_ */
