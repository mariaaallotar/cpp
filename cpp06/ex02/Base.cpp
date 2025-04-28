/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:52:49 by maheleni          #+#    #+#             */
/*   Updated: 2025/04/17 13:47:02 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {};

Base * generate(void) {
    int randN = rand();
    if (randN % 3 == 0) {
        std::cout << "Created: A" << std::endl;
        return (new A());
    }
    else if (randN % 3 == 1) {
        std::cout << "Created: B" << std::endl;
        return (new B());
    }
    else if (randN % 3 == 2) {
        std::cout << "Created: C" << std::endl;
        return (new C());
    }
    return (0);
};

void identify(Base* p) {
    
    if (p == nullptr)
		std::cout << "Null pointer" << std::endl;
    else if (dynamic_cast<A*>(p))
        std::cout << "POINTER: This base pointer points to: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "POINTER: This base pointer points to: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "POINTER: This base pointer points to: C" << std::endl;
    else
        std::cout << "Not A, B or C" << std::endl;
};

void identify(Base& p) {
    try {
        Base b = dynamic_cast<A &>(p);
        std::cout << "REF: This base ref is a: A" << std::endl;
        return ;
    }
    catch (const std::exception& e) {};
    try {
        Base b = dynamic_cast<B &>(p);
        std::cout << "REF: This base ref is a: B" << std::endl;
        return ;
    }
    catch (const std::exception& e) {};
    try {
        Base b = dynamic_cast<C &>(p);
        std::cout << "REF: This base ref is a: C" << std::endl;
        return ;
    }
    catch (const std::exception& e) {
        std::cout << "Not A, B or C" << std::endl;
        return ;
    };
};
