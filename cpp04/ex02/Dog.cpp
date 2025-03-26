/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:13:50 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/25 15:55:18 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(std::string type) : brain(new Brain()), Animal(type) {
    std::cout << "Dog constructor called" << std::endl;
};

Dog::Dog(const Dog & other) : brain(new Brain(*(other.brain))), Animal(other.type) {
    std::cout << "Dog copy constructor called" << std::endl;
};

Dog & Dog::operator=(const Dog & other) {
    this->type = other.type;
    *(this->brain) = *(other.brain);
    std::cout << "Dog copy assignment operator called" << std::endl;
    return (*this);
};

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
};

void Dog::makeSound() const {
    std::cout << "Dog sound" << std::endl;
};

void Dog::addIdea(int index, std::string idea) {
    brain->addIdea(index, idea);
}

std::string Dog::getIdea(int index) {
    return (brain->getIdea(index));
}