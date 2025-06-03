/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:21:41 by maheleni          #+#    #+#             */
/*   Updated: 2025/06/03 14:40:58 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void binaryInsert(std::vector<std::string> element, std::vector<std::string> & main) {
//     int elements = 
// }

std::vector<std::string> sort();

std::vector<std::string> mergeInsertSort(std::vector<std::string> args, int level, int size) {
    std::vector<std::string> initialSort;
    int elementSize = std::pow(2, level);
    //std::cout << "LEVEL: " << level << std::endl;
    int i;
    for (i = elementSize; i < size; i += elementSize * 2) {
        // std::cout << "i: " << i << std::endl;
        // std::cout << "left: " << args[i - elementSize] << " right: " << args[i] << std::endl;
        if (args[i] < args[i - elementSize]) {
            // std::cout << "From: " << *(args.begin() + i) << " To: " << *(args.begin() + i + elementSize) << std::endl;
            initialSort.insert(initialSort.end(), args.begin() + i, args.begin() + i + elementSize);
            // std::cout << "From: " << *(args.begin() + i - elementSize) << " To: " << *(args.begin() + i) << std::endl;
            initialSort.insert(initialSort.end(), args.begin() + i - elementSize, args.begin() + i);
        }
        else {
            initialSort.insert(initialSort.end(), args.begin() + i - elementSize, args.begin() + i + 2 * elementSize);
        }
        // std::cout << "After first comparison: " << std::endl;
        // for (std::string s : initialSort) {
        //     std::cout << s << std::endl;
        // }
    }
    // std::cout << "i: " << initialSort.size() << " size: " << size << std::endl;
    //std::vector<std::string>::iterator outsiders = args.begin() + initialSort.size();     //do NOT remove this
    for (int i = initialSort.size(); i < size; i++) {
        initialSort.insert(initialSort.end(), args[i]);
    }
    // std::cout << "After level: " << level << std::endl;
    // for (std::string s : initialSort) {
    //     std::cout << s << std::endl;
    // }
    if (elementSize * 4 <= size) {
        // std::cout << "Going deeper into recursion because size is: " << size << " and the new element size will be: " << elementSize * 2 << std::endl;
        initialSort = mergeInsertSort(initialSort, ++level, size);
    }
    std::map<int, std::vector<std::string>> pend;
    for (int i = 2; i < size / 2; i += 2) {
        pend.insert({i, std::vector<std::string>(initialSort.begin() + i * elementSize, initialSort.begin() + i * elementSize + elementSize)});
    }

    std::cout << "Elements in the pend: " << std::flush;
    for (const auto& pair : pend) {
        std::cout <<  "< " << std::flush;
        for (const auto& value : pair.second) {
            std::cout << value << " ";
        }
        std::cout <<  " >" << std::flush;
    }
    std::cout << std::endl;
    
    std::vector<std::string> main;
    main.insert(main.end(), initialSort.begin(), initialSort.begin() + elementSize);
    for (int i = 1; i < size / 2; i += 2) {
        main.insert(main.end(), initialSort.begin() + i * elementSize, initialSort.begin() + i * elementSize + elementSize);
    }

    std::cout << "Elements in main: " << std::flush;
    for (std::string s : main) {
        std::cout << s << " " << std::flush;
    }
    std::cout << std::endl;

    // for (int i = 3; (unsigned long) i < pend.size(); i++) {
    //     try {
    //         binaryInsert(pend[jacobsthal[i]], main);
    //         pend.erase(jacobsthal[i]);
    //     }
    //     catch (...) {
            
    //     }
        
    // }
    
    return (initialSort);
}

std::vector<int> jacobsthalSequence() {
    std::vector<int> result = {0, 1};
    for (int i = 2; i < 30; i++) {
        result.insert(result.end(), result[i - 1] + 2 * result[i - 2]);
    }
    return (result);
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