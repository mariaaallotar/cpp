/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:11:33 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/21 13:25:46 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog(std::string type = "Dog");
        Dog(const Dog & other);
        Dog & operator=(const Dog & other);
        ~Dog() override;
        void makeSound() const override;
};