#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Point &point);
		Point(const float x, const float y);
		~Point();
		Point &operator=(const Point &point);
		const Fixed getX() const;
		const Fixed getY() const;
	private:
		Fixed const _x;
		Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif