#include "Point.hpp"
#include <cstdlib>

int main(int ac, char **av) {
	if (ac != 9) {
		std::cout << "Usage: ./bsp <a_x> <a_y> <b_x> <b_y> <c_x> <c_y> <p_x> <p_y>" << std::endl;
		return 1;
	}
	Point a((float)atof(av[1]), (float)atof(av[2]));
	Point b((float)atof(av[3]), (float)atof(av[4]));
	Point c((float)atof(av[5]), (float)atof(av[6]));
	Point point((float)atof(av[7]), (float)atof(av[8]));
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}
