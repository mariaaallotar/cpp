/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:56:04 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/16 17:13:57 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <stdexcept>


class BitcoinExchange {
    private:
        std::map<std::string, int> map;
    public:
        // BitcoinExchange();
        // BitcoinExchange(const BitcoinExchange & other);
        // BitcoinExchange & operator=(const BitcoinExchange & other);
        // ~BitcoinExchange();
        int parseData(const char * file, std::map<std::string, float> & dataMap);
        void calculateValue(std::map<std::string, float> dataMap, std::string inputFileName);
        
};