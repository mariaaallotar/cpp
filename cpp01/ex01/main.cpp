/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:42:55 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/15 12:55:21 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 5;
    Zombie* zombieArray = zombieHorde(N, "name");
    for (int i = 0; i < N; i++) {
        zombieArray[i].announce();
    }
    delete[] zombieArray;
}