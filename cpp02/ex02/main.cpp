/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:26:50 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/31 13:12:54 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

    std::cout << "\nComparison operators:" << std::endl;
    {
        Fixed a(1.121f);
        Fixed b(1.123f);
        std::cout << "a: " << a.toFloat() << " b: " << b.toFloat() << std::endl;
        std::cout << a.toFloat() << " < " << b.toFloat() << " : " << ((a < b) ? "true" : "false") << std::endl;
        std::cout << a.toFloat() << " <= " << b.toFloat() << " : " << ((a <= b) ? "true" : "false") << std::endl;
        std::cout << a.toFloat() << " > " << b.toFloat() << " : " << ((a > b) ? "true" : "false") << std::endl;
        std::cout << a.toFloat() << " >= " << b.toFloat() << " : " << ((a >= b) ? "true" : "false") << std::endl;
        std::cout << a.toFloat() << " == " << b.toFloat() << " : " << ((a == b) ? "true" : "false") << std::endl;
        std::cout << a.toFloat() << " != " << b.toFloat() << " : " << ((a != b) ? "true" : "false") << std::endl;
    }

    std::cout << "\nArithmetic operators:" << std::endl;
    {
        Fixed a(1000.1f);
        Fixed const b( Fixed( 100 ) * Fixed( 10 ) );
        std::cout << a.toFloat() << "+" << b.toFloat() << "=" << (a + b) << std::endl;
        std::cout << a.toFloat() << "-" << b.toFloat() << "=" << (a - b) << std::endl;
        std::cout << a.toFloat() << "*" << b.toFloat() << "=" << (a * b) << std::endl;
        std::cout << a.toFloat() << "/" << b.toFloat() << "=" << (a / b) << std::endl;
    }
    
    std::cout << "\nIncrement operators:" << std::endl;
    {
        Fixed a;
        std::cout << "The original: " << "\n\t" << a << std::endl;
        std::cout << "Pre increment: increments then prints: " << "\n\t" << ++a << std::endl;
        std::cout << "The value now: " << "\n\t" << a << std::endl;
        std::cout << "Post increment: prints then increments: " << "\n\t" << a++ << std::endl;
        std::cout << "The value now: " << "\n\t" << a << std::endl;
    }

    std::cout << "\nDecrement operators:" << std::endl;
    {
        Fixed a(1);
        std::cout << "The original: " << "\n\t" << a << std::endl;
        std::cout << "Pre decrement: decrements then prints: " << "\n\t" << --a << std::endl;
        std::cout << "The value now: " << "\n\t" << a << std::endl;
        std::cout << "Post decrement: prints then decrements: " << "\n\t" << a-- << std::endl;
        std::cout << "The value now: " << "\n\t" << a << std::endl;
    }

    std::cout << "\nMin & max functions:" << std::endl;
    {
        Fixed a;
        Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << "a: " << a.toFloat() << " b: " << b.toFloat() << std::endl;
        std::cout << "Min: " << Fixed::min( a, b ) << std::endl;
        std::cout << "Max: " << Fixed::max( a, b ) << std::endl;
    }
    
    std::cout << "\nConstant min & max functions:" << std::endl;
    {
        Fixed a(Fixed(0.11f) + Fixed(4));
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << "a: " << a.toFloat() << " b: " << b.toFloat() << std::endl;
        std::cout << "Min: " << Fixed::min( a, b ) << std::endl;
        std::cout << "Max: " << Fixed::max( a, b ) << std::endl;
    }
    
    return 0;
}
