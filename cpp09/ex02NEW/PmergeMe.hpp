/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:14:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/07/30 14:10:36 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

struct element {
	int index;
	std::string value;
	std::vector<std::string> element_vec;
};

struct sortInfo {
	std::vector<std::string> args;
	std::vector<std::string> initialSort;
	std::vector<element> main;
	std::vector<element> pend;
	element outsider;
	int elementSize;
	int level;
	int comparisons;
	int totalValues;
	int totalElements;
	std::vector<int> jacobsthal;
};

bool validateArg(std::vector<std::string> args);

std::vector<std::string> sort(std::vector<std::string> args, int size);

std::vector<int> jacobsthalSequence();

std::vector<element>::iterator getElement(int jacobsthal, std::vector<element> & vector);