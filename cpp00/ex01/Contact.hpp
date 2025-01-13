/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:43:17 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/10 14:12:29 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

	private:
		std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	public:
		Contact();
		int printContact();

		//SETTERS
		void updateFirstName();
		void updateLastName();
		void updateNickname();
		void updatePhoneNumber();
		void updateDarkestSecret();

		//GETTERS
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif