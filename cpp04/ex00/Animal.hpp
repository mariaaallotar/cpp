/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:22:49 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/21 13:15:25 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal(std::string type = "Animal");
        Animal(const Animal & other);
        Animal & operator=(const Animal & other);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;
};
