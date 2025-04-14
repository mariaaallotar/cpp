/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:42:21 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/14 13:56:33 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <stddef.h>
#include <iostream>

template <class T>
void print(T& value) {
    std::cout << value << std::endl;
}

template <typename T>
void increment(T& value) {
    value += 1;
}

int main() {

    int testCounter = 1;

    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": int array" << std::endl;
        size_t length = 4;
        int arr[] = {1, 2, 3, 4};
        for (int i : arr) {
            std::cout << i << std::endl;
        }
        iter(arr, length, increment);
        std::cout << "After iter" << std::endl;
        for (int i : arr) {
            std::cout << i << std::endl;
        }
    }
    {
        std::cout << "\nTest" << std::to_string(testCounter++) <<
            ": string array" << std::endl;
        size_t length = 4;
        std::string arr[] = {"ha", "haha", "hahaha", "hahahaha"};
        iter(arr, length, print);
    }
}