/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:33:15 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/21 09:42:05 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

    std::cout << std::endl;

    {
        std::cout << "Test 1: default values" << std::endl;
        ClapTrap clapTrap;
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.attack("target1");
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.takeDamage(3);
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.beRepaired(2);
        std::cout << "\t" << clapTrap << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "Test 2: all values 0" << std::endl;
        ClapTrap clapTrap("0", 0, 0, 0);
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.attack("target1");
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.takeDamage(3);
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.beRepaired(2);
        std::cout << "\t" << clapTrap << std::endl;
    }
    
    std::cout << std::endl;

    {
        std::cout << "Test 3: energy points will end" << std::endl;
        ClapTrap clapTrap("0", 0, 2, 0);
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.attack("target1");
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.attack("target2");
        std::cout << "\t" << clapTrap << std::endl;
        clapTrap.attack("target3");
        std::cout << "\t" << clapTrap << std::endl;
    }
}