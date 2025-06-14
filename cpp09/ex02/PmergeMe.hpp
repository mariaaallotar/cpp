/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:14:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/06/03 14:39:30 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

struct element {
	std::string index;
	std::vector<std::string> values;
};

struct sortInfo {
	std::vector<std::string> args;
	std::vector<std::string> initialSort;
	std::vector<element> main;
	std::vector<element> pend;
	std::vector<std::string>::iterator outsiders;
	int elementSize;
	int level;
	int comparisons;
	int totalValues;
	std::vector<int> jacobsthal;
};

bool validateArg(std::vector<std::string> args);

std::vector<std::string> sort(std::vector<std::string> args, int size);

std::vector<int> jacobsthalSequence();