/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:46:42 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/21 13:47:42 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "WrongAnimal constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal & other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
};

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & other) {
    this->type = other.type;
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return (*this);
};

WrongAnimal::~WrongAnimal() {
    std::cout << "Animal destructor called" << std::endl;
};

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
};

std::string WrongAnimal::getType() const {
    return (type);
};