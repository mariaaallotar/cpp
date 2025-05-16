/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:56:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/16 17:14:15 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int validateDate(std::string dateStr) {
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

int checkFirstLine(std::string line, bool & firstLineChecked, int dataFile) {
    if (dataFile && line == "date,exchange_rate") {
        std::cout << "first line skipped" << std::endl;     //remove this
        firstLineChecked = 1;
        return (1);
    }
    if (!dataFile && line == "date | value") {
        std::cout << "first line skipped" << std::endl;     //remove this
        firstLineChecked = 1;
        return (1);
    }
    return (0);
}

int readFile(std::ifstream & dataFile, std::map<std::string, float> & dataMap) {
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

int BitcoinExchange::parseData(const char * fileName, std::map<std::string, float> & dataMap) {
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

void BitcoinExchange::calculateValue(std::map<std::string, float> dataMap, std::string inputFileName) {
    
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
            value = std::stof(line.substr(line.find('|') + 2, line.size() - line.find('|')));
            // std::cout << "Date: " << date << std::endl;
            // std::cout << "Value: " << value << std::endl;
            if (value < 0 || value > 1000) {
                throw (std::invalid_argument("Value form inputfile is out of range"));
            }
        }
        catch (std::exception & e) {
            std::cout << "Data in inputfile is formatted incorrectly. Error: " << e.what() << std::endl;
            inputFile.close();
            throw (e);
        }
        // std::cout << "Date: " << date << std::endl;
        // std::cout << "Rate: " << rate << std::endl;
        try {
            validateDate(date);
            
            float result = dataMap.at(date) * value;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << date << " | " << result << std::endl;
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
            throw (e);
        }
    }
}