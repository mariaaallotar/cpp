
#include "Fixed.hpp"

Fixed::Fixed(int value) : _value(value) {
	std::cout << "Default constructor called" << std::endl;
	std::cout << "Value: " << _value << std::endl;		//remove this
	std::cout << "Fractionl bits: " << _factorialBits << std::endl;		//remove this
};

Fixed::Fixed(const Fixed &other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Value: " << _value << std::endl;		//remove this
	std::cout << "Fractionl bits: " << _factorialBits << std::endl;		//remove this
};

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other._value;
	}
	std::cout << "Value: " << _value << std::endl;		//remove this
	std::cout << "Fractionl bits: " << _factorialBits << std::endl;		//remove this
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}