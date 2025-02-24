/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:46:03 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/24 14:39:43 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name, int hit, int energy, int attack) : 
    ClapTrap(name + "_clap_name", hit, energy, attack), ScavTrap(), FragTrap(), _name(name) {
    std::cout << "DiamondTrap Constructor called" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap & other) : ClapTrap(other), ScavTrap(other),
    FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
};

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & other) {
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &other) {
        ClapTrap::operator=(other);
		this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
	}
	return (*this);
};

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called" << std::endl;
};

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
};

void DiamondTrap::whoAmI() {
    std::cout << "My ClapTrap name is: " << ClapTrap::_name 
        << " and my DiamondTrap name: " << _name << std::endl;
};