/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:54:05 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/28 10:54:39 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "Give this program one argument that you want to convert" << std::endl;
        return (0);
    }
    if (argc > 2) {
        std::cout << "Too many arguments" << std::endl;
        return (0);
    }
    ScalarConverter::convert(argv[1]);
}
