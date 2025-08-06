/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:14:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/08/06 15:11:17 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <cmath>

#define COMMENTS 0
#define COMPARISONS 1

template<template<typename, typename> class Container>
struct element {
	int index;
	int value;
	Container<int, std::allocator<int>> element_vec;
};

template<template<typename, typename> class Container>
struct sortInfo {
	Container<int, std::allocator<int>> args;
	Container<int, std::allocator<int>> initialSort;
	Container<element<Container>, std::allocator<element<Container>>> main;
	Container<element<Container>, std::allocator<element<Container>>> pend;
	element<Container> outsider;
	int elementSize;
	int level;
	int comparisons;
	int totalValues;
	int totalElements;
	std::vector<int, std::allocator<int>> jacobsthal;
};

std::vector<int> createArgVec(char *argv[]);
std::deque<int> createArgDeq(char *argv[]);

std::vector<int> sort(std::vector<int> args, int size);
std::deque<int> sort(std::deque<int> args, int size);

std::vector<int> jacobsthalSequence();