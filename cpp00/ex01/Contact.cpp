/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:26:49 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/13 13:43:04 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Input.hpp"

Contact::Contact() {};

int Contact::printContact() {
	std::cout << std::endl;
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
	std::cout << std::endl;

	if (std::cout.fail()) {
		std::cerr << "Error: Failed to write to std::cout! "
			"Exiting program" << std::endl;
		std::exit(1);
	}
	return (0);
}

void Contact::updateFirstName() {

	this->firstName = Input::getInputLine("Enter fist name: ");
}

void Contact::updateLastName() {

	this->lastName = Input::getInputLine("Enter last name: ");;
}

void Contact::updateNickname() {

	this->nickname = Input::getInputLine("Enter nickname: ");;
}

void Contact::updatePhoneNumber() {
	
	this->phoneNumber = Input::getInputLine("Enter phone number: ");
}

void Contact::updateDarkestSecret() {

	this->darkestSecret = Input::getInputLine("Enter your darkest secret: ");
}



std::string Contact::getFirstName() {
	return firstName;
}

std::string Contact::getLastName() {
	return lastName;
}

std::string Contact::getNickname() {
	return nickname;
}
