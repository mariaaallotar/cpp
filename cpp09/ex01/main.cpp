/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:27:59 by maheleni          #+#    #+#             */
/*   Updated: 2025/08/28 15:00:47 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "This program takes one argument, ex: \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
        return (0);
    }
    try {
        rpn(argv[1]);
    }
    catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}