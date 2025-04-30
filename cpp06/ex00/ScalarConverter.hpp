/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:54:36 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/30 11:13:09 by maheleni         ###   ########.fr       */
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
    private:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter & other) = delete;
        ScalarConverter & operator=(const ScalarConverter & other) = delete;
        ~ScalarConverter() = delete;
    public:
        static void convert(const std::string & str);
};