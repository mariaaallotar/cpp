/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:15:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/01 10:18:06 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
    AForm("RobotomyRequestForm", 72, 45), _target(target) {};

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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    canExecute(executor);
    std::cout << "Drilling noices" << std::endl;
    srand(time(0));
    if (rand() % 2) {
        std::cout << _target << " robotomization successfull" << std::endl;
    }
    else {
        std::cerr << "robotomization failed" << std::endl;
        throw "robotomization failed";
    }
};