/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:52:35 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/01 09:44:39 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm(std::string target = "Default target");
        RobotomyRequestForm(const RobotomyRequestForm & other);
        RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
        ~RobotomyRequestForm();
        void execute(Bureaucrat const & executor) const override;
};