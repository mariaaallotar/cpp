/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:13:15 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/06 16:21:17 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <exception>
#include <algorithm>
#include <limits>
#include <cmath>

#include <iostream>

class Span {
    private:
    public:
    unsigned int _maxSize;
    std::vector<int> _numbers;
        Span(unsigned int capacity = 0);
        Span(const Span & other);
        Span & operator=(const Span & other);
        ~Span();
        void addNumber(int n);
        template <typename T>
        void addNumbers(T first, T last);
        unsigned int shortestSpan();
        unsigned int  longestSpan();
        class capacityException;
        class spanImpossible;
};

class Span::capacityException : public std::exception {
    public:
        const char * what() const noexcept override;
};

class Span::spanImpossible : public std::exception {
    public:
        const char * what() const noexcept override;
};

template <typename T>
inline void Span::addNumbers(T first, T last) {
    unsigned int numOfNewElements = std::distance(first, last);
    if (numOfNewElements + _numbers.size() > _maxSize) {
        throw Span::capacityException();
    }
    _numbers.insert(_numbers.end(), first, last);
}
