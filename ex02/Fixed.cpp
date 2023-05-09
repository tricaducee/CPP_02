#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &fixed) : _value(fixed.getRawBits()) {};

Fixed::Fixed(const int value) : _value(value << this->_bits) {};

Fixed::Fixed(const float value) : _value(roundf(value * (1 << this->_bits))) {};

Fixed::~Fixed() {};

int Fixed::toInt() const {
	return this->_value >> this->_bits;
};

float Fixed::toFloat() const {
	return (float)this->_value / (float)(1 << this->_bits);
};

int Fixed::getRawBits() const {
	return this->_value;
};

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
};

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return a > b ? a : b;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	this->_value = fixed.getRawBits();
	return *this;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
};

bool Fixed::operator>(const Fixed &fixed) const {
	return this->_value > fixed.getRawBits();
};

bool Fixed::operator<(const Fixed &fixed) const {
	return this->_value < fixed.getRawBits();
};

bool Fixed::operator>=(const Fixed &fixed) const {
	return this->_value >= fixed.getRawBits();
};

bool Fixed::operator<=(const Fixed &fixed) const {
	return this->_value <= fixed.getRawBits();
};

bool Fixed::operator==(const Fixed &fixed) const {
	return this->_value == fixed.getRawBits();
};

bool Fixed::operator!=(const Fixed &fixed) const {
	return this->_value != fixed.getRawBits();
};

Fixed Fixed::operator+(const Fixed &fixed) const {
	Fixed ret;
	ret.setRawBits(this->_value + fixed.getRawBits());
	return ret;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	Fixed ret;
	ret.setRawBits(this->_value - fixed.getRawBits());
	return ret;
}

// Fixed Fixed::operator*(const Fixed &fixed) const {
// 	return Fixed(this->toFloat() * fixed.toFloat());
// }

// Fixed Fixed::operator/(const Fixed &fixed) const {
// 	return Fixed(this->toFloat() / fixed.toFloat());
// }

Fixed Fixed::operator*(const Fixed &fixed) const {
	Fixed ret;
	ret.setRawBits((this->_value * fixed.getRawBits()) >> this->_bits);
	return ret;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	Fixed ret;
	ret.setRawBits((this->_value << this->_bits) / fixed.getRawBits());
	return ret;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++this->_value;
	return temp;
}

Fixed &Fixed::operator++() {
	++this->_value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--this->_value;
	return temp;
}

Fixed &Fixed::operator--() {
	--this->_value;
	return *this;
}
