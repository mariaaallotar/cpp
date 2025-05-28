/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:36:03 by maheleni          #+#    #+#             */
/*   Updated: 2025/05/28 12:01:54 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool supportedOperation(char c) {
    if (std::string("+-*/").find(c) != std::string::npos) {
        return true;
    }
    return (false);
}

float countResult(float a, float b, char c) {
    switch (c) {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
        case '/':
            return (a  / b);
        default:
            std::cerr << "Something went wrong, results undefined" << std::endl;
    }
    return (-1);
}

void rpn(std::string expr) {
    std::istringstream iss(expr);
    std::string token;
    std::stack<float> stack;

    while (iss >> token) {
        if (token.length() != 1) {
            if (token[0] == '(' || token[0] == ')') {
                std::cerr << "Brackets not supported" << std::endl;
                return ;
            }
            std::cerr << "Invalid input: " << token << std::endl;
            return ;
        }
        if (std::isdigit(token[0])) {
            int value = std::stoi(token);
            if (value < 0 || value > 9) {
                std::cerr << "Value not supported" << std::endl;
                return ;
            }
            stack.push(value);
        } else if (supportedOperation(token[0])) {
            if (stack.size() < 2) {
                std::cerr << "Operator can not be used on less than 2 values" << std::endl;
                return ;
            }
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            stack.push(countResult(a, b, token[0]));
        } else {
            std::cout << "Use of unsupported operator: " << token[0] << std::endl;
            return ;
        }
    }
    if (stack.size() > 1) {
        std::cout << "Note: unused numbers in stack, showing stack top" << std::endl;
    }
    std::cout << stack.top() << std::endl;
}