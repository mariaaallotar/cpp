
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:44:36 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/23 11:45:10 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(int const value) : _value(value) {
	std::cout << "Int constructor called" << std::endl;
	std::cout << "Value: " << _value << std::endl;		//remove this
	std::cout << "Fractionl bits: " << _factorialBits << std::endl;		//remove this
};

int power(int base, int exp)  {
	if (exp < 0)
		return (0);
	else if (exp == 0)
		return (1);
	int i = 0;
	int res = 1;
	while (i < exp)
	{
		res = res * base;
		i++;
	}
	return (res);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(power(2, this->_factorialBits) * value);
};

Fixed::Fixed(const Fixed &other) : _value(other.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Value: " << _value << std::endl;		//remove this
	std::cout << "Fractionl bits: " << _factorialBits << std::endl;		//remove this
};

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_value = other.getRawBits();
	}
	std::cout << "Value: " << _value << std::endl;		//remove this
	std::cout << "Fractionl bits: " << _factorialBits << std::endl;		//remove this
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat(void) const {
	return (this->getRawBits() / (1 << this->_factorialBits));
}

int Fixed::toInt(void) const {
	return (this->getRawBits() / (1 << this->_factorialBits));
}