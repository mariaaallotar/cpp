/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:09:26 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/27 15:37:47 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const unsigned int _minSignGrade;
        const unsigned int _minExecuteGrade;
        static const unsigned int _maxGrade = 1;
        static const unsigned int _minGrade = 150;
    public:
        Form(std::string name = "Form 000", unsigned int signGrade = 1,
            unsigned int executeGrade = 1);
        Form(const Form & other);
        Form & operator=(const Form & other);
        ~Form();
        void beSigned(const Bureaucrat &b);
        std::string getName() const;
        bool getIsSigned() const;
        unsigned int getMinSignGrade() const;
        unsigned int getMinExecuteGrade() const;
        class GradeTooLowException;
        class GradeTooHighException;
        class AlreadySignedException;
};

std::ostream & operator<<(std::ostream & out, Form & form);

class Form::GradeTooLowException : public std::exception {
    public:
        const char* what() const noexcept override;
};

class Form::GradeTooHighException : public std::exception {
    public:
        const char* what() const noexcept override;
};

class Form::AlreadySignedException : public std::exception {
    public:
        const char* what() const noexcept override;
};