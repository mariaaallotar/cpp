/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:06:32 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/30 11:14:19 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum overflow {
	CHAR_OVERF = 1,
	INT_OVERF,
	FLOAT_OVERF
};

static int isChar(const std::string &s)
{
	if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
		return 1;
	return 0;
}

static int isInt(const std::string &s)
{
    int i = 0;
	if ((s[i] == '-' || s[i] == '+') && s.length() > 1)
		i++;
	for (; i < s.length(); i++)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return 0;
	return 1;
}

static int isDouble(const std::string &s)
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

static int isFloat(const std::string &s)
{
	size_t len = s.length();
	if (len < 2)
		return 0;
	if (isDouble(s.substr(0, len - 1)) && s[len - 1] == 'f')
		return 1;
	return 0;
}

static int isPseudoDouble(const std::string &s)
{
	if (s == "-inf" || s == "+inf" || s == "nan")
		return 1;
	return 0;
}

static int isPseudoFloat(const std::string &s)
{
	if (s == "-inff" || s == "+inff" || s == "nanf")
		return 1;
	return 0;
}

static int isOverflow(const std::string & s)
{
	try {
		float f = std::stof(s);
	}
	catch (std::out_of_range & e) {
		return (FLOAT_OVERF);
	}
	try {
		int i = std::stoi(s);
	}
	catch (std::out_of_range & e) {
		return (INT_OVERF);
	}
	int i = std::stoi(s);
	if (i < 0 || i > 127)
		return (CHAR_OVERF);
	return 0;
}

static int countPrecision(const std::string &s, int isFloat) {
	size_t dot = s.find('.');
	std::string fromDot = s.substr(dot);
	int len = fromDot.size();
	if (isFloat) {
		len--;
	}
	len--;
	if (len <= 0)
		return (1);
	return (len);
}

static void conversionImpossiblePrint() {
    std::cout << "char: " << "Impossible" << std::endl;
    std::cout << "int: " << "Impossible" << std::endl;
    std::cout << "float: " << "Impossible" << std::endl;
    std::cout << "double: " << "Impossible" << std::endl;
}

static void printChar(const char &c, const int overflow)
{
	std::cout << "char: ";
	if (!overflow) {
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Not Displayable" << std::endl;
		
	}
	else
		std::cout << "Impossible" << std::endl;
}

static void convertChar(const std::string &s)
{
	if (std::isprint(s[0]))
		std::cout << "char: '" << s[0] << "'"<< std::endl;
	else
		std::cout << "Not Displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(s[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(s[0])  << std::endl;
}

static void convertInt(const std::string &s)
{
    try {
        int i = std::stoi(s);
		int overflow = isOverflow(s);
        printChar(static_cast<char>(i), overflow);
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    catch (std::out_of_range & e) {
        conversionImpossiblePrint();
    }
}

static void convertFloat(const std::string &s)
{
    try {
        float f = std::stof(s);
		int overflow = isOverflow(s);
		std::cout << std::fixed << std::setprecision(countPrecision(s, 1));
        printChar(static_cast<char>(f), overflow);
        if (overflow == INT_OVERF)
            std::cout << "int: Impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    catch (...) {
        conversionImpossiblePrint();
    }
}

static void convertDouble(const std::string &s)
{
    try {
        double d = std::stod(s);
		int overflow = isOverflow(s);
		std::cout << std::fixed << std::setprecision(countPrecision(s, 0));
        printChar(static_cast<char>(d), overflow);
        if (overflow == INT_OVERF)
            std::cout << "int: Impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
		if (overflow == FLOAT_OVERF)
			std::cout << "float: Impossible" << std::endl;
		else
        	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    catch (...) {
        conversionImpossiblePrint();
    }
}

static void convertPseudoDouble(const std::string &s)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: " << s << "f" << std::endl;
	std::cout << "double: " << s << std::endl;
}

static void convertPseudoFloat(const std::string &s)
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: " << s << std::endl;
	std::cout << "double: " << s.substr(0, s.length() - 1) << std::endl;
}

void ScalarConverter::convert(const std::string & str) {
    if (isChar(str))
        convertChar(str);
    else if (isInt(str))
        convertInt(str);
    else if (isFloat(str))
        convertFloat(str);
    else if (isDouble(str))
        convertDouble(str);
    else if (isPseudoDouble(str))
        convertPseudoDouble(str);
    else if (isPseudoFloat(str))
        convertPseudoFloat(str);
    else
        std::cout << "Invalid input" << std::endl;
};