/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:14:20 by maheleni          #+#    #+#             */
/*   Updated: 2025/06/02 15:22:11 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <cmath>

bool validateArg(std::vector<std::string> args);

std::vector<std::string> mergeInsertSort(std::vector<std::string> args, int level, int size);