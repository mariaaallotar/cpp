/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:22:59 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/25 10:58:17 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    
    std::cout << std::endl;

    {
        std::cout << "Test 1: DiamondTrap default constructor" << std::endl;
        DiamondTrap diamondTrap;
        std::cout << "\t" << diamondTrap << std::endl;
        diamondTrap.whoAmI();
    }

    std::cout << "\n" << std::endl;

    {
        std::cout << "Test 2: DiamondTrap constructor" << std::endl;
        DiamondTrap diamondTrap("AAA");
        std::cout << "\t" << diamondTrap << std::endl;
        diamondTrap.whoAmI();
    }

    std::cout << "\n" << std::endl;

    {
        std::cout << "Test 3: DiamondTrap constructor, all values custom" << std::endl;
        DiamondTrap diamondTrap("BBB", 6, 77, 888);
        std::cout << "\t" << diamondTrap << std::endl;
        diamondTrap.whoAmI();
    }

    std::cout << "\n" << std::endl;

    {
        std::cout << "Test 4: DiamondTrap copy constructor" << std::endl;
        DiamondTrap diamondTrap("CCC", 6, 77, 888);
        std::cout << "\t" << diamondTrap << std::endl;
        diamondTrap.whoAmI();
        diamondTrap.attack("target1");
        std::cout << "\t" << diamondTrap << std::endl;
        DiamondTrap diamondTrap2(diamondTrap);
        std::cout << "\t" << "diamondTrap2 " << diamondTrap2 << std::endl;
        diamondTrap2.whoAmI();
    }

    std::cout << "\n" << std::endl;

    {
        std::cout << "Test 5: DiamondTrap copy assignment operator + attack()" << std::endl;
        DiamondTrap diamondTrap("DDD", 6, 77, 888);
        std::cout << "\t" << diamondTrap << std::endl;
        diamondTrap.whoAmI();
        diamondTrap.attack("target1");
        std::cout << "\t" << diamondTrap << std::endl;
        DiamondTrap diamondTrap2;
        diamondTrap2 = diamondTrap;
        std::cout << "\t" << "diamondTrap2 " << diamondTrap2 << std::endl;
        diamondTrap2.whoAmI();
    }

    std::cout << std::endl;

    {
        std::cout << "Test 6: DiamondTrap default constructor + highFivesGuys()" << std::endl;
        DiamondTrap diamondTrap;
        std::cout << "\t" << diamondTrap << std::endl;
        diamondTrap.whoAmI();
        diamondTrap.highFivesGuys();
        std::cout << "\t" << diamondTrap << std::endl;
    }

}