/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:19:32 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/09 15:30:04 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data original;
	Data *deserialized_ptr;
	uintptr_t ptr_as_unsigned_int;

    original.joke = "\tWhy do C++ developers prefer dark mode?\n\tBecause the light attracts bugs!";
    original.funny = 0;

	std::cout << "Original joke: \n" << original.joke << std::endl;
	std::cout << "Is it funny: " << original.funny << std::endl;
	std::cout << "Original address: \t" << &original << std::endl;
	
	std::cout << std::endl;
	ptr_as_unsigned_int = Serializer::serialize(&original);
	std::cout << "ptr_as_unsigned_int value: " << ptr_as_unsigned_int << std::endl;
    std::cout << "ptr_as_unsigned_int address: " << &ptr_as_unsigned_int << std::endl;
	std::cout << std::endl;

	deserialized_ptr = Serializer::deserialize(ptr_as_unsigned_int);
	std::cout << "Joke after casts: \n" << deserialized_ptr->joke << std::endl;
	std::cout << "Funny after casts: " << deserialized_ptr->funny << std::endl;
	std::cout << "Address after casts: \t" << deserialized_ptr << std::endl;

	return (0);
}
