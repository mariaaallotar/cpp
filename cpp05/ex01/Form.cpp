/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:18:05 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/27 15:42:10 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, unsigned int signGrade, unsigned int executeGrade) :
    _name(name), _isSigned(false), _minExecuteGrade(executeGrade),
    _minSignGrade(signGrade) {

    if (signGrade > _minGrade || executeGrade > _minGrade)
        throw Form::GradeTooLowException();
    else if (signGrade < _maxGrade || executeGrade < _maxGrade)
        throw Form::GradeTooHighException();
};

Form::Form(const Form & other) : _name(other._name), _isSigned(other._isSigned),
    _minExecuteGrade(other._minExecuteGrade), _minSignGrade(other._minSignGrade) {};

Form & Form::operator=(const Form & other) {
    if (this != &other) {
        delete this;
        new(this) Form(other);
    }
    return (*this);
};

Form::~Form() {};

void Form::beSigned(const Bureaucrat &b) {
    if (this->_isSigned)
        throw Form::AlreadySignedException();
    else if (b.getGrade() > this->getMinSignGrade())
        throw Form::GradeTooLowException();
    else
        this->_isSigned = true;
};

std::string Form::getName() const {
    return (_name);
};

bool Form::getIsSigned() const {
    return (_isSigned);
};

unsigned int Form::getMinSignGrade() const {
    return (_minSignGrade);
};

unsigned int Form::getMinExecuteGrade() const {
    return (_minExecuteGrade);
};

std::ostream & operator<<(std::ostream & out, Form & form) {
    out << "\tName: " << form.getName() << (form.getIsSigned() ? "\n\tIs signed" : "\n\tNot signed") <<
    "\n\tGrade needed to sign: " << form.getMinSignGrade() <<
    "\n\tGrade needed to execute " << form.getMinExecuteGrade();
    return (out);
};

const char * Form::GradeTooLowException::what() const noexcept {
    return ("grade too low");
};

const char * Form::GradeTooHighException::what() const noexcept {
    return ("grade too high");
};

const char* Form::AlreadySignedException::what() const noexcept {
    return ("Form: is already signed");
}