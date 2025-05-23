/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:30:12 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/31 15:32:24 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	std::cout << "---------------------" << std::endl;

	Fixed b( a );
	std::cout << "---------------------" << std::endl;

	Fixed c;
	std::cout << "---------------------" << std::endl;

	c = b;
	std::cout << "---------------------" << std::endl;

	Fixed d;
	d.setRawBits(300);
	std::cout << "---------------------" << std::endl;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	
	return 0;
}