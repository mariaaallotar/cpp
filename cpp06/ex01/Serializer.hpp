/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:15:56 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/30 15:37:34 by maheleni         ###   ########.fr       */
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
			Serializer(Serializer const &other) = delete;
			Serializer & operator=(Serializer const &other) = delete;
			~Serializer();
	public:
			static uintptr_t serialize(Data* ptr);
			static Data* deserialize(uintptr_t raw);
};