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

// struct {
//   std::vector<std::string> initialSort;
//   int elementSize;
    // std::vector<int> jacobsthal;
// } info;

bool validateArg(std::vector<std::string> args);

std::vector<std::string> mergeInsertSort(std::vector<std::string> args, int level, int size);

std::vector<int> jacobsthalSequence();