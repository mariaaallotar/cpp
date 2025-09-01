/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:36:03 by maheleni          #+#    #+#             */
/*   Updated: 2025/09/01 14:22:01 by maheleni         ###   ########.fr       */
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
            if (b == 0) {
                throw std::runtime_error("Division by 0 not allowed");
            }
            return (a  / b);
        default:
            throw std::runtime_error("Something went wrong, exiting program");
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
                throw std::runtime_error("Brackets not supported");
            }
            throw std::runtime_error("Invalid input: " + token);
            return ;
        }
        if (std::isdigit(token[0])) {
            int value = std::stoi(token);
            if (value < 0 || value > 9) {
                throw std::runtime_error("Value not supported");
            }
            stack.push(value);
        } else if (supportedOperation(token[0])) {
            if (stack.size() < 2) {
                throw std::runtime_error("Operator can not be used on less than 2 values");
            }
            float b = stack.top();
            stack.pop();
            float a = stack.top();
            stack.pop();
            stack.push(countResult(a, b, token[0]));
        } else {
            throw std::runtime_error("Use of unsupported operator: " + std::string(1, token[0]));
            return ;
        }
    }
    if (stack.size() > 1) {
        std::cout << "Note: unused numbers in stack, showing stack top" << std::endl;
    }
    if (stack.empty()) {
        return ;
    }
    std::cout << stack.top() << std::endl;
}