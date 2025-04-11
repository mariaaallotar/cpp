/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:54:05 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/11 12:52:07 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    // if (argc == 1) {
    //     std::cout << "Give this program one argumnet that you want to convert" << std::endl;
    //     return (0);
    // }
    // if (argc > 2) {
    //     std::cout << "Too many arguments" << std::endl;
    //     return (0);
    // }
    // ScalarConverter::convert(argv[1]);
    
    std::string input[100] =
    {"0",
    "-0",
    "+0",
    "++4",
    "+4",
    "-4",
    "10",
    "126",
    "127",
    "128",
    "2147483647",
    "2147483648",
    "2147483647.9",
    "-2147483648",
    "48.7f",
    "1.",
    "1f",
    "1.f",
    "1.0f",
    "1..1",
    "1.1.1f",
    "c",
    "\t",
    "99999999999999.0f",
    "99999999999999.0",
    "555555555555555haha",
    "555555555555555haha.0f",
    "555555555555555.5555555555f",
    "555555555555555.5555555555",
    "haha77",
    "haha",
    "haha.08",
    "haha.08f"};
    
    for (std::string s : input) {
        std::cout << s << std::endl;
        ScalarConverter::convert(s);
        std::cout << std::endl;
    };

    #include <stdio.h>

    printf("%lf\n", 1.);
}