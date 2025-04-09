/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:15:56 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/09 15:19:23 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <cstdint>
#include <iostream>

class	Serializer
{
	private:
			Serializer();
			Serializer(Serializer const &other);
			Serializer & operator=(Serializer const &other);
			~Serializer();
	public:
			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);
};