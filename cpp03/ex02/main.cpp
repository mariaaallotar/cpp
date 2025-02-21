/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:15 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/21 12:26:16 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    std::cout << std::endl;

    {
        std::cout << "Test 1: FragTrap default values" << std::endl;
        FragTrap fragTrap;
        std::cout << "\t" << fragTrap << std::endl;
        fragTrap.attack("target1");
        std::cout << "\t" << fragTrap << std::endl;
        fragTrap.highFivesGuys();
        std::cout << "\t" << fragTrap << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test 2: FragTrap custom values" << std::endl;
        FragTrap fragTrap("Fragy", 999, 99, 9);
        std::cout << "\t" << fragTrap << std::endl;
        fragTrap.highFivesGuys();
        std::cout << "\t" << fragTrap << std::endl;
        fragTrap.attack("target1");                 //fragTrap can attack (inherited from ClapTrap)
        std::cout << "\t" << fragTrap << std::endl;
        // fragTrap.guardGate();                    //but not guardGate, since it is part of only ScavTrap
    }
    
    std::cout << std::endl;

    {
        std::cout << "Test 3: Possible to still create just a ClapTrap" << std::endl;
        ClapTrap clapTrap;
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.attack("target1");
        std::cout << "\t" << clapTrap << std::endl;
        // clapTrap.guardGate();        //but clapTrap does not have a guardGate functionality (function)
        // clapTrap.highFivesGuys();    //or high five functionality (function)
    }
    
    std::cout << std::endl;

    {
        std::cout << "Test 4: Possible to still create just a ScavTrap" << std::endl;
        ScavTrap scavTrap;
        std::cout << "\t" << scavTrap << std::endl;
        scavTrap.attack("target1");
        std::cout << "\t" << scavTrap << std::endl;
        scavTrap.guardGate();
        std::cout << "\t" << scavTrap << std::endl;
        // scavTrap.highFivesGuys();    //ScavTrap does not have high five fucntionality (function)
    }

    std::cout << std::endl;

    {
        std::cout << "Test 5: FragTrap is of type ClapTrap" << std::endl;
        FragTrap fragTrap("Fragy");
        ClapTrap & base = fragTrap;
        std::cout << "\t" << base << std::endl;
        base.attack("target1");         //will run ClapTraps attack function since it is not overridden in FragTrap
        std::cout << "\t" << base << std::endl;
        // base.highFivesGuys();        //even though base is a reference to a FragTrap this will not compile
                                        //since the compiler sees base to be of type ClapTrap and it does not
                                        //have a function highFivesGuys();
    }
    
}