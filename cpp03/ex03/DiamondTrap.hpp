/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:27:03 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/24 13:43:36 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;
    public:
        DiamondTrap(std::string name = "default Diamondy", int hit = FragTrap::_initHitPoints,
            int energy = ScavTrap::_initEnergyPoints, int attack = FragTrap::_initAttackDamage);
        DiamondTrap(const DiamondTrap & other);
        DiamondTrap & operator=(const DiamondTrap & other);
        ~DiamondTrap();
        void attack(const std::string& target) override;
        void whoAmI();
};