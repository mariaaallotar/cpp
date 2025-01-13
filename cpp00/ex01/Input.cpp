/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:00:36 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/13 12:29:20 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

bool Input::isWhitespace(const std::string& s) {
	for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
		if (!isspace(*it)) {
			return false;
		}
	}
	return true;
};

std::string Input::getInputLine(std::string prompt) {

	std::string input;

	while (1) {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl << "k, bye" << std::endl;
			exit(1);
		}
		if (!input.empty() && !isWhitespace(input)) {
			return input;
		}
		std::cout << "Line can not be empty, try again" << std::endl;
	}
	return input;
}
