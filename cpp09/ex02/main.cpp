/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:04:45 by maheleni          #+#    #+#             */
/*   Updated: 2025/08/05 11:49:13 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>
#include <cmath>

int maxComparisons(int n) {
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "This program needs a positive integer sequence as argument" << std::endl;
        return (0);
    }
    std::vector<int> argsVec;
    try {
        argsVec = createArgVec(argv + 1);
    }
    catch (std::exception & e) {
        std::cout << "error: " << e.what() << std::endl;
        return (1);
    }
    std::cout << "Before : " << std::flush;
    for (int i : argsVec) {
        std::cout << i << " " << std::flush;
    }
    std::cout << std::endl;
    
    auto startVec = std::chrono::high_resolution_clock::now();
    std::vector<int> result = sort(argsVec, argc - 1);
    auto stopVec = std::chrono::high_resolution_clock::now();
    auto durationVec = std::chrono::duration_cast<std::chrono::microseconds>(stopVec - startVec);
    
    std::cout << "After : " << std::flush;
    for (int i : result) {
        std::cout << i << " " << std::flush;
    }
    std::cout << std::endl;

    
    std::deque<int> argsDeq;
    try {
        argsDeq = createArgDeq(argv + 1);
    }
    catch (std::exception & e) {
        std::cout << "error: " << e.what() << std::endl;
        return (1);
    }
    
    auto startDeq = std::chrono::high_resolution_clock::now();
    sort(argsDeq, argc - 1);
    auto stopDeq = std::chrono::high_resolution_clock::now();
    auto durationDeq = std::chrono::duration_cast<std::chrono::microseconds>(stopDeq - startDeq);
    
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << durationVec.count() << "us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << durationDeq.count() << "us" << std::endl;

    if (COMMENTS) {
        std::cout << "\nMax comparisons allowed: " << maxComparisons(argc - 1) << std::endl;
    }
}

