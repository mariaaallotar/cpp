/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:27:59 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/28 11:21:01 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "This program takes one argument, ex: \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
        return (0);
    }
    rpn(argv[1]);
}