/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:51:49 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/07 11:22:38 by maheleni         ###   ########.fr       */
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
                std::cout << "Shortest span: " << static_cast<unsigned int>(s.shortestSpan()) << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << static_cast<unsigned int>(s.longestSpan()) << std::endl;
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
        std::cout << "\nTest 1.5: basic 2" << std::endl;
        try {
            Span s(5);
            s.addNumber(0);
            s.addNumber(2);
            s.addNumber(4);
            s.addNumber(6);
            s.addNumber(7);
            try {
                std::cout << "Shortest span: " << static_cast<unsigned int>(s.shortestSpan()) << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << static_cast<unsigned int>(s.longestSpan()) << std::endl;
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
                std::cout << "Shortest span: " << static_cast<unsigned int>(s.shortestSpan()) << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << static_cast<unsigned int>(s.longestSpan()) << std::endl;
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
                std::cout << "Shortest span: " << static_cast<unsigned int>(s.shortestSpan()) << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << static_cast<unsigned int>(s.longestSpan()) << std::endl;
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
                std::cout << "Shortest span: " << static_cast<unsigned int>(s.shortestSpan()) << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << static_cast<unsigned int>(s.longestSpan()) << std::endl;
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
                std::cout << "Shortest span: " << static_cast<unsigned int>(s.shortestSpan()) << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << static_cast<unsigned int>(s.longestSpan()) << std::endl;
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
            Span s(5);
            s.addNumber(1000);
            s.addNumber(1000);
            s.addNumber(1000);
            s.addNumber(1000);
            s.addNumber(1000);
            try {
                std::cout << "Shortest span: " << static_cast<unsigned int>(s.shortestSpan()) << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << static_cast<unsigned int>(s.longestSpan()) << std::endl;
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
        std::cout << "\nTest 7: adding with iterators (list)" << std::endl;
        try {
            Span s(20);
            s.addNumber(1);
            s.addNumber(2);
            std::list<int> data = {3, 4, 5, 6, 7, 8, 9};
            s.addNumbers(data.begin(), data.end());
            try {
                std::cout << "Shortest span: " << static_cast<unsigned int>(s.shortestSpan()) << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << static_cast<unsigned int>(s.longestSpan()) << std::endl;
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
        std::cout << "\nTest 8: 10 000 random values with iterators (vector)" << std::endl;
        try {
            Span s(10000);
            std::vector<int> data;
            std::srand(time(0));
            for (int i = 0; i < 10000; i++) {
                data.push_back(std::rand());
            }
            s.addNumbers(data.begin(), data.end());
            try {
                std::cout << "Shortest span: " << static_cast<unsigned int>(s.shortestSpan()) << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
            try {
                std::cout << "Longest span: " << static_cast<unsigned int>(s.longestSpan()) << std::endl;
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