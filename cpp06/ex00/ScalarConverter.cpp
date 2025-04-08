/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:06:32 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/03 13:24:22 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter & other) {};

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other) {
    return (*this);
};

ScalarConverter::~ScalarConverter() {};

int ScalarConverter::isChar(const std::string &s)
{
	if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])) && std::isprint(s[0]))
		return 1;
	return 0;
}

int ScalarConverter::isInt(const std::string &s)
{
    int i = 0;
	if ((s[i] == '-' || s[i] == '+') && s.length() > 1)
		i++;
	for (; i < s.length(); i++)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return 0;
	return 1;
}

int ScalarConverter::isDouble(const std::string &s)
{
	size_t i = 0;
	size_t dot = s.find('.');
	if (dot == std::string::npos || s.find('.', dot + 1) != std::string::npos)
		return 0;
	if ((s[i] == '-' || s[i] == '+') && s.length() > 2)
		i++;
	for (; i < s.length(); i++)
		if (!(std::isdigit(static_cast<unsigned char>(s[i])) || s[i] == '.'))
			return 0;
	if (!(s.length() == 1 && s[0] == '.'))
		return 1;
	return 0;
}

int ScalarConverter::isFloat(const std::string &s)
{
	size_t len = s.length();
	if (len < 2)
		return 0;
	if (ScalarConverter::isDouble(s.substr(0, len - 1)) && s[len - 1] == 'f')
		return 1;
	return 0;
}

int ScalarConverter::isPseudoDouble(const std::string &s)
{
	if (s == "-inf" || s == "+inf" || s == "nan")
		return 1;
	return 0;
}

int ScalarConverter::isPseudoFloat(const std::string &s)
{
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return 1;
	return 0;
}

bool intOverflows(const std::string & s) {
	try {
		int i = std::stoi(s);
		return (false);
	}
	catch (std::out_of_range & e) {
		return (true);
	}
}

bool floatOverflows(const std::string & s) {
	try {
		float f = std::stof(s);
		return (false);
	}
	catch (std::out_of_range & e) {
		return (true);
	}
}

void conversionImpossiblePrint() {
    std::cout << "char: " << "Impossible" << std::endl;
    std::cout << "int: " << "Impossible" << std::endl;
    std::cout << "float: " << "Impossible" << std::endl;
    std::cout << "double: " << "Impossible" << std::endl;
}

void ScalarConverter::printChar(const char &c)
{
	std::cout << "char: ";
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Not Displayable" << std::endl;
}

void ScalarConverter::convertChar(const std::string &s)
{
	std::cout << "char: '" << s[0] << "'"<< std::endl;
	std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(s[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(s[0]) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &s)
{
    try {
        int i = std::stoi(s);
        ScalarConverter::printChar(static_cast<char>(i));
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    catch (std::out_of_range & e) {
        conversionImpossiblePrint();
    }
}

void ScalarConverter::convertFloat(const std::string &s)
{
    try {
        float f = std::stof(s);
        ScalarConverter::printChar(static_cast<char>(f));
        if (intOverflows(s))
            std::cout << "int: Impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    catch (...) {
        conversionImpossiblePrint();
    }
}

void ScalarConverter::convertDouble(const std::string &s)
{
    try {
        double d = std::stod(s);
        ScalarConverter::printChar(static_cast<char>(d));
        if (intOverflows(s))
            std::cout << "int: Impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
		if (floatOverflows(s))
			std::cout << "float: Impossible" << std::endl;
		else
        	std::cout << "float: ";
        std::cout << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    catch (...) {
        conversionImpossiblePrint();
    }
}

void ScalarConverter::convertPseudoDouble(const std::string &s)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: " << s << "f" << std::endl;
	std::cout << "double: " << s << std::endl;
}

void ScalarConverter::convertPseudoFloat(const std::string &s)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: " << s << std::endl;
	std::cout << "double: " << s.substr(0, s.length() - 1) << std::endl;
}

void ScalarConverter::convert(const std::string & str) {
    if (ScalarConverter::isChar(str))
        ScalarConverter::convertChar(str);
    else if (ScalarConverter::isInt(str))
        ScalarConverter::convertInt(str);
    else if (ScalarConverter::isFloat(str))
        ScalarConverter::convertFloat(str);
    else if (ScalarConverter::isDouble(str))
        ScalarConverter::convertDouble(str);
    else if (ScalarConverter::isPseudoDouble(str))
        ScalarConverter::convertPseudoDouble(str);
    else if (ScalarConverter::isPseudoFloat(str))
        ScalarConverter::convertPseudoFloat(str);
    else
        std::cout << "Invalid input" << std::endl;
};