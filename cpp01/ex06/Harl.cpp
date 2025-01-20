/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:14:06 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/20 11:39:41 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "DEBUG complaining" << std::endl;
}

void Harl::info(void) {
    std::cout << "INFO complaining" << std::endl;
}

void Harl::warning(void) {
    std::cout << "WARNING complaining" << std::endl;
}

void Harl::error(void) {
    std::cout << "ERROR complaining" << std::endl;
}

void Harl::complain(std::string level) {

    std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < sizeof(levels)/sizeof(std::string); i++) {
        if (level == levels[i]) {
            (this->*functions[i])();
        }
    }
}