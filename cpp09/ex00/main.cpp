/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:56:43 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/16 17:13:37 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "This program must take one file as argument" << std::endl;
        return (0);
    }
    std::map<std::string, float> dataMap;
    BitcoinExchange be;
    try {
        be.parseData("data.csv", dataMap);
        // for(std::map<std::string, int>::const_iterator it = dataMap.begin(); it != dataMap.end(); ++it)
        // {
        //     std::cout << it->first << " " << it->second << "\n";
        // }
        be.calculateValue(dataMap, argv[1]);
    }
    catch (std::exception & e) {
        std::cout << "Exiting program" << std::endl;
        return (1);
    }
}