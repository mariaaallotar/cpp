/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:13:42 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/16 14:59:33 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cout << "This program only takes one argument, any of these: DEBUG, "
            "INFO, WARNING, ERROR" << std::endl;
        return (0);
    }

    Harl harl;
    std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int level = -1;
    for (int i = 0; i < 4; i++) {
		if (argv[1] == levels[i]) {
            level = i;
        }
    }

    int levelValid = (level != -1);
    switch (levelValid) {
        case 0:
            std::cout << "Invalid level, try again: DEBUG, "
                "INFO, WARNING, ERROR" << std::endl;
            return (1);
        case 1:
            for (; level < 4; level++) {
				harl.complain(levels[level]);
            }
    }
    return (0);
}