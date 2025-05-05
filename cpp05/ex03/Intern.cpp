/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:45:09 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/30 15:32:52 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {};

Intern::~Intern() {};

AForm * Intern::makeScf(const std::string & target) {
    return (new ShrubberyCreationForm(target));
}

AForm * Intern::makeRrf(const std::string & target) {
    return (new RobotomyRequestForm(target));
};

AForm * Intern::makePpf(const std::string & target) {
    return (new PresidentialPardonForm(target));
};

AForm * Intern::makeForm(std::string name, std::string target) {
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*	(Intern::*functions[3])(const std::string & target) = {&Intern::makeScf, &Intern::makeRrf, &Intern::makePpf};
    int i = 0;
	for (; i < 3 && name != forms[i]; i++) {  
    };
	std::cout << (i < 3 ? "Intern created " + forms[i] : throw Intern::InvalidTypeException()) << std::endl;
	return ((this->*functions[i])(target));
};

const char * Intern::InvalidTypeException::what() const noexcept {
    return ("Invalid form type");
};