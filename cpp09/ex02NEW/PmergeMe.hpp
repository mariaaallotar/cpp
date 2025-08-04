/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:14:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/08/04 17:30:55 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#define COMMENTS 1

struct element {
	int index;
	int value;
	std::vector<int> element_vec;
};

struct sortInfo {
	std::vector<int> args;
	std::vector<int> initialSort;
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

std::vector<int> createArgVec(char *argv[]);

std::vector<int> sort(std::vector<int> args, int size);

std::vector<int> jacobsthalSequence();