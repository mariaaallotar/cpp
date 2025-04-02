/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:54:36 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/02 11:58:04 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <limits.h>
#include <cfloat>
#include <iomanip>
#include <cmath>

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter & operator=(const ScalarConverter & other);
        ~ScalarConverter();
        static void convert(const std::string & str);
        static int isChar(const std::string &s);
        static int isInt(const std::string &s);
        static int isDouble(const std::string &s);
        static int isFloat(const std::string &s);
        static int isPseudoDouble(const std::string &s);
        static int isPseudoFloat(const std::string &s);

        static void convertChar(const std::string &s);
        static void convertInt(const std::string &s);
        static void convertDouble(const std::string &s);
        static void convertFloat(const std::string &s);
        static void convertPseudoDouble(const std::string &s);
        static void convertPseudoFloat(const std::string &s);
        
        static int isOverflow(const double &d);
        static void printChar(const char &c);
};