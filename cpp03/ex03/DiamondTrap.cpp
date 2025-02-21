/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:46:03 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/21 14:52:16 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//check that the _name and _name are different
DiamondTrap::DiamondTrap(std::string name, int hit, int energy, int attack) : 
    ClapTrap(), ScavTrap(), FragTrap(name + "_clap_name"), _name(name) {
    std::cout << "DiamondTrap Constructor called" << std::endl;
};

//check that the _name and _name are different
DiamondTrap::DiamondTrap(const DiamondTrap & other) : ClapTrap(other), ScavTrap(other),
    FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
};

DiamondTrap & DiamondTrap::operator=(const ClapTrap & other) : {
    
};

~DiamondTrap();
void attack(const std::string& target) override;