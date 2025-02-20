/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:01:56 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/20 16:43:24 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    protected:
        static const int _initHitPoints = 100;
        static const int _initEnergyPoints = 50;
        static const int _initAttackDamage = 20;

    public:
        ScavTrap(std::string name = "default", int hit = _initHitPoints,
            int energy = _initEnergyPoints, int attack = _initAttackDamage);
        ScavTrap(const ScavTrap & other);
        ScavTrap & operator=(const ScavTrap & other);
        ~ScavTrap();
        void attack(const std::string& target) override;
        void guardGate();
};

