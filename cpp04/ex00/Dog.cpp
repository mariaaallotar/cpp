/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:13:50 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/26 09:16:36 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(std::string type) : Animal(type) {
    std::cout << "Dog constructor called" << std::endl;
};

Dog::Dog(const Dog & other) : Animal(other.type) {
    std::cout << "Dog copy constructor called" << std::endl;
};

Dog & Dog::operator=(const Dog & other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->type = other.type;
    return (*this);
};

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
};

void Dog::makeSound() const {
    std::cout << "Dog sound" << std::endl;
};