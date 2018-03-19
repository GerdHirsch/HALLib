#ifndef __POINT_H__
#define __POINT_H__


namespace HAL
{
	template<typename sizeT>
	struct Point
	{
		typedef sizeT sizetype;
		Point():x(0),y(0){}
		Point(Point const& p):x(p.x),y(p.y){}

		template<typename U>
		Point(Point<U> const& p):x(p.x), y(p.y){}

		Point(sizetype x, sizetype y):x(x),y(y){}
		bool operator==(Point const& rhs){
			return x == rhs.x && y == rhs.y;
		}

		sizetype x;
		sizetype y;
	};
}
#endif //__POINT_H__
