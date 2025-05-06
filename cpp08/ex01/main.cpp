/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:51:49 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/06 16:22:03 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <list>

int main() {
    {
        std::cout << "\nTest 0: form subject" << std::endl;
        try {
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest 1: basic" << std::endl;
        try {
            Span s(5);
            s.addNumber(20);
            s.addNumber(55);
            s.addNumber(-20);
            s.addNumber(80);
            s.addNumber(0);
            try {
                std::cout << "Shortest span: " << (unsigned int) s.shortestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << (unsigned int) s.longestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest 2: writing out of bounds" << std::endl;
        try {
            Span s(4);
            s.addNumber(20);
            s.addNumber(55);
            s.addNumber(-20);
            s.addNumber(80);
            s.addNumber(0);
            for (int n : s._numbers) {
                std::cout << n << std::endl;
            }
            try {
                std::cout << "Shortest span: " << (unsigned int) s.shortestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << (unsigned int) s.longestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest 3: 0 values" << std::endl;
        try {
            Span s(100);
            try {
                std::cout << "Shortest span: " << (unsigned int) s.shortestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << (unsigned int) s.longestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest 4: 1 value" << std::endl;
        try {
            Span s(100);
            s.addNumber(1);
            try {
                std::cout << "Shortest span: " << (unsigned int) s.shortestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << (unsigned int) s.longestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest 5: max values" << std::endl;
        try {
            Span s(5);
            s.addNumber(2147483647);
            s.addNumber(-2147483648);
            try {
                std::cout << "Shortest span: " << (unsigned int) s.shortestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << (unsigned int) s.longestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest 6: all values the same" << std::endl;
        try {
            Span s(20);
            s.addNumber(1);
            s.addNumber(2);
            for (int n : s._numbers) {
                std::cout << n << std::endl;
            }
            std::list<int> data = {3, 4, 5, 6, 7, 8, 9};
            s.addNumbers(data.begin(), data.end());

            for (int n : s._numbers) {
                std::cout << n << std::endl;
            }
            
            try {
                std::cout << "Shortest span: " << (unsigned int) s.shortestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << (unsigned int) s.longestSpan() << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}