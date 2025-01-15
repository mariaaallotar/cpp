/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:07:31 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/15 11:07:42 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
    
    private:
        std::string name;
    
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
        std::string getName();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif