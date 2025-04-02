/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:54:05 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/02 10:50:22 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "Give this program one argumnet that you want to convert" << std::endl;
        return (0);
    }
    if (argc > 2) {
        std::cout << "Too many arguments" << std::endl;
        return (0);
    }
    ScalarConverter::convert(argv[1]);
}