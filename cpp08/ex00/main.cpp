/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:21:15 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/13 10:20:48 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <random>

int createRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-100, 100);
    return (dist(gen));
}

std::list<int> createRandomList(int toFind) {
    std::list<int> result;
    for (int i = 0; i < 100; ++i) {
        int num = createRandomNumber();
        if (num == toFind)
            std::cout << "\t" << std::flush;
        std::cout << num << std::endl;
        result.push_back(num);
    }
    return result;
}


int main() {
    {
        std::cout << "\nTEST 1: basic found" << std::endl;
        try {
            std::vector<int> arr = {1, 2, 3, 4, 5};
            std::cout << "Result: " << *easyfind(arr, 3) << std::endl;
            
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\nTEST 2: basic NOT found" << std::endl;
        try {
            std::deque<int> arr = {1, 2, 3, 4, 5};
            std::cout << "Result: " << *easyfind(arr, 6) << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        
        std::cout << "\nTEST 3: big random" << std::endl;
        try {
            int toFind = createRandomNumber();
            std::list<int> arr = createRandomList(toFind);
            std::cout << "\nTo find: " << toFind << std::endl;
            std::cout << "Result: " << *easyfind(arr, toFind) << std::endl;
            
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
}