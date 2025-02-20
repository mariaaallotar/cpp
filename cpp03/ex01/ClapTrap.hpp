/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:12 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/20 15:49:13 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap {
    
    private:
        static const int _initHitPoints = 10;
        static const int _initEnergyPoints = 10;
        static const int _initAttackDamage = 0;

    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;

    public:
        ClapTrap(std::string name = "default", int hit = _initHitPoints,
            int energy = _initEnergyPoints, int attack = _initAttackDamage);
        ClapTrap(const ClapTrap & other);
        ClapTrap & operator=(const ClapTrap & other);
        virtual ~ClapTrap();
        std::string variablesToString() const;
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName();
};

std::ostream & operator<<(std::ostream &out, const ClapTrap & clapTrap);