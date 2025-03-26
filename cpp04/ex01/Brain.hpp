/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:42:32 by maheleni          #+#    #+#             */
/*   Updated: 2025/03/25 14:49:58 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Brain {
    private:
        static const int size = 100;
        std::string ideas[size];
    public:
        Brain();
        Brain(const Brain & other);
        Brain & operator=(const Brain & other);
        ~Brain();
        void addIdea(int index, std::string idea);
        int getSize();
        std::string getIdea(int index);
};