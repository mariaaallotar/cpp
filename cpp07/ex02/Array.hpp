/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:58:44 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/30 15:41:03 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <stdexcept>

template<class T>
class Array {
    private:
        unsigned int _size;
        T * _values;
    
    public:
        Array(unsigned int size = 0);
        Array(const Array & other);
        Array<T> & operator=(const Array & other);
        ~Array();
        unsigned int size() const;
        T & operator[](int i);
};

template<class T>
Array<T>::Array(unsigned int size) {
    _values = new T[size];
    _size = size;
};

template<class T>
Array<T>::Array(const Array & other) {
    _size = other.size();
    _values = new T[_size];
    for (int i = 0; (size_t)i < _size; i++) {
        _values[i] = other._values[i];
    }
};

template<class T>
Array<T> & Array<T>::operator=(const Array & other) {
    delete[] _values;
    _size = other.size();
    _values = new T[_size];
    for (int i = 0; (size_t)i < _size; i++) {
        _values[i] = other._values[i];
    }
};

template<class T>
unsigned int Array<T>::size() const {
    return (_size);
}

template<class T>
T & Array<T>::operator[](int i) {
    if ((size_t)i < _size) {
        return (_values[i]);
    }
    throw std::runtime_error("Error: index out of bounds");
};

template<class T>
Array<T>::~Array() {
    delete[] _values;
};