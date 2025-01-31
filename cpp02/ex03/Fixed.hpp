/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:40:39 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/31 14:00:53 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int _value;
		static const int _factorialBits = 8;
	
	public:
		/*---Orthodox Canonical Form---*/
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);
		/*---class member functions---*/
        int getRawBits(void) const;
        void setRawBits(const int raw);
		void setRawBits(const float raw);
		static int toRawBits(const int value);
		static int toRawBits(const float value);
		float toFloat(void) const;
		int toInt(void) const;
		/*---comparison operators---*/
		bool operator>(const Fixed &number) const;
		bool operator>=(const Fixed &number) const;
		bool operator<(const Fixed &number) const;
		bool operator<=(const Fixed &number) const;
		bool operator==(const Fixed &number) const;
		bool operator!=(const Fixed &number) const;
		/*---arithmetic operators---*/
		float operator+(const Fixed &number) const;
		float operator-(const Fixed &number) const;
		float operator*(const Fixed &number) const;
		float operator/(const Fixed &number) const;
		/*---increment operators---*/
		Fixed &operator++(void);	//pre
		Fixed operator++(int);		//post
		/*---decrement operators---*/
		Fixed &operator--(void);	//pre
		Fixed operator--(int);		//post
		/*---static min & max member functions---*/
		static Fixed & min(Fixed & a, Fixed & b);
		static const Fixed & min(const Fixed & a, const Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static const Fixed & max(const Fixed & a, const Fixed & b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);