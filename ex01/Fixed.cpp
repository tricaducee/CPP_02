#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
};

Fixed::Fixed(const int value) : _value(value << this->_bits) {
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float value) : _value(roundf(value * (1 << this->_bits))) {
	std::cout << "Float constructor called" << std::endl;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

int Fixed::toInt() const {
	return this->_value >> this->_bits;
};

float Fixed::toFloat() const {
	return (float)this->_value / (float)(1 << this->_bits);
};

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
};

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
};

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Assignation operator called" << std::endl;
	this->_value = fixed.getRawBits();
	return *this;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
};
