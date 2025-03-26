/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:23:29 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/25 15:55:07 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string type) : brain(new Brain()), Animal(type) {
    std::cout << "Cat constructor called" << std::endl;
};

Cat::Cat(const Cat & other) : brain(new Brain(*(other.brain))), Animal(other.type) {
    std::cout << "Cat copy constructor called" << std::endl;
};

Cat & Cat::operator=(const Cat & other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = other.type;
    *(this->brain) = *(other.brain);
    return (*this);
};

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
};

void Cat::makeSound() const {
    std::cout << "Cat sound" << std::endl;
};

void Cat::addIdea(int index, std::string idea) {
    brain->addIdea(index, idea);
}

std::string Cat::getIdea(int index) {
    return (brain->getIdea(index));
}