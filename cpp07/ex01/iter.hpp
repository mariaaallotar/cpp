/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:42:39 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/30 15:53:59 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

template<class T>
void iter(T * array, size_t length, void (func)(T&)) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
};