/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:15 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/20 16:48:35 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    // std::cout << std::endl;

    // {
    //     std::cout << "Test 1: default values" << std::endl;
    //     ClapTrap clapTrap;
    //     std::cout << "\t" << clapTrap << std::endl;
    //     clapTrap.attack("target 1");
    //     std::cout << "\t" << clapTrap << std::endl;
    //     clapTrap.takeDamage(3);
    //     std::cout << "\t" << clapTrap << std::endl;
    //     clapTrap.beRepaired(2);
    //     std::cout << "\t" << clapTrap << std::endl;
    // }

    // std::cout << std::endl;

    // {
    //     std::cout << "Test 2: all values 0" << std::endl;
    //     ClapTrap clapTrap("0", 0, 0, 0);
    //     std::cout << "\t" << clapTrap << std::endl;
    //     clapTrap.attack("target 1");
    //     std::cout << "\t" << clapTrap << std::endl;
    //     clapTrap.takeDamage(3);
    //     std::cout << "\t" << clapTrap << std::endl;
    //     clapTrap.beRepaired(2);
    //     std::cout << "\t" << clapTrap << std::endl;
    // }
    
    // std::cout << std::endl;

    // {
    //     std::cout << "Test 3: energy points will finish" << std::endl;
    //     ClapTrap clapTrap("0", 0, 2, 0);
    //     std::cout << "\t" << clapTrap << std::endl;
    //     clapTrap.attack("target 1");
    //     std::cout << "\t" << clapTrap << std::endl;
    //     clapTrap.attack("target 2");
    //     std::cout << "\t" << clapTrap << std::endl;
    //     clapTrap.attack("target 2");
    //     std::cout << "\t" << clapTrap << std::endl;
    // }

    std::cout << std::endl;

    {
        std::cout << "Test 4: ScavTrap default values" << std::endl;
        ScavTrap scavTrap;
        std::cout << "\t" << scavTrap << std::endl;
        scavTrap.attack("target1");
        std::cout << "\t" << scavTrap << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test 5: ScavTrap is of type ClapTrap" << std::endl;
        std::cout << "-----------------------" << std::endl;
        ClapTrap* base;
        std::cout << "-----------------------" << std::endl;
        ScavTrap derived("ScavTrap");
        std::cout << "-----------------------" << std::endl;
        ScavTrap derived2(derived);
        std::cout << "-----------------------" << std::endl;
        base = &derived2;
        std::cout << "-----------------------" << std::endl;
        std::cout << "\t" << *base << std::endl;
        (*base).attack("target1");
        std::cout << "\t" << *base << std::endl;
    }
}