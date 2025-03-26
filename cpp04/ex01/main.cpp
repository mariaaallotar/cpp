/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:02:11 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/26 10:11:23 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    {
        std::cout << "\nTest 1: everything from previous still works" << std::endl;
        const Animal* meta = nullptr;
        const Animal* j = nullptr;
        const Animal* i = nullptr;
        try {
            meta = new Animal();
            j = new Dog();
            i = new Cat();
            std::cout << j->getType() << " " << std::endl;
            std::cout << i->getType() << " " << std::endl;
            i->makeSound();
            j->makeSound();
            meta->makeSound();
            delete meta;
            delete j;
            delete i;
        }
        catch (...) {
            std::cerr << "allocating an object failed" << std::endl;
            if (meta != nullptr)
                delete meta;
            if (i != nullptr)
                delete j;
            if (j != nullptr)
                delete i;
        }
    }
    {
        std::cout << "\nTest 2: memory management with delete Animal" << std::endl;
        const int SIZE = 5;
        Animal* animals[SIZE];

        try {
            for (int i = 0; i < SIZE; i++) {
                if (i % 2 == 0) {
                    animals[i] = new(std::nothrow) Dog();
                } else {
                    animals[i] = new(std::nothrow) Cat();
                }
                if (animals[i] == nullptr)
                    throw i;
            }
            for (int i = 0; i < SIZE; i++) {
                delete animals[i];
            }
        }
        catch (int i) {
            i--;
            for ( ; i >= 0; i--) {
                delete animals[i];
            }
        }
    }
    {
        std::cout << "\nTest 3: deep copy with copy assignment operator" << std::endl;
        try {
            Cat cat1;
            Cat cat2;

            for (int i = 0; i < 100; i++) {
                cat1.addIdea(i, "Idea: cat1");
            }
            for (int i = 0; i < 100; i++) {
                cat2.addIdea(i, "Idea: cat2");
            }
            std::cout << cat1.getIdea(1) << std::endl;
            std::cout << cat2.getIdea(1) << std::endl;
            cat1 = cat2;
            std::cout << cat1.getIdea(1) << std::endl;
            std::cout << cat2.getIdea(1) << std::endl;
            cat2.addIdea(1, "Only cat2 idea");
            std::cout << cat1.getIdea(1) << std::endl;
            std::cout << cat2.getIdea(1) << std::endl;
        }
        catch (...) {
            std::cerr << "Allocation of an object failed" << std::endl;
        }
    }
    {
        std::cout << "\nTest 4: deep copy with copy constructor" << std::endl;
        Cat cat1;

        for (int i = 0; i < 100; i++) {
            cat1.addIdea(i, "Idea: cat1");
        }
        std::cout << cat1.getIdea(1) << std::endl;
        Cat cat2(cat1);
        std::cout << cat1.getIdea(1) << std::endl;
        std::cout << cat2.getIdea(1) << std::endl;
        cat1.addIdea(1, "Only cat1 idea");
        std::cout << cat1.getIdea(1) << std::endl;
        std::cout << cat2.getIdea(1) << std::endl;
    }
}
