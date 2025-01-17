/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:42:55 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/17 14:35:30 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    {
        int N = 3;
        std::string name = "Alice";
        Zombie* zombieArray = zombieHorde(N, name);
        for (int i = 0; i < N; i++) {
            zombieArray[i].announce();
        }
        delete[] zombieArray;
    }
    std::cout << "-----------------------------" << std::endl;
    {
        int N = 7;
        std::string name = "Bob";
        Zombie* zombieArray = zombieHorde(N, name);
        for (int i = 0; i < N; i++) {
            zombieArray[i].announce();
        }
        delete[] zombieArray;
    }
}