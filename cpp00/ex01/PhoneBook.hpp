/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:36:48 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/13 13:44:17 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#define PHONEBOOK_SIZE 8

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {

	private:
		Contact contacts[PHONEBOOK_SIZE];
		int writeToIndex = 0;
		std::string input;

	public:
		PhoneBook();
		int printContacts();
		void searchCommand();
		void addContact();
};

#endif