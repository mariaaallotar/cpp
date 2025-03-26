/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:48:02 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/21 13:57:04 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat(std::string type = "WrongCat");
        WrongCat(const WrongCat & other);
        WrongCat & operator=(const WrongCat & other);
        ~WrongCat() override;
        void makeSound() const;
};
