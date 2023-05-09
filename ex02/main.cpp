#include "Fixed.hpp"
#include <cstdlib>

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	Fixed n1(0.5f);
// 	Fixed n2((int)3);
// 	Fixed n3(n1 * n2);
// 	Fixed nb1((int)5);
// 	Fixed nb2((int)2);
// 	Fixed nb3(nb1 / nb2);
// 	std::cout << n1 << " * " << n2 << " = " << n1 * n2 << std::endl;
// 	std::cout << n1 << " * " << n2 << " = " << n3 << std::endl;
// 	std::cout << nb1 << " / " << nb2 << " = " << nb1 / nb2 << std::endl;
// 	std::cout << nb1 << " / " << nb2 << " = " << nb3 << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int main(int ac, char **av) {
	if (ac != 3) {
		std::cout << "Usage: ./fixed <num1> <num2>" << std::endl;
		return 1;
	}
	Fixed a((float)atof(av[1]));
	Fixed b((float)atof(av[2]));
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	return 0;
}
