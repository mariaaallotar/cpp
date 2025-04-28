/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:08:25 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/17 13:47:03 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>

int main() {
    
    int testCounter = 1;
    srand(time(0));

    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": Basic" << std::endl;
        Base * list[10];
        for (int i = 0; i < 10; i++) {
            list[i] = generate();
            identify(list[i]);
            identify(*(list[i]));
        }
        for (Base * b : list) {
            delete b;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": null pointer" << std::endl;
        Base * b = nullptr;
        identify(b);
    }
}