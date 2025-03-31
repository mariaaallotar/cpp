/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:52:09 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/31 14:11:26 by maheleni         ###   ########.fr       */
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
            ": ShrubberyCreationForm" << std::endl;
        Bureaucrat b("Anna", 1);
        ShrubberyCreationForm form("Villa");
        form.execute(b);
        b.signForm(form);
        form.execute(b);
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": RobotomyRequestForm" << std::endl;
        Bureaucrat b("Anna", 1);
        RobotomyRequestForm form("Home");
        form.execute(b);
        b.signForm(form);
        for (int i = 0; i < 5; i++) {
            form.execute(b);
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
        form.execute(b1);
        std::cout << form << std::endl;
        b1.signForm(form);
        std::cout << form << std::endl;
        form.execute(b1);
        Bureaucrat b2("Bert", 4);
        std::cout << b2 << std::endl;
        form.execute(b2);
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": executeForm()" << std::endl;
        Bureaucrat b("Anna", 1);
        ShrubberyCreationForm form("Home");
        b.executeForm(form);
        b.signForm(form);
        b.executeForm(form);
    }
}