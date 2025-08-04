/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:04:45 by maheleni          #+#    #+#             */
/*   Updated: 2025/08/04 14:06:24 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "This program needs a positive integer sequence as argument" << std::endl;
        return (0);
    }
    std::vector<int> args;
    try {
        args = createArgVec(argv + 1);
    }
    catch (std::exception & e) {
        std::cout << "error: " << e.what() << std::endl;
        return (1);
    }
    std::cout << "Before : " << std::flush;
    for (int i : args) {
        std::cout << i << " " << std::flush;
    }
    std::cout << std::endl;
    std::vector<int> result = sort(args, argc - 1);
    std::cout << "\nAfter : " << std::flush;
    for (int i : result) {
        std::cout << i << " " << std::flush;
    }
}