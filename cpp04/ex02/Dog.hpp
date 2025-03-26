/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:11:33 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/25 14:48:55 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *brain;
    public:
        Dog(std::string type = "Dog");
        Dog(const Dog & other);
        Dog & operator=(const Dog & other);
        ~Dog() override;
        void makeSound() const override;
        void addIdea(int index, std::string idea);
        std::string getIdea(int index);
};