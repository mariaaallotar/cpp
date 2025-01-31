/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:37:18 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/31 14:07:13 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
    
    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Fixed &other);
        Point & operator=(const Point & other);
        ~Point();
};