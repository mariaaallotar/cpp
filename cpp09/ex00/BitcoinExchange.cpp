/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:56:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/08/20 10:56:18 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static int validateDate(std::string dateStr) {
    struct std::tm date{};
    std::istringstream date_stream(dateStr);
    date_stream >> std::get_time(&date, "%Y-%m-%d");
    struct std::tm testDate{};
	testDate = date;
    if (std::mktime(&testDate) < 0) {
        throw (std::runtime_error("mktime failed"));
    }
	if (testDate.tm_year != date.tm_year
		|| testDate.tm_mon != date.tm_mon
		|| testDate.tm_mday != date.tm_mday) {
		throw (std::invalid_argument("Unexpected date format or date not valid"));
	} 
	return true;
}

static bool isValidLineFormat(const std::string& line) {
    std::regex pattern(R"(^\d{4}-\d{2}-\d{2} \| -?\d+(\.\d+)?$)");
    return (std::regex_match(line, pattern));
}

static int checkFirstLine(std::string line, bool & firstLineChecked, int dataFile) {
    if (dataFile && line == "date,exchange_rate") {
        firstLineChecked = 1;
        return (1);
    }
    if (!dataFile && line == "date | value") {
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
        try {
            validateDate(date);
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

static float getExchangeRate(std::map<std::string, float> & dataMap, std::string date) {
    float rate;
    try {
        rate = dataMap.at(date);
    }
    catch (std::exception & e) {
        auto it = dataMap.lower_bound(date);
        if (it != dataMap.begin()) {
            it--;
        }
        rate = it->second;
    }
    return (rate);
}

void calculateValue(std::map<std::string, float> dataMap, std::string inputFileName) {
    
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cout << "Error opening inputfile" << std::endl;
        throw (std::invalid_argument("Error opening inputfile"));
    }
    bool firstLineChecked = 0;
    for (std::string line; std::getline(inputFile, line, '\n'); ) {
        if (line == "\0" || line == "\n")
            continue ;
        if (firstLineChecked == 0 && checkFirstLine(line, firstLineChecked, 0)) {
            continue ;
        }
        std::string date;
        float value;
        if (!isValidLineFormat(line)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue ;
        }
        try {
            date = line.substr(0, line.find(' '));
            value = getValue(line);
            if (value == -1) {
                continue ;
            }
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
            float exchangeRate = getExchangeRate(dataMap, date);
            float result = exchangeRate * value;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (std::exception & e) {
            std::cout << "Error: " << e.what() << std::endl;
            throw (e);
        }
    }
}