/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:21:41 by maheleni          #+#    #+#             */
/*   Updated: 2025/06/02 16:44:46 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::string> mergeInsertSort(std::vector<std::string> args, int level, int size) {
    std::vector<std::string> initialSort;
    int elementSize = std::pow(2, level);
    std::cout << "LEVEL: " << level << std::endl;
    for (int i = elementSize; i < size; i += elementSize * 2) {
        std::cout << "i: " << i << std::endl;
        std::cout << "left: " << args[i - elementSize] << " right: " << args[i] << std::endl;
        if (args[i] < args[i - elementSize]) {
            initialSort.insert(initialSort.end(), args.begin() + i, args.begin() + i + elementSize);
            initialSort.insert(initialSort.end(), args.begin() + i - elementSize, args.begin() + i + elementSize);
        }
        else {
            initialSort.insert(initialSort.end(), args.begin() + i - elementSize, args.begin() + i);
            initialSort.insert(initialSort.end(), args.begin() + i, args.begin() + i + elementSize);
        }
    }
    if (elementSize * 2 <= size) {
        mergeInsertSort(initialSort, ++level, size);
    }
    else {
        for (std::string s : args) {
            std::cout << s << std::endl;
        }
    }
    return (initialSort);
}

bool validateArg(std::vector<std::string> args) {
    for (std::string s : args) {
        if (s.length() != 1 || std::string("0123456789").find(s) == std::string::npos) {
            std::cout << "This value is not supported: " << s << std::endl;
            return (false);
        }
    }
    return (true);
}