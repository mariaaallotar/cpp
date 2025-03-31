/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:33:33 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/27 10:35:42 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat & other) : _name(other._name), _grade(other._grade) {};

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other) {
    if (this != &other) {
        this->~Bureaucrat();
        new(this) Bureaucrat(other);
    }
    return (*this);
};

Bureaucrat::~Bureaucrat() {};

std::string Bureaucrat::getName() const {
    return (_name);
}

unsigned int Bureaucrat::getGrade() const {
    return (_grade);
}

void Bureaucrat::incrementGrade() {
    std::cout << "Incrementing grade." << std::endl;
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
}
void Bureaucrat::decrementGrade() {
    std::cout << "Decrementing grade." << std::endl;
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

std::ostream & operator<<(std::ostream &out, const Bureaucrat b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (out);
}

const char * Bureaucrat::GradeTooHighException::what() const noexcept {
    return ("Grade is too high!");
};

const char * Bureaucrat::GradeTooLowException::what() const noexcept {
    return ("Grade is too low!");
};