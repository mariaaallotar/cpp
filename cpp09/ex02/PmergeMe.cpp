/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:21:41 by maheleni          #+#    #+#             */
/*   Updated: 2025/07/30 14:35:18 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void binaryInsert(std::vector<element>::iterator toInsert, std::vector<element> & main) {
    auto searchStart  = main.begin();
    auto searchEnd = getElement(toInsert->index, main);
    

    while (searchStart->values.end() - 1 < searchEnd->values.end() - 1) {
        auto mid = searchStart + (searchEnd - searchStart) / 2;

        if (mid->values.end() - 1 < toInsert->values.end() - 1) {
            searchStart = mid + 1;
        } else {
            searchEnd = mid;
        }
    }
    main.insert(searchStart, *toInsert);
}

std::vector<element>::iterator getElement(int jacobsthal, std::vector<element> & vector) {
    for (auto it = vector.begin(); it != vector.end(); it++) {
        if (it->index == jacobsthal) {
            return (it);
        }
    }
    return (vector.end());
}

std::vector<std::string> mergeInsertSort(sortInfo info) {

	std::cout << "\nLEVEL: " << info.level << std::endl;
	std::cout << "Comparisons: " << info.comparisons << std::endl;
    std::cout << "Element size: " << info.elementSize << std::endl;
    
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
            info.initialSort.insert(info.initialSort.end(), rightBegin, rightEnd);
            info.initialSort.insert(info.initialSort.end(), leftBegin, leftEnd);
        }
        else {
            info.initialSort.insert(info.initialSort.end(), leftBegin, rightEnd);
        }
    }
    
	info.outsiders = info.args.begin() + info.initialSort.size();
    for (int i = info.initialSort.size(); i < info.totalValues; i++) {
        info.initialSort.insert(info.initialSort.end(), info.args[i]);
    }
    
    std::cout << "After initial sort: " << std::endl;
    for (std::string s : info.initialSort) {
        std::cout << s << " " << std::flush;
    }
    std::cout << std::endl;
    
    if (info.elementSize * 4 <= info.totalValues) {
        //std::cout << "Going deeper into recursion because size is: " << info.totalValues << " and the new element size will be: " << info.elementSize * 2 << std::endl;
        std::cout << "Going deeper into recursion" << "----------------------------------" << std::endl;
        sortInfo newInfo = info;
		newInfo.level = info.level + 1;
		newInfo.elementSize = std::pow(2, newInfo.level);
		newInfo.comparisons = info.totalValues / (newInfo.elementSize * 2);
		newInfo.args = info.initialSort;
		newInfo.initialSort.clear();
		info.initialSort = mergeInsertSort(newInfo);
    }

    std::cout << "\nLEVEL: " << info.level << std::endl;
	std::cout << "Comparisons: " << info.comparisons << std::endl;
    std::cout << "Element size: " << info.elementSize << std::endl;

    std::cout << "Making main and pend form: " << std::endl;
    for (std::string s : info.initialSort) {
        std::cout << s << " " << std::flush;
    }
    std::cout << std::endl;

    auto it = info.initialSort.begin();
    for (int i = 0; i < info.comparisons; i++) {
		leftBegin = it;
		leftEnd = it + info.elementSize;
		rightBegin = it + info.elementSize;
		rightEnd = it + 2 * info.elementSize;
		if (i == 0) {
			info.main.insert(info.main.end(), {i + 1, std::vector<std::string>(leftBegin, leftEnd)});
			info.main.insert(info.main.end(), {i + 1, std::vector<std::string>(rightBegin, rightEnd)});
            it += info.elementSize;
			continue ;
		}
        info.pend.insert(info.pend.end(), {i + 1, std::vector<std::string>(leftBegin, leftEnd)});
		info.main.insert(info.main.end(), {i + 1, std::vector<std::string>(rightBegin, rightEnd)});
        it += info.elementSize;
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

    int elementsInPend = info.pend.size();
    for (int i = 3; i <= elementsInPend; i++) {     //i is the index in jacobsthal
        for (int j = info.jacobsthal[i]; j >= 2 && j > info.jacobsthal[i - 1]; i--) {   //j is the actual jacobsthal to insert
            try {
                auto elementIt = getElement(j, info.pend);
                binaryInsert(elementIt, info.main);
                info.pend.erase(elementIt);
            }
            catch (...) {
                
            }
        }
    }
    while (!info.pend.empty()) {
        binaryInsert(info.pend.end() -1, info.main);
        info.pend.erase(info.pend.end() -1);
    }

    std::vector<std::string> sorted;
    for (element e : info.main) {
        for (std::string str : e.values) {
            sorted.insert(sorted.end(), str);
        }
    }
    
    return (sorted);
}

std::vector<std::string> sort(std::vector<std::string> args, int size) {
	sortInfo info;
	info.level = 0;
	info.elementSize = 1;
	info.args = args;
	info.totalValues = size;
	info.comparisons = info.totalValues / (info.elementSize * 2);
    info.jacobsthal = jacobsthalSequence();
    for (int i : info.jacobsthal) {
        std::cout << i << " " << std::flush;
    }
    std::cout << std::endl;
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
        for (char c : s) {
            if (std::string("0123456789").find(c) == std::string::npos) {
                std::cout << "This value is not supported: " << s << std::endl;
                return (false);
            }
        }
    }
    return (true);
}