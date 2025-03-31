/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:33:33 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/31 14:15:58 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
    if (grade < _maxGrade)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > _minGrade)
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
    if (_grade == _maxGrade)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
}
void Bureaucrat::decrementGrade() {
    std::cout << "Decrementing grade." << std::endl;
    if (_grade == _minGrade)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm(AForm &f) const {
    try {
        f.beSigned(*this);
        std::cout << this->_name << " signed form " << f.getName() << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << this->_name << " couldn't sign form " << f.getName() <<
        " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (int err) {
        std::cerr << "Form execution failed" << std::endl;
    }
}

std::ostream & operator<<(std::ostream &out, const Bureaucrat b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (out);
}

const char * Bureaucrat::GradeTooHighException::what() const noexcept {
    return ("Bureaucrats rade would be too high!");
};

const char * Bureaucrat::GradeTooLowException::what() const noexcept {
    return ("Bureaucrats grade would be too low!");
};