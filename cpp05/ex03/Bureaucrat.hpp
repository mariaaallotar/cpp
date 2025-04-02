/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:19:59 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/01 10:02:03 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        unsigned int _grade;
        static const unsigned int _maxGrade = 1;
        static const unsigned int _minGrade = 150;
    public:
        Bureaucrat(std::string name = "Default Bureaucrat", unsigned int grade = _minGrade);
        Bureaucrat(const Bureaucrat & other);
        Bureaucrat & operator=(const Bureaucrat & other);
        ~Bureaucrat();
        std::string getName() const;
        unsigned int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &f) const;
        void executeForm(AForm const & form) const noexcept;
        class GradeTooHighException;
        class GradeTooLowException;
};

std::ostream & operator<<(std::ostream &out, const Bureaucrat b);

class Bureaucrat::GradeTooHighException : public std::exception {
    public:
        const char * what() const noexcept override;
};

class Bureaucrat::GradeTooLowException : public std::exception {
    public:
        const char * what() const noexcept override;
};
