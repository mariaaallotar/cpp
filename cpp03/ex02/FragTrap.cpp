/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:50:33 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/21 12:15:03 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name, int hit, int energy, int attack) : 
    ClapTrap(name, hit, energy, attack) {
    std::cout << "FragTrap Constructor called" << std::endl;
};

FragTrap::FragTrap(const FragTrap & other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
};

FragTrap & FragTrap::operator=(const FragTrap & other) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
};

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
};

void FragTrap::highFivesGuys(void) {
    std::cout << "This is a positive high fives request from a FragTrap" << std::endl;
};