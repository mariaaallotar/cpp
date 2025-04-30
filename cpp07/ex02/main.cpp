/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:33:50 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:54 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {
    std::cout << "\n" << std::endl;
    {
        std::cout << "TEST 1: default" << std::endl;
        try {
            Array<int> a;
            a[0] = 0;
            std::cout << "value 0 set into index 0" << std::endl;
            std::cout << a[0] << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "\n" << std::endl;
    {
        std::cout << "TEST 2: basic" << std::endl;
        try {
            Array<int> a(5);
            a[0] = 0;
            a[1] = 1;
            std::cout << "a[0]: " <<  a[0] << std::endl;
            std::cout << "a[1]: " <<  a[1] << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "\n" << std::endl;
    {
        std::cout << "TEST 3: setting and reading out of bounds" << std::endl;
        try {
            Array<char> a(5);
            a[0] = 'a';
            std::cout << a[0] << std::endl;
            a[1] = 'b';
            std::cout << a[1] << std::endl;
            a[2] = 'c';
            std::cout << a[2] << std::endl;
            a[3] = 'd';
            std::cout << a[3] << std::endl;
            a[4] = 'e';
            std::cout << a[4] << std::endl;
            std::cout << a[5] << std::endl;
            a[5] = 'f';
            std::cout << a[5] << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "\n" << std::endl;
    {
        std::cout << "TEST 4: creating array of negative size" << std::endl;
        try {
            Array<int> a(-5);
            a[0] = 0;
            a[1] = 1;
            std::cout << a[0] << std::endl;
            std::cout << a[1] << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "\n" << std::endl;
    {
        std::cout << "TEST 5: deep copy with copy constrctor" << std::endl;
        try {
            Array<int> a(5);
            std::cout << "Adding 0 and 1 to a" << std::endl;
            a[0] = 0;
            a[1] = 1;
            std::cout << "a[0]: " << a[0] << std::endl;
            std::cout << "a[1]: " << a[1] << std::endl;
            std::cout << "Constructing b by copy of a" << std::endl;
            Array<int> b(a);
            std::cout << "Adding 2 to a (will only be in a)" << std::endl;
            a[2] = 2;
            std::cout <<  "a[2]: " << a[2] << std::endl;
            std::cout <<  "b[2]: " << b[2] << std::endl;
            std::cout << "Adding 3 to b (will only be in b)" << std::endl;
            b[3] = 3;
            std::cout <<  "a[3]: " << a[3] << std::endl;
            std::cout <<  "b[3]: " << b[3] << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "\n" << std::endl;
    {
        std::cout << "TEST 6: copy assinment operator and size() function" << std::endl;
        try {
            Array<std::string> a(10);
            a[0] = "Hello";
            a[1] = "World";
            Array<std::string> b = a;
            std::cout << "b[0]: " << b[0] << std::endl;
            std::cout << "b[1]: " << b[1] << std::endl;
            std::cout << "b size: " << b.size() << std::endl;
            std::cout << "b[9]: " << b[9] << std::endl;
            std::cout << "b[10]: " << b[10] << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
}