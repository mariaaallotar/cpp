/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:54:17 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/14 14:34:24 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    {
        std::cout << "\nTest1: default case" << std::endl;

        Bureaucrat b;
        std::cout << b << std::endl;
        try {
            b.decrementGrade();
            std::cout << b << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
        try {
            b.incrementGrade();
            std::cout << b << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest2: custom values" << std::endl;

        try {
            Bureaucrat b("Custom", 100);
            std::cout << b << std::endl;
            try {
                b.decrementGrade();
                std::cout << b << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
            try {
                b.incrementGrade();
                std::cout << b << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest3: grade too low on creation" << std::endl;

        try {
            Bureaucrat b("Grade too low", 200);
            std::cout << b << std::endl;
            try {
                b.decrementGrade();
                std::cout << b << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
            try {
                b.incrementGrade();
                std::cout << b << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest4: grade too high on creation" << std::endl;

        try {
            Bureaucrat b("Grade too high", 0);
            std::cout << b << std::endl;
            try {
                b.decrementGrade();
                std::cout << b << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
            try {
                b.incrementGrade();
                std::cout << b << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest5: copy constructor" << std::endl;

        try {
            Bureaucrat b1;
            Bureaucrat b2(b1);
            std::cout << b1 << std::endl;
            std::cout << b2 << std::endl;
            try {
                b2.decrementGrade();
                std::cout << b2 << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
            try {
                b2.incrementGrade();
                std::cout << b2 << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest6: copy assignment operator" << std::endl;

        try {
            Bureaucrat b1;
            Bureaucrat b2("My name", 2);
            b1 = b2;
            std::cout << b1 << std::endl;
            std::cout << b2 << std::endl;
            try {
                b2.decrementGrade();
                std::cout << b1 << std::endl;
                std::cout << b2 << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
            try {
                b2.incrementGrade();
                std::cout << b1 << std::endl;
                std::cout << b2 << std::endl;
            }
            catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
}