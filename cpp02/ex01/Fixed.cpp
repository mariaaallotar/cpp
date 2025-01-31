
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

Fixed::Fixed(int const value) : _value(this->toRawBits(value)) {
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float value) : _value(this->toRawBits(value)){
	std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(const Fixed &other) : _value(other.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
};

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const {
    return (this->_value);
};

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
};

int Fixed::toRawBits(const int value) {
	return (value * (1 << _factorialBits));
}

int Fixed::toRawBits(const float value) {
	return ((int)roundf(value * (1 << _factorialBits)));
}

float Fixed::toFloat(void) const {
	return (this->getRawBits() / (float) (1 << this->_factorialBits));
};

int Fixed::toInt(void) const {
	return (this->getRawBits() / (1 << this->_factorialBits));
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
};