/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:52:09 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/01 10:15:27 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

int main() {
    
    int testCounter = 1;
    
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": ShrubberyCreationForm success" << std::endl;
        try {
            Bureaucrat b("Anna", 1);
            ShrubberyCreationForm form("Villa");
            b.signForm(form);
            form.execute(b);
        }
        catch (std::exception & e) {
            std::cerr << "Error: " <<e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": ShrubberyCreationForm error" << std::endl;
        try {
            Bureaucrat b("Anna", 1);
            ShrubberyCreationForm form("Home");
            form.execute(b);
        }
        catch (std::exception & e) {
            std::cerr << "Error: " <<e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": RobotomyRequestForm" << std::endl;
        Bureaucrat b("Anna", 1);
        RobotomyRequestForm form("Hive");
        b.executeForm(form);
        b.signForm(form);
        try {
            for (int i = 0; i < 5; i++) {
                form.execute(b);
                sleep(1);
            }
        }
        catch (std::exception & e) {
        std::cerr << "Form execution failed: " << e.what() << std::endl;
        }
        catch (const char * str) {
            std::cerr << "Form execution failed: " << str << std::endl;
        }
        for (int i = 0; i < 5; i++) {
            b.executeForm(form);
            sleep(1);
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": PresidentialPardonForm" << std::endl;
        Bureaucrat b1("Anna", 25);
        std::cout << b1 << std::endl;
        PresidentialPardonForm form("Me");
        std::cout << form << std::endl;
        b1.executeForm(form);
        std::cout << form << std::endl;
        b1.signForm(form);
        std::cout << form << std::endl;
        b1.executeForm(form);
        Bureaucrat b2("Bert", 4);
        std::cout << b2 << std::endl;
        b2.executeForm(form);
    }
}