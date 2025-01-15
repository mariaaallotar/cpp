/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:03:22 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/15 15:31:03 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    _type = type;
}

const std::string& Weapon::getType() {
    return (_type);
}

void Weapon::setType(std::string type) {
    _type = type;
}
