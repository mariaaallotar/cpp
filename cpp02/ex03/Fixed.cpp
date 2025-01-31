/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:49:59 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/31 14:00:55 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-----------------------------*/
/*---Orthodox Canonical Form---*/
/*-----------------------------*/

Fixed::Fixed() : _value(0) {};

Fixed::Fixed(int const value) : _value(this->toRawBits(value)) {};

Fixed::Fixed(const float value) : _value(this->toRawBits(value)){};

Fixed::Fixed(const Fixed &other) : _value(other.getRawBits()) {};

Fixed & Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
};

Fixed::~Fixed() {};

/*----------------------------*/
/*---class member functions---*/
/*----------------------------*/

int Fixed::getRawBits(void) const {
    return (this->_value);
};

void Fixed::setRawBits(int const raw) {
    this->_value = ((raw * (1 << this->_factorialBits)));
};

void Fixed::setRawBits(float const raw) {
	this->_value = ((int)roundf(raw * (1 << this->_factorialBits)));
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

/*--------------------------*/
/*---comparison operators---*/
/*--------------------------*/

bool Fixed::operator>(const Fixed &number) const {
	return (this->_value > number._value);
}

bool Fixed::operator>=(const Fixed &number) const {
	return (this->_value >= number._value);
}

bool Fixed::operator<(const Fixed &number) const {
	return (this->_value < number._value);
}

bool Fixed::operator <=(const Fixed &number) const {
	return (this->_value <= number._value);
}

bool Fixed::operator ==(const Fixed &number) const {
	return (this->_value == number._value);
}

bool Fixed::operator !=(const Fixed &number) const {
	return (this->_value != number._value);
}

/*--------------------------*/
/*---arithmetic operators---*/
/*--------------------------*/

float Fixed::operator+(const Fixed &number) const {
	return (this ->toFloat() + number.toFloat());
}

float Fixed::operator-(const Fixed &number) const {
	return (this ->toFloat() - number.toFloat());
}

float Fixed::operator*(const Fixed &number) const {
	return (this ->toFloat() * number.toFloat());
}

float Fixed::operator/(const Fixed &number) const {
	return (this ->toFloat() / number.toFloat());
}

/*-------------------------*/
/*---increment operators---*/
/*-------------------------*/

Fixed & Fixed::operator++(void) {
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_value++;
	return(temp);
}

/*-------------------------*/
/*---decrement operators---*/
/*-------------------------*/

Fixed & Fixed::operator--(void) {
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

/*---------------------------------------*/
/*---static min & max member functions---*/
/*---------------------------------------*/

Fixed & Fixed::min(Fixed & a, Fixed & b) {
	return (a < b ? a : b);
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b) {
	return (a < b ? a : b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
	return (a > b ? a : b);
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b) {
	return (a > b ? a : b);
}

/*---------------------------------*/
/*---insertion operator overload---*/
/*---------------------------------*/

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
};