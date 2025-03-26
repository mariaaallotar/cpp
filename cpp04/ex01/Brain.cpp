/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:50:19 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/25 15:57:31 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
};

Brain::Brain(const Brain & other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i]  = other.ideas[i];
    }
};

Brain & Brain::operator=(const Brain & other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other) {
        for (int i = 0; i < size; i++) {
            this->ideas[i]  = other.ideas[i];
        }
    }
    return (*this);
};

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::addIdea(int index, std::string idea) {
    if (index < 0 || index >= size) {
        std::cout << "This brain is too small" << std::endl;
        return ;
    }
    ideas[index] = idea;
}

int Brain::getSize() {
    return (size);
}

std::string Brain::getIdea(int index) {
    if (index < 0 || index >= size) {
        std::cout << "This brain is too small" << std::endl;
        return (nullptr);
    }
    return (ideas[index]);
}