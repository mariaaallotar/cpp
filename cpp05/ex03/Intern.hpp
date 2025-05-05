/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:41:05 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/30 15:33:05 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
    public:
        Intern();
        Intern(const Intern & other) = delete;
        Intern & operator=(const Intern & other) = delete;
        ~Intern();
        AForm * makeForm(std::string name, std::string target);
        AForm * makeScf(const std::string & target);
        AForm * makeRrf(const std::string & target);
        AForm * makePpf(const std::string & target);
        class InvalidTypeException;
};

class Intern::InvalidTypeException : public std::exception {
    public:
        const char * what() const noexcept override;
};