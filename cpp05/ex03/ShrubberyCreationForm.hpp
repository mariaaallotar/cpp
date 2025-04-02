/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:06:53 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/01 09:48:03 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    public:
        ShrubberyCreationForm(std::string target = "Default target");
        ShrubberyCreationForm(const ShrubberyCreationForm & other);
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm & other);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const override;
        std::string tree() const;
};