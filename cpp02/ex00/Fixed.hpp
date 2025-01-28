
#pragma once

#include <iostream>

class Fixed {

	private:
		int _value;
		static const int _factorialBits = 8;
	
	public:
		Fixed(int value = 0);
		Fixed(const Fixed &original);
		Fixed &operator=(const Fixed &other);
		~Fixed();
};