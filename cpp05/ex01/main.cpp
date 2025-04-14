/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 09:54:17 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/14 14:32:28 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {

    int testCounter = 1;

    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": default case" << std::endl;

        try {
            Form f;
            std::cout << f << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": custom values" << std::endl;

        try {
            Form f("C28", 100, 5);
            std::cout << f << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": sign form ok" << std::endl;

        try {
            Bureaucrat b("Anna", 50);
            Form f("C28", 100, 5);
            std::cout << b << std::endl;
            std::cout << f << std::endl;
            b.signForm(f);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": sign form, grade too low" << std::endl;

        try {
            Bureaucrat b("Anna", 150);
            Form f("C28", 100, 5);
            std::cout << b << std::endl;
            std::cout << f << std::endl;
            b.signForm(f);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": sign form, but is already signed" << std::endl;

        try {
            Bureaucrat b("Anna", 150);
            Form f("C28", 150, 5);
            std::cout << b << std::endl;
            std::cout << f << std::endl;
            b.signForm(f);
            std::cout << b << std::endl;
            std::cout << f << std::endl;
            Form f2(f);
            std::cout << f2 << std::endl;
            b.signForm(f2);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
}