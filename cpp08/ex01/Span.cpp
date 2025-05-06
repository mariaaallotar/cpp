/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:18:32 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/06 16:16:24 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>

Span::Span(unsigned int capacity) : _maxSize(capacity) {
    _numbers.reserve(_maxSize);
};

Span::Span(const Span & other) : _maxSize(other._maxSize) {
    _numbers.reserve(_maxSize);
    for (unsigned int i = 0; i < other._numbers.size(); i++) {
        _numbers[i] = other._numbers[i];
    }
};

Span & Span::operator=(const Span & other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        for (unsigned int i = 0; i < _numbers.size(); i++) {
            _numbers[i] = other._numbers[i];
        }
    }
    return (*this);
};

Span::~Span() {};

void Span::addNumber(int n) {
    if (_numbers.size() < _maxSize) {
        _numbers.push_back(n);
    }
    else
        throw Span::capacityException();
}

unsigned int Span::shortestSpan() {
    if (_numbers.size() < 2) {
        throw (Span::spanImpossible());
    }
    unsigned int shortest = std::numeric_limits<unsigned int>::max();
    sort(_numbers.begin(), _numbers.end());
    for (unsigned int i = 0; i < (_numbers.size() - 1); i++) {
        unsigned int span = std::abs((long)_numbers[i] - (long)_numbers[i + 1]);
        if (span <= shortest) {
            shortest = span;
        }
    }
    return (shortest);
}

unsigned int Span::longestSpan() {
    if (_numbers.size() < 2) {
        throw (Span::spanImpossible());
    }
    sort(_numbers.begin(), _numbers.end());
    unsigned int longest = std::abs((long) _numbers[0] - (long) _numbers[_numbers.size() - 1]);
    return (longest);
}

const char * Span::capacityException::what() const noexcept {
    return ("Can not add new element, span is already full");
}

const char * Span::spanImpossible::what() const noexcept {
    return ("Impossible to get span, two or more values needed");
}