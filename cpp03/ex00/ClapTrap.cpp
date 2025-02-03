/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:10 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/03 15:43:38 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {};
ClapTrap::ClapTrap(std::string name) {};
ClapTrap::ClapTrap(const ClapTrap & other) {};
ClapTrap::~ClapTrap(){};
void ClapTrap::attack(const std::string& target){};
void ClapTrap::takeDamage(unsigned int amount){};
void ClapTrap::beRepaired(unsigned int amount){};