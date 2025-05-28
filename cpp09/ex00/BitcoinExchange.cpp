/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:56:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/28 09:53:37 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int validateDate(std::string dateStr) {
    struct std::tm date{};
    std::istringstream date_stream(dateStr);
    date_stream >> std::get_time(&date, "%Y-%m-%d");
    struct std::tm testDate{};
	testDate = date;
	std::mktime(&testDate);
	if (testDate.tm_year != date.tm_year
		|| testDate.tm_mon != date.tm_mon
		|| testDate.tm_mday != date.tm_mday) {
		throw (std::invalid_argument("Unexpected date format or date not valid"));
	} 
	return true;
}

static int checkFirstLine(std::string line, bool & firstLineChecked, int dataFile) {
    if (dataFile && line == "date,exchange_rate") {
        //std::cout << "first line skipped" << std::endl;     //remove this
        firstLineChecked = 1;
        return (1);
    }
    if (!dataFile && line == "date | value") {
        //std::cout << "first line skipped" << std::endl;     //remove this
        firstLineChecked = 1;
        return (1);
    }
    return (0);
}

static int readFile(std::ifstream & dataFile, std::map<std::string, float> & dataMap) {
    for (std::string line; std::getline(dataFile, line, '\n'); ) {
        if (line == "\0" || line == "\n")
            continue ;
        bool firstLineChecked = 0;
        if (firstLineChecked == 0 && checkFirstLine(line, firstLineChecked, 1)) {
            continue ;
        }
        std::string date;
        std::string rate;
        try {
            date = line.substr(0, line.find(','));
            rate = line.substr(line.find(',') + 1, line.size() - line.find(','));
        }
        catch (std::exception & e) {
            std::cout << "Data in databse is formatted incorrectly. Error: " << e.what() << std::endl;
            dataFile.close();
            throw (e);
        }
        // std::cout << "Date: " << date << std::endl;
        // std::cout << "Rate: " << rate << std::endl;
        try {
            validateDate(date);
            // std::cout << "IS VALID DATE" << std::endl;
            dataMap.insert({date, std::stof(rate)});
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
            throw (e);
        }
    }
    return (1);
}

int parseData(const char * fileName, std::map<std::string, float> & dataMap) {
    std::ifstream dataFile(fileName);
    if (!dataFile.is_open()) {
        std::cout << "Could not open datafile, exiting program" << std::endl;
        return (-1);
    }
    if (readFile(dataFile, dataMap) == 0) {
        return (-1);
    }
    dataFile.close();
    return (1);
}

static float getValue(std::string line) {
    float value;
    if (line.find('|') == line.npos) {
        std::cout << "Error: bad input => " << line << std::endl;
        return (-1);
    }
    value = std::stof(line.substr(line.find('|') + 1, line.size() - line.find('|')));
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return (-1);
    } else if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return (-1);
    }
    return (value);
}

void calculateValue(std::map<std::string, float> dataMap, std::string inputFileName) {
    
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cout << "Error opening inputfile" << std::endl;
        throw (std::invalid_argument("Error opening inputfile"));
    }
    for (std::string line; std::getline(inputFile, line, '\n'); ) {
        if (line == "\0" || line == "\n")
            continue ;
        bool firstLineChecked = 0;
        if (firstLineChecked == 0 && checkFirstLine(line, firstLineChecked, 0)) {
            continue ;
        }
        std::string date;
        float value;
        try {
            date = line.substr(0, line.find(' '));
            value = getValue(line);
            if (value == -1) {
                continue ;
            }
            // std::cout << "Date: " << date << std::endl;
            // std::cout << "Value: " << value << std::endl;
        }
        catch (std::exception & e) {
            std::cout << "Data in inputfile is formatted incorrectly. Error: " << e.what() << std::endl;
            continue ;
        }
        try {
            try {
                validateDate(date);
            }
            catch (std::exception & e) {
                std::cout << "Error: bad input => " << date << std::endl;
                continue ;
            }
            //std::cout << "DATE: " << date << std::endl;
            float exchangeRate;
            try {
                exchangeRate = dataMap.at(date);
            }
            catch (std::exception & e) {
                auto it = dataMap.lower_bound(date);
                if (it != dataMap.begin()) {
                    it--;
                }
                exchangeRate = it->second;
            }
            float result = exchangeRate * value;
            //std::cout << "exchange rate: " << exchangeRate<< " for date: " << date << " ";
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
            throw (e);
        }
    }
}