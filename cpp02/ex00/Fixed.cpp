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

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &other) : _value(other._value) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}