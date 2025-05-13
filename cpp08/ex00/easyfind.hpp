/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:21:04 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/13 10:19:30 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T container, int i) {
    typename T::iterator itr = std::find(container.begin(), container.end(), i);
    if (itr == container.end()) {
        throw std::runtime_error("Error: value not found");
    }
    return (itr);
}