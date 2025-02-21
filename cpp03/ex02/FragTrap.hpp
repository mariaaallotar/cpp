/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:45:19 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/21 12:13:06 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

    private:
        static const int _initHitPoints = 100;
        static const int _initEnergyPoints = 100;
        static const int _initAttackDamage = 30;
    
    public:
        FragTrap(std::string name = "default", int hit = _initHitPoints,
            int energy = _initEnergyPoints, int attack = _initAttackDamage);
        FragTrap(const FragTrap & other);
        FragTrap & operator=(const FragTrap & other);
        ~FragTrap();
        void highFivesGuys(void);
};