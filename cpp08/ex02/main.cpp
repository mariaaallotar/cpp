/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:11:26 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/07 15:41:37 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <deque>

int main() {
    {
        std::cout << "\nTest 1: from subject" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "\nTest 2: from subject with deque (insted of MutantStack)" << std::endl;
        std::deque<int> deck;
        deck.push_back(5);
        deck.push_back(17);
        std::cout << deck.back() << std::endl;
        deck.pop_back();
        std::cout << deck.size() << std::endl;
        deck.push_back(3);
        deck.push_back(5);
        deck.push_back(737);
        //[...]
        deck.push_back(0);
        MutantStack<int>::iterator it = deck.begin();
        MutantStack<int>::iterator ite = deck.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(deck);
    }
    {
        std::cout << "\nTest 3: const reverse" << std::endl;
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(10);
        mstack.push(20);
        mstack.push(100);
        mstack.push(200);
        MutantStack<int>::const_reverse_iterator it = mstack.crbegin();
        MutantStack<int>::const_reverse_iterator ite = mstack.crend();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    {
        std::cout << "\nTest 4: for loop" << std::endl;
        MutantStack<std::string> mstack;
        mstack.push("array");
        mstack.push("vector");
        mstack.push("inplace_vector");
        mstack.push("hive");
        mstack.push("deque");
        mstack.push("forward_list");
        mstack.push("list");
        for (std::string str : mstack) {
            std::cout << str << std::endl;
        }
    }
}