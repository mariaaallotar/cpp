/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:22:38 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/21 13:15:41 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat(std::string type = "Cat");
        Cat(const Cat & other);
        Cat & operator=(const Cat & other);
        ~Cat() override;
        void makeSound() const override;
};