/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:19:59 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/27 10:17:28 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat {
    private:
        const std::string _name;
        unsigned int _grade;
    public:
        Bureaucrat(std::string name = "Default Bureaucrat", unsigned int grade = 150);
        Bureaucrat(const Bureaucrat & other);
        Bureaucrat & operator=(const Bureaucrat & other);
        ~Bureaucrat();
        std::string getName() const;
        unsigned int getGrade() const;
        void incrementGrade();
        void decrementGrade();
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
