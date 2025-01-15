/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:20:13 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/15 12:50:17 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {

    Zombie* zombieHorde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        new (&zombieHorde[i]) Zombie(name);
    }
    return (zombieHorde);
}