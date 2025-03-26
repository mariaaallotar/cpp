/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:21:26 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/26 09:22:52 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    return 0;
}


// WRONG Animal and Cat

// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

// int main() {
//     const WrongAnimal* meta = new WrongAnimal();
//     const WrongAnimal* i = new WrongCat();
//     std::cout << meta->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound();
//     meta->makeSound();
//     delete meta;
//     delete i;
//     return 0;
// }