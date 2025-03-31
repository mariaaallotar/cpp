/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:04:15 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/31 11:22:17 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
    AForm("Default PresidentialPardonForm", 25, 5), _target(target) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other) :
    AForm(other.getName(), other.getMinSignGrade(), other.getMinExecuteGrade()),
    _target(other._target) {};

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & other) {
    if (this != &other) {
        delete this;
        new(this) PresidentialPardonForm(other);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {};

int PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    try {
        canExecute(executor);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
        return (0);
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    return (1);
};