/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:15:08 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/13 13:44:15 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Input.hpp"

PhoneBook::PhoneBook() {};

void printField(std::string str) {
	// std::cout << std::setw(10);
	if (str.length() > 10) {
		// std::cout << "before:"<< str << std::endl;
		std::string catStr(str, 0, 9);
		std::cout << catStr << ".";
	} else {
		std::cout << std::setw(10) << str;
	}
	std::cout << "|";
}

void printField(int i) {
	std::cout << std::setw(10);
	std::cout << i;
	std::cout << "|";
}

int PhoneBook::printContacts() {

	std::cout << std::endl;
	for (int i = 1; i <= PHONEBOOK_SIZE; i++) {
		printField(i);
		printField(this->contacts[i - 1].getFirstName());
		printField(this->contacts[i - 1].getLastName());
		printField(this->contacts[i - 1].getNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl;
	if (std::cout.fail()) {
		std::cerr << "Error: Failed to write to std::cout! "
			"Exiting program" << std::endl;
		std::exit(1);
	}
	return (0);
}

void PhoneBook::searchCommand() {
	int line;

	PhoneBook::printContacts();
	while (1) {
		std::string input = Input::getInputLine("Enter line number of contact to show: ");
		try {
			line = stoi(input);
			if (line < 1 || line > PHONEBOOK_SIZE) {
				throw (line);
			}
			break ;
		} catch (const std::invalid_argument& e) {
			std::cout << "Must be number, try again" << std::endl;
		} catch (int line) {
			std::cout << "Number must be in range 1 - " << PHONEBOOK_SIZE << ", try again" << std::endl;
		} catch (const std::out_of_range& e) {
			std::cout << "Number must be in range 1 - " << PHONEBOOK_SIZE << ", try again" << std::endl;
    }
	}
	this->contacts[line - 1].printContact();
}

void PhoneBook::addContact() {

	Contact newContact = Contact();

	newContact.updateFirstName();
	newContact.updateLastName();
	newContact.updateNickname();
	newContact.updatePhoneNumber();
	newContact.updateDarkestSecret();
	std::cout << std::endl;
	PhoneBook::contacts[this->writeToIndex] = newContact;
	if (this->writeToIndex == PHONEBOOK_SIZE - 1) {
		this->writeToIndex = 0;
	} else {
		this->writeToIndex++;
	}
}

