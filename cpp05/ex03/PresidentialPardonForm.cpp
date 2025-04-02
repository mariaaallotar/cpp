/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:04:15 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/01 10:18:01 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
    AForm("PresidentialPardonForm", 25, 5), _target(target) {};

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

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    canExecute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};