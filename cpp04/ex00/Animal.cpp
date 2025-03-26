/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:33:50 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/21 13:08:06 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal constructor called" << std::endl;
};

Animal::Animal(const Animal & other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
};

Animal & Animal::operator=(const Animal & other) {
    this->type = other.type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return (*this);
};

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
};

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
};

std::string Animal::getType() const {
    return (type);
};
