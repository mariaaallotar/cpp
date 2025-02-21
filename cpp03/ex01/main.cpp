/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:15 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/21 14:34:03 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    std::cout << std::endl;

    {
        std::cout << "Test 1: ScavTrap default values" << std::endl;
        ScavTrap scavTrap;
        std::cout << "\t" << scavTrap << std::endl;
        scavTrap.attack("target1");
        std::cout << "\t" << scavTrap << std::endl;
        scavTrap.guardGate();
        std::cout << "\t" << scavTrap << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test 2: ScavTrap custom values using copy constructor" << std::endl;
        ScavTrap scavTrap1("Scavy", 999, 999, 999);
        std::cout << "\t" << scavTrap1 << std::endl;
        scavTrap1.attack("target1");
        std::cout << "\t" << scavTrap1 << std::endl;
        scavTrap1.guardGate();
        std::cout << "\t" << scavTrap1 << std::endl;
        ScavTrap scavTrap2(scavTrap1);
        std::cout << "\t" << scavTrap2 << std::endl;
        scavTrap2.attack("target1");
        std::cout << "\t" << scavTrap2 << std::endl;
        scavTrap2.guardGate();
        std::cout << "\t" << scavTrap2 << std::endl;
    }
    
    std::cout << std::endl;

    {
        std::cout << "Test 3: Possible to still create just a ClapTrap" << std::endl;
        ClapTrap clapTrap;
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.attack("target1");
        std::cout << "\t" << clapTrap << std::endl;
        // clapTrap.guardGate();        //but clapTrap does not have a guardGate functionality (function)
    }

    std::cout << std::endl;

    {
        std::cout << "Test 4: ScavTrap is of type ClapTrap" << std::endl;
        ClapTrap* base;
        ScavTrap scavTrap("Scavy");
        base = &scavTrap;
        std::cout << "\t" << *base << std::endl;
        base->attack("target1");      //will run ScavTraps attack function, since base is a pointer to scavTrap
        std::cout << "\t" << *base << std::endl;
        // base->guardGate();           //even though base is a pointer to a ScavTrap this will not compile
                                        //since the compiler sees base to be of type ClapTrap and it does not
                                        //have a function guardGate();
    }

    std::cout << std::endl;

    {
        std::cout << "Test 5: ScavTrap is of type ClapTrap, but with reference" << std::endl;
        ScavTrap scavTrap("Scavy");
        ClapTrap & base = scavTrap;
        std::cout << "\t" << base << std::endl;
        base.attack("target1");         //will run ScavTraps attack function, since base is a reference to scavTrap
        std::cout << "\t" << base << std::endl;
        //base.guardGate();             //even though base is a reference to a ScavTrap this will not compile
                                        //since the compiler sees base to be of type ClapTrap and it does not
                                        //have a function guardGate();
    }
    
}