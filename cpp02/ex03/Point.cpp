/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:40:03 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/03 12:58:06 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {};

Point::Point(float x, float y) : _x(Fixed(x)), _y(Fixed(y)) {};

Point::Point(const Point &other) : _x(other._x), _y(other._y) {};

Point & Point::operator=(const Point & other) {
    if (this != &other)
	{
		this-> ~Point();
      	new(this) Point(other);
	}
	return (*this);
}

Point::~Point() {};

const Fixed Point::getX() {
	return (this->_x);
};

const Fixed Point::getY() {
	return (this->_y);
}