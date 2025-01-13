/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:01:09 by maheleni          #+#    #+#             */
/*   Updated: 2025/01/10 14:31:42 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <string>

class Input {

    private:
        static bool isWhitespace(const std::string& s);

    public:
        static std::string getInputLine(std::string prompt);
};

#endif