/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:21:41 by maheleni          #+#    #+#             */
/*   Updated: 2025/06/03 14:40:58 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void binaryInsert(std::vector<std::string> element, std::vector<std::string> & main) {
//     int elements = 
// }

std::vector<std::string> mergeInsertSort(sortInfo info) {

	std::cout << "\nLEVEL: " << info.level << std::endl;
	std::cout << "Comparisons: " << info.comparisons << std::endl;
	for (std::string s : info.args) {
		std::cout << s << " " << std::flush;
	}
	std::cout << std::endl;

	std::vector<std::string>::iterator leftBegin;
	std::vector<std::string>::iterator leftEnd;
	std::vector<std::string>::iterator rightBegin;
	std::vector<std::string>::iterator rightEnd;

    for (int i = 0; i < info.comparisons; i++) {
		leftBegin = info.args.begin() + 2 * i * info.elementSize;
		leftEnd = info.args.begin() + 2 * i * info.elementSize + info.elementSize;
		rightBegin = info.args.begin() + 2 * i * info.elementSize + info.elementSize;
		rightEnd = info.args.begin() + 2 * i * info.elementSize + 2 * info.elementSize;
        if (*(rightEnd - 1) < *(leftEnd - 1)) {
			std::cout << *(rightEnd - 1) << " is smaller than " << *(leftEnd - 1) << std::endl;
            info.initialSort.insert(info.initialSort.end(), rightBegin, rightEnd);
            info.initialSort.insert(info.initialSort.end(), leftBegin, leftEnd);
        }
        else {
            info.initialSort.insert(info.initialSort.end(), leftBegin, rightEnd);
        }
    }

	std::cout << "After initial sort: " << std::endl;
	for (std::string s : info.initialSort) {
		std::cout << s << " " << std::flush;
	}
	std::cout << std::endl;

	info.outsiders = info.args.begin() + info.initialSort.size();
    for (int i = info.initialSort.size(); i < info.totalValues; i++) {
        info.initialSort.insert(info.initialSort.end(), info.args[i]);
    }

    if (info.elementSize * 4 <= info.totalValues) {
        // std::cout << "Going deeper into recursion because size is: " << info.totalValues << " and the new element size will be: " << info.elementSize * 2 << std::endl;
        sortInfo newInfo = info;
		newInfo.level = info.level + 1;
		newInfo.elementSize = std::pow(2, newInfo.level);
		newInfo.comparisons = info.totalValues / (newInfo.elementSize * 2);
		newInfo.args = info.initialSort;
		newInfo.initialSort.clear();
		info.initialSort = mergeInsertSort(newInfo);
    }

    for (int i = 0; i < info.comparisons; i++) {
		leftBegin = info.initialSort.begin() + 2 * i * info.elementSize;
		leftEnd = info.initialSort.begin() + 2 * i * info.elementSize + info.elementSize;
		rightBegin = info.initialSort.begin() + 2 * i * info.elementSize + info.elementSize;
		rightEnd = info.initialSort.begin() + 2 * i * info.elementSize + 2 * info.elementSize;
		if (i == 0) {
			std::cout << "Adding both b1 and a1 to main" << std::endl;
			std::cout << "start of b1 " << *(leftBegin) << std::endl;
			info.main.insert(info.main.end(), {"b1", std::vector<std::string>(leftBegin, leftEnd)});
			info.main.insert(info.main.end(), {"a1", std::vector<std::string>(rightBegin, rightEnd)});
			continue ;
		}
        info.pend.insert(info.pend.end(), {"b" + std::to_string(i + 1), std::vector<std::string>(leftBegin, leftEnd)});
		info.main.insert(info.main.end(), {"a" + std::to_string(i + 1), std::vector<std::string>(rightBegin, rightEnd)});
    }

    std::cout << "Elements in main: " << std::endl;
    for (element e : info.main) {
        std::cout << e.index << " {" << std::flush;
		for (const auto& value : e.values) {
            std::cout << value << " ";
        }
		std::cout << "}" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Elements in the pend: " << std::endl;
    for (element e : info.pend) {
        std::cout << e.index << " {" << std::flush;
		for (const auto& value : e.values) {
            std::cout << value << " ";
        }
		std::cout << "}" << std::endl;
    }
    std::cout << std::endl;

    // for (int i = 3; (unsigned long) i < pend.size(); i++) {
    //     try {
    //         binaryInsert(pend[jacobsthal[i]], main);
    //         pend.erase(jacobsthal[i]);
    //     }
    //     catch (...) {
            
    //     }
        
    // }
    
    return (info.initialSort);
}

std::vector<std::string> sort(std::vector<std::string> args, int size) {
	sortInfo info;
	info.level = 0;
	info.elementSize = 1;
	info.args = args;
	info.totalValues = size;
	info.comparisons = info.totalValues / (info.elementSize * 2);
	return (mergeInsertSort(info));
}

std::vector<int> jacobsthalSequence() {
    std::vector<int> result = {0, 1};
    for (int i = 2; i < 30; i++) {
        result.insert(result.end(), result[i - 1] + 2 * result[i - 2]);
    }
    return (result);
}

bool validateArg(std::vector<std::string> args) {
    for (std::string s : args) {
        if (s.length() != 1 || std::string("0123456789").find(s) == std::string::npos) {
            std::cout << "This value is not supported: " << s << std::endl;
            return (false);
        }
    }
    return (true);
}