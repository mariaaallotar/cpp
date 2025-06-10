/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:04:45 by maheleni          #+#    #+#             */
/*   Updated: 2025/06/03 12:39:47 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "This program needs a positive integer sequence as argument" << std::endl;
        return (0);
    }
    std::vector<std::string> args(argv + 1, argv + argc);
    if (validateArg(args) == false) {
        return (0);
    }
    std::vector<int> jacobsthal = jacobsthalSequence();
    // for (int i : jacobsthal) {
    //     std::cout << i << std::endl;
    // }
    std::cout << "Before : " << std::flush;
    for (std::string s : args) {
        std::cout << s << " " << std::flush;
    }
    std::cout << std::endl;
    //start time for first
    std::vector<std::string> result = sort(args, argc - 1);
    std::cout << "\nAfter : " << std::flush;
    for (std::string s : result) {
        std::cout << s << " " << std::flush;
    }
}