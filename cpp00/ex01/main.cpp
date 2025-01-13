/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:53:58 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/13 12:07:25 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Input.hpp"

int main(void) {

	std::string input;
	PhoneBook   phoneBook;

	std::cout << "Welcome to PhoneBook. Use any of the following commands:\n"
		"SEARCH, ADD, EXIT" << std::endl;
	phoneBook = PhoneBook();
	while (1) {
		input = Input::getInputLine("Command: ");
		if (input == "SEARCH") {
			phoneBook.searchCommand();
		}
		else if (input == "ADD") {
			phoneBook.addContact();
		}
		else if (input == "EXIT") {
			std::cout << "Ok, bye" << std::endl;
			break ;
		}
		else {
			std::cout << "ERROR: Command not supported, try again" << std::endl;
			continue ;
		}
	}
	return (0);
}
