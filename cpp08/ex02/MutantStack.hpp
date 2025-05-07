/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:27:11 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/07 15:41:20 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() = default;
        MutantStack(const MutantStack &source) = default;
        MutantStack& operator=(const MutantStack &source) = default;
        ~MutantStack() = default;

        typedef typename std::stack<T>::container_type::iterator
        iterator;
        typedef typename std::stack<T>::container_type::const_iterator
        const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator
        reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator
        const_reverse_iterator;

        iterator begin();
        const_iterator cbegin();
        iterator end();
        const_iterator cend();
        reverse_iterator rbegin();
        const_reverse_iterator	crbegin();
        reverse_iterator rend();
        const_reverse_iterator crend();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return (this->c.begin());
};

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() {
    return (this->c.cbegin());
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return (this->c.end());
};

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() {
    return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
    return (this->c.rbegin());
};

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() {
    return (this->c.crbegin());
};

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
    return (this->c.rend());
};

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() {
    return (this->c.crend());
};