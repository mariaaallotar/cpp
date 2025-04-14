/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:52:09 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/14 14:40:48 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

int main() {
    
    int testCounter = 1;
    
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": Intern creating ShrubberyCreationForm" << std::endl;
        try {
            Intern i;
            Bureaucrat b("Anna", 1);
            AForm * form = i.makeForm("ShrubberyCreationForm", "Villa");
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
        catch (Intern::InvalidTypeException & e) {
            std::cerr << "Could not create form: " <<e.what() << std::endl;
        }
        catch (std::exception & e) {
            std::cerr << "Error: " <<e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": Intern creating RobotomyRequestForm" << std::endl;
        try {
            Intern i;
            Bureaucrat b("Anna", 1);
            AForm * form = i.makeForm("RobotomyRequestForm", "Hive");
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
        catch (Intern::InvalidTypeException & e) {
            std::cerr << "Could not create form: " <<e.what() << std::endl;
        }
        catch (std::exception & e) {
            std::cerr << "Error: " <<e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": Intern creating PresidentialPardonForm" << std::endl;
        try {
            Intern i;
            Bureaucrat b("Anna", 1);
            AForm * form = i.makeForm("PresidentialPardonForm", "Me");
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
        catch (Intern::InvalidTypeException & e) {
            std::cerr << "Could not create form: " <<e.what() << std::endl;
        }
        catch (std::exception & e) {
            std::cerr << "Error: " <<e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": Intern trying to create SomeForm" << std::endl;
        try {
            Intern i;
            Bureaucrat b("Anna", 1);
            AForm * form = i.makeForm("SomeForm", "Home");
            b.signForm(*form);
            b.executeForm(*form);
            delete form;
        }
        catch (Intern::InvalidTypeException & e) {
            std::cerr << "Could not create form: " <<e.what() << std::endl;
        }
        catch (std::exception & e) {
            std::cerr << "Error: " <<e.what() << std::endl;
        }
    }
}