#ifndef TEXTCONTROL_H_
#define TEXTCONTROL_H_

#include <cstring>

namespace GraphicDevice {
template<class Display_>
class TextControl{
	typedef Display_ Display;
	typedef typename Display::Point Point;
	typedef typename Display::Color Color;

	Point pos1;
	unsigned int numChar;
	bool autoSize;
	Point pos2;
	Color forground;
	Color background;
public:
	TextControl(Point pos, unsigned int numChar=0,
			Color forground=1, Color background=15)
	: pos1(pos), numChar(numChar), autoSize(!numChar),
	  pos2(pos1.x+numChar*8, pos1.y+16),
	  forground(forground), background(background)
	{}
	void showText(char const* message){
		Display display = Display::getInstance();

		if(autoSize){
			std::size_t pos2x = pos1.x + std::strlen(message) * 8;
			if(pos2x < pos2.x)
				display.fillRectangle(pos1, pos2, background);
			pos2.x = pos2x;
		}
		display.fillRectangle(pos1, pos2, background, false);
		display.putString(pos1, message, forground, false);
		display.flush(pos1, pos2);
	}
	void showNumber(unsigned long num, unsigned char base = 10){
		char buffer[33] = "                    ";
		Display::value2string(num, buffer, base);
		this->showText(buffer);

	}
};

}//namespace GraphicDevice
#endif /* TEXTCONTROL_H_ */
