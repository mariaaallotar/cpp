/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:33:02 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/14 12:38:58 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main() {
    
    int testCounter = 1;

    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": from subject" << std::endl;
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": char" << std::endl;
        char a = 'a';
        char b = 'b';
        std::cout << "a = " << a << ", b = " << b << std::endl;
        swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": float" << std::endl;
        float a = 100.1f;
        float b = 100.2f;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": double" << std::endl;
        double a = 100.1;
        double b = 100.2;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    }
}