/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:12 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/04 14:49:20 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define DEFAULT_HIT 10
#define DEFAULT_ENERGY 10
#define DEFAULT_ATTACK 0

class ClapTrap {
    
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
    public:
        ClapTrap(std::string name = "default", int hit = DEFAULT_HIT,
            int energy = DEFAULT_ENERGY, int attack = DEFAULT_ATTACK);
        ClapTrap(const ClapTrap & other);
        ClapTrap & operator=(const ClapTrap & other);
        ~ClapTrap();
        std::string variablesToString() const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

std::ostream & operator<<(std::ostream &out, const ClapTrap & clapTrap);