/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:26:50 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/30 16:15:39 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    // Fixed a(1.121f);
    // Fixed b(1.123f);
    Fixed a(1000.1f);
    Fixed const b( Fixed( 100 ) * Fixed( 10 ) );
    std::cout << a.toFloat() << " < " << b.toFloat() << " : " << ((a < b) ? "true" : "false") << std::endl;
    std::cout << a.toFloat() << " <= " << b.toFloat() << " : " << ((a <= b) ? "true" : "false") << std::endl;
    std::cout << a.toFloat() << " > " << b.toFloat() << " : " << ((a > b) ? "true" : "false") << std::endl;
    std::cout << a.toFloat() << " >= " << b.toFloat() << " : " << ((a >= b) ? "true" : "false") << std::endl;
    std::cout << a.toFloat() << " == " << b.toFloat() << " : " << ((a == b) ? "true" : "false") << std::endl;
    std::cout << a.toFloat() << " != " << b.toFloat() << " : " << ((a != b) ? "true" : "false") << std::endl;
    

    std::cout << a.toFloat() << " + " << b.toFloat() << "=" << (a + b) << std::endl;
    std::cout << a.toFloat() << " - " << b.toFloat() << "=" << (a - b) << std::endl;
    std::cout << a.toFloat() << " * " << b.toFloat() << "=" << (a * b) << std::endl;
    std::cout << a.toFloat() << " / " << b.toFloat() << "=" << (a / b) << std::endl;

    
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}