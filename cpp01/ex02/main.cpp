/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:57:07 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/15 13:41:36 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "memory address of the string variable:\t" <<  &str << std::endl;
    std::cout << "memory address held by stringPTR:\t" << stringPTR << std::endl;
    std::cout << "memory address held by stringREF:\t" << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "value of the string variable:\t" <<  str << std::endl;
    std::cout << "value pointed to by stringPTR:\t" <<  *stringPTR << std::endl;
    std::cout << "value pointed to by stringPTR:\t" <<  stringREF << std::endl;
}