/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:09:55 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/30 15:27:43 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, unsigned int signGrade, unsigned int executeGrade) :
    _name(name), _isSigned(false), _minSignGrade(signGrade),
    _minExecuteGrade(executeGrade) {

    if (signGrade > _minGrade || executeGrade > _minGrade)
        throw AForm::GradeTooLowException();
    else if (signGrade < _maxGrade || executeGrade < _maxGrade)
        throw AForm::GradeTooHighException();
};

AForm::AForm(const AForm & other) : _name(other._name), _isSigned(other._isSigned),
    _minSignGrade(other._minSignGrade), _minExecuteGrade(other._minExecuteGrade) {};

//this does not really make sense, but rules are rules
AForm & AForm::operator=(const AForm & other) {
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return (*this);
};

AForm::~AForm() {};

void AForm::beSigned(const Bureaucrat &b) {
    if (this->_isSigned)
        throw AForm::AlreadySignedException();
    else if (b.getGrade() > this->getMinSignGrade())
        throw AForm::GradeTooLowException();
    else
        this->_isSigned = true;
};

std::string AForm::getName() const {
    return (_name);
};

bool AForm::getIsSigned() const {
    return (_isSigned);
};

unsigned int AForm::getMinSignGrade() const {
    return (_minSignGrade);
};

unsigned int AForm::getMinExecuteGrade() const {
    return (_minExecuteGrade);
};

bool AForm::canExecute(Bureaucrat const & b) const {
    if (!_isSigned)
        throw AForm::NotSignedException();
    if (b.getGrade() > _minExecuteGrade)
        throw AForm::GradeTooLowException();
    return (true);
};

std::ostream & operator<<(std::ostream & out, AForm & form) {
    out << "\tName: " << form.getName() << (form.getIsSigned() ? "\n\tIs signed" : "\n\tNot signed") <<
    "\n\tGrade needed to sign: " << form.getMinSignGrade() <<
    "\n\tGrade needed to execute " << form.getMinExecuteGrade();
    return (out);
};

const char * AForm::GradeTooLowException::what() const noexcept {
    return ("Grade too low");
};

const char * AForm::GradeTooHighException::what() const noexcept {
    return ("Grade too high");
};

const char* AForm::AlreadySignedException::what() const noexcept {
    return ("Form is already signed");
}

const char * AForm::NotSignedException::what() const noexcept {
    return ("Form not signed");
}