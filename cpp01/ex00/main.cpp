/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:42:11 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/15 11:17:19 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    Zombie* heapZombie = newZombie("heapZombie");
    heapZombie->announce();
    randomChump("stackZombie");
    heapZombie->announce();
    delete heapZombie;
}