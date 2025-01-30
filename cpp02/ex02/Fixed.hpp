/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:40:39 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/30 15:44:15 by maheleni         ###   ########.fr       */
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
		Fixed(const Fixed &original);
		Fixed &operator=(const Fixed &other);
		~Fixed(void);
		/*---class member functions---*/
        int getRawBits(void) const;
        void setRawBits(const int raw);
		void setRawBits(const float raw);
		int toRawBits(const int value);
		int toRawBits(const float value);
		float toFloat(void) const;
		int toInt(void) const;
		/*---operators---*/
		bool operator>(const Fixed &number) const;
		bool operator>=(const Fixed &number) const;
		bool operator<(const Fixed &number) const;
		bool operator<=(const Fixed &number) const;
		bool operator==(const Fixed &number) const;
		bool operator!=(const Fixed &number) const;
		float operator+(const Fixed &number) const;
		float operator-(const Fixed &number) const;
		float operator*(const Fixed &number) const;
		float operator/(const Fixed &number) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);