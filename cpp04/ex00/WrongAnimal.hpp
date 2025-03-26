/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:45:51 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/21 13:57:00 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    public:
        WrongAnimal(std::string type = "WrongAnimal");
        WrongAnimal(const WrongAnimal & other);
        WrongAnimal & operator=(const WrongAnimal & other);
        virtual ~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
};
