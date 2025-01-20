/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:43:43 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/20 11:59:27 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    
    //Normal HumanA test case
    {
        Weapon club = Weapon("crude spiked club");
        HumanA person1("Alice", club);
        person1.attack();
        club.setType("some other type of club");
        person1.attack();
        std::cout << "--------------------------------" << std::endl;
    }

    //Init HumanB without weapon, attack, then give it a weapon, attack
    {
        HumanB person2("Bob");
        person2.attack();
        Weapon club = Weapon("crude spiked club");
        person2.setWeapon(club);
        person2.attack();
        club.setType("some other type of club");
        person2.attack();
        std::cout << "--------------------------------" << std::endl;
    }
    
    return 0;
}