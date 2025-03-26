/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:23:29 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/26 09:16:25 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(std::string type) : Animal(type) {
    std::cout << "Cat constructor called" << std::endl;
};

Cat::Cat(const Cat & other) : Animal(other.type) {
    std::cout << "Cat copy constructor called" << std::endl;
};

Cat & Cat::operator=(const Cat & other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = other.type;
    return (*this);
};

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
};

void Cat::makeSound() const {
    std::cout << "Cat sound" << std::endl;
};