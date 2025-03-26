/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:49:38 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/21 13:51:32 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
    std::cout << "WrongCat constructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat & other) : WrongAnimal(other.type) {
    std::cout << "WrongCat copy constructor called" << std::endl;
};

WrongCat & WrongCat::operator=(const WrongCat & other) {
    this->type = other.type;
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return (*this);
};

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
};

void WrongCat::makeSound() const {
    std::cout << "WrongCat sound" << std::endl;
};