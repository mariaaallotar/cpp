/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:36:26 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/03 12:48:13 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(Point p1, Point p2, Point p3) {
    Fixed area;
    
    area = p1.getX() * (p2.getY() - p3.getY())
         + p2.getX() * (p3.getY() - p1.getY())
         + p3.getX() * (p1.getY() - p2.getY());
    return (area.toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    float triArea = area(a, b, c);
    float area1 = area(a, b, point);
    float area2 = area(a, c, point);
    float area3 = area(b, c, point);

    triArea = (triArea < 0) ? triArea * (-1) : triArea;
    area1 = (area1 < 0) ? area1 * (-1) : area1;
    area2 = (area2 < 0) ? area2 * (-1) : area2;
    area3 = (area3 < 0) ? area3 * (-1) : area3;

    if (area1 == 0 || area2 == 0 || area3 == 0) {
        return (false);
    }
    else if (area1 + area2 + area3 == triArea) {
        return (true);
    } else {
        return (false);
    }
    
}