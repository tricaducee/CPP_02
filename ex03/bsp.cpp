#include "Point.hpp"

bool sameSide(Point const a, Point const b, Point const p1, Point const p2) {
	Fixed vp1 = (b.getX() - a.getX()) * (p1.getY() - a.getY()) - (b.getY() - a.getY()) * (p1.getX() - a.getX());
	Fixed vp2 = (b.getX() - a.getX()) * (p2.getY() - a.getY()) - (b.getY() - a.getY()) * (p2.getX() - a.getX());
	return (vp1 * vp2) >= 0;
};

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	return sameSide(a, b, c, point) && sameSide(b, c, a, point) && sameSide(c, a, b, point);
};
