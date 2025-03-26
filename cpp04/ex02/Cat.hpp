/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:22:38 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/25 14:48:58 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *brain;
    public:
        Cat(std::string type = "Cat");
        Cat(const Cat & other);
        Cat & operator=(const Cat & other);
        ~Cat() override;
        void makeSound() const override;
        void addIdea(int index, std::string idea);
        std::string getIdea(int index);
};