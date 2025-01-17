/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:01:16 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/17 16:54:02 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
    
    private:
        std::string _name;
        Weapon* _weapon = nullptr;

    public:
        HumanB(std::string name);
        void setWeapon(Weapon& weapon);
        void attack();
};

#endif