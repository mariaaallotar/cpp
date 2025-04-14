/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:07:45 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/14 14:38:53 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const unsigned int _minSignGrade;
        const unsigned int _minExecuteGrade;
        static const unsigned int _maxGrade = 1;
        static const unsigned int _minGrade = 150;
    public:
        AForm(std::string name = "Form 000", unsigned int signGrade = 1,
            unsigned int executeGrade = 1);
        AForm(const AForm & other);
        AForm & operator=(const AForm & other);
        virtual ~AForm();
        void beSigned(const Bureaucrat &b);
        std::string getName() const;
        bool getIsSigned() const;
        unsigned int getMinSignGrade() const;
        unsigned int getMinExecuteGrade() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
        bool canExecute(Bureaucrat const & executor) const;
        class GradeTooLowException;
        class GradeTooHighException;
        class AlreadySignedException;
        class NotSignedException;
};

std::ostream & operator<<(std::ostream & out, AForm & form);

class AForm::GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override;
};

class AForm::GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override;
};

class AForm::AlreadySignedException : public std::exception {
    public:
        const char* what() const noexcept override;
};

class AForm::NotSignedException : public std::exception {
    public:
        const char * what() const noexcept override;
};