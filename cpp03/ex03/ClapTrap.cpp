/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:10 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/25 11:06:34 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, int hit, int energy, int attack) :
    _name(name), _hitPoints(hit), _energyPoints(energy), _attackDamage(attack) {
    std::cout << "ClapTrap Constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap & other) :    _name(other._name),
                                                _hitPoints(other._hitPoints),
                                                _energyPoints(other._energyPoints),
                                                _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
};

ClapTrap & ClapTrap::operator=(const ClapTrap & other) {
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
	}
	return (*this);
};

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
};

std::string ClapTrap::variablesToString() const {
    return ("Name: " + _name +
            ", hit points: " + std::to_string(_hitPoints) +
            ", energy points: " + std::to_string(_energyPoints) +
            ", attack points: " + std::to_string(_attackDamage));
};

std::ostream & operator<<(std::ostream &out, const ClapTrap & clapTrap) {
    out << clapTrap.variablesToString();
	return (out);
};

void ClapTrap::attack(const std::string& target) {
    if (this->_energyPoints <= 0) {
        std::cout << "No energy points, can not attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " + this->_name + " attacks " + target + ", causing " +
        std::to_string(this->_attackDamage) + " points of damage!" << std::endl;
    this->_energyPoints--;
};

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " + this->_name + " took " + std::to_string(amount) +
        " points of damage!" << std::endl;
    this->_hitPoints -= amount;
};

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_energyPoints <= 0) {
        std::cout << "No energy points, can not be repaired" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " + this->_name + " repaired itself with " +
        std::to_string(amount) + " points." << std::endl;
    this->_hitPoints += amount;
};
