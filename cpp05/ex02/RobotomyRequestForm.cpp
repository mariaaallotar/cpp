/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:15:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/31 11:21:34 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("Default RobotomyRequestForm", 72, 45), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other) :
    AForm(other.getName(), other.getMinSignGrade(), other.getMinExecuteGrade()), 
    _target(other._target){};

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & other)  {
    if (this != &other) {
        delete this;
        new(this) RobotomyRequestForm(other);
    }
    return (*this);
};

RobotomyRequestForm::~RobotomyRequestForm() {};

int RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    try {
        canExecute(executor);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        return (0);
    }
    std::cout << "Drilling noices" << std::endl;
    srand(time(0));
    if (rand() % 2) {
        std::cout << _target << " robotomization successfull" << std::endl;
    }
    else {
        std::cout << _target << " robotomization failed" << std::endl;
        return (0);
    }
    return (1);
};