#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::~Point() {}

const Fixed Point::getX() const {
	return this->_x;
}

const Fixed Point::getY() const {
	return this->_y;
}

Point &Point::operator=(const Point &point) {
	if (this != &point) {
		*(const_cast<Fixed *>(&this->_x)) = point._x;
		*(const_cast<Fixed *>(&this->_y)) = point._y;
	}
	return *this;
}
