/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:36:26 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/31 14:29:38 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float ()

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    float triArea = area();
    float area1 = area();
    float area2 = area();
    float area3 = area();
    if (area1 == 0 || area2 == 0 || area3 || 0) {
        return (false);
    }
    if (area1 + area2 + area3 == triArea) {
        return (true);
    } else {
        return (false);
    }
    
}