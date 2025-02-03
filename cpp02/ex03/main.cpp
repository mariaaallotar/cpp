/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:35:47 by maheleni          #+#    #+#             */
/*   Updated: 2025/02/03 12:59:42 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void printResult(Point p1, Point p2, Point p3, Point point) {
    if (bsp(p1, p2, p3, point)) {
        std::cout << "Result: Inside" << std::endl;
    } else {
        std::cout << "Result: Outside" << std::endl;
    }
}

int main(void) {

    {
        std::cout << "\nTest: clearly inside" << std::endl;
        const Point p1(0, 0);
        const Point p2(3, 0);
        const Point p3(1, 2);
        const Point pointA(1, 1);

        printResult(p1, p2, p3, pointA);
    }

    {
        std::cout << "\nTest: clearly outside" << std::endl;
        const Point p1(0, 0);
        const Point p2(3, 0);
        const Point p3(1, 2);
        const Point pointB(2, 2);

        printResult(p1, p2, p3, pointB);
    }

    {
        std::cout << "\nTest: on line" << std::endl;
        const Point p1(0, 0);
        const Point p2(3, 0);
        const Point p3(1, 2);
        const Point pointC(1, 0);

        printResult(p1, p2, p3, pointC);
    }

    {
        std::cout << "\nTest: barely outside" << std::endl;
        const Point p1(0, 0);
        const Point p2(3, 0);
        const Point p3(1, 2);
        const Point pointD(-0.04, 0);

        printResult(p1, p2, p3, pointD);
    }

    {
        std::cout << "\nTest: barely inside" << std::endl;
        const Point p1(0, 0);
        const Point p2(3, 0);
        const Point p3(1, 2);
        const Point pointE(1.78, 1.18);

        printResult(p1, p2, p3, pointE);
    }

    {
        std::cout << "\nTest: on corner point" << std::endl;
        const Point p1(0, 0);
        const Point p2(3, 0);
        const Point p3(1, 2);
        const Point pointE(p3);

        printResult(p1, p2, p3, pointE);
    }

    {
        std::cout << "\nTest: not a triangle" << std::endl;
        const Point p1;
        const Point p2;
        const Point p3;
        const Point pointE;

        printResult(p1, p2, p3, pointE);
    }
}