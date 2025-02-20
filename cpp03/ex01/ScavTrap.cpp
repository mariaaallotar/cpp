/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:01:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/20 16:40:11 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name, int hit, int energy, int attack) :
    ClapTrap(name, hit, energy, attack) {
    std::cout << "ScavTrap Constructor called" << std::endl;
};

//is this correct or should it create a ClapTrap first?
ScavTrap::ScavTrap(const ScavTrap & other) : ClapTrap(other) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
};

ScavTrap & ScavTrap::operator=(const ScavTrap & other) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
	}
	return (*this);
};

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
};

void ScavTrap::attack(const std::string& target) {
    if (this->_energyPoints <= 0) {
        std::cout << "No energy points, can not attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " + this->_name + " attacks " + target + ", causing " +
        std::to_string(this->_attackDamage) + " points of damage!" << std::endl;
    this->_energyPoints--;
};

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " + this->getName() + " is now in gate keeper mode!" << std::endl;
}