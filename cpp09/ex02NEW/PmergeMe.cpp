
#include "PmergeMe.hpp"

int comparisonCounter = 0;


/*************************************************************************************************/


std::vector<element>::iterator getElement(int jacobsthal, std::vector<element> & vector) {
    for (auto it = vector.begin(); it != vector.end(); it++) {
        if (it->index == jacobsthal) {
            return (it);
        }
    }
    return (vector.end() - 1);
}

void binaryInsertOutsider(element toInsert, std::vector<element> & main) {

    auto start = main.begin();
    auto end = main.end();

    while (start < end) {
        auto mid = start + (end - start) / 2;
        if (mid->value < toInsert.value) {
            start = mid + 1;
        } else {
            end = mid;
        }
        comparisonCounter++;
    }

    if (COMMENTS) {
        std::cout << "Inserting: " << std::flush;
        std::cout << " {" << std::flush;
        for (const auto& value : toInsert.element_vec) {
            std::cout << value << " ";
        }
        std::cout << "}" << " after " << end->value << std::endl;
    }

    main.insert(start, toInsert);
}

void binaryInsert(element toInsert, std::vector<element> & main) {

    auto start = main.begin();
    auto end =  getElement(toInsert.index, main);

    while (start < end) {
        auto mid = start + (end - start) / 2;
        if (mid->value < toInsert.value) {
            start = mid + 1;
        } else {
            end = mid;
        }
        comparisonCounter++;
    }

    if (COMMENTS) {
        std::cout << "Inserting: " << std::flush;
        std::cout << toInsert.index << " {" << std::flush;
        for (const auto& value : toInsert.element_vec) {
            std::cout << value << " ";
        }
        std::cout << "}" << " before " << end->value << std::endl;
    }

    main.insert(start, toInsert);
}

void initialSort(sortInfo & info) {

    std::vector<int>::iterator leftBegin;
	std::vector<int>::iterator leftEnd;
	std::vector<int>::iterator rightBegin;
	std::vector<int>::iterator rightEnd;

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
        comparisonCounter++;
    }
    if (info.totalElements % 2 == 1) {
        element outsider;
        outsider.element_vec.insert(outsider.element_vec.end(), rightEnd, rightEnd + info.elementSize);
        outsider.value = *(outsider.element_vec.end() - 1);
        info.outsider = outsider;
    }
}

void createMainAndPend(sortInfo & info) {

    std::vector<int>::iterator leftBegin;
	std::vector<int>::iterator leftEnd;
	std::vector<int>::iterator rightBegin;
	std::vector<int>::iterator rightEnd;

    auto it = info.initialSort.begin();
    for (int i = 0; i < info.comparisons; i++) {
        if (it >= info.initialSort.end()) {
            break ;
        }
		leftBegin = it;
		leftEnd = it + info.elementSize;
		rightBegin = it + info.elementSize;
		rightEnd = it + 2 * info.elementSize;
        element b;
        b.element_vec.insert(b.element_vec.end(), leftBegin, leftEnd);
        b.value = *(b.element_vec.end() - 1);
        b.index = i + 1;
        element a;
        a.element_vec.insert(a.element_vec.end(), rightBegin, rightEnd);
        a.value = *(a.element_vec.end() - 1);
        a.index = i + 1;
		if (i == 0) {
            info.main.insert(info.main.end(), b);
            info.main.insert(info.main.end(), a);
		}
        else {
            info.main.insert(info.main.end(), a);
            info.pend.insert(info.pend.end(), b);
        }
        it += 2 * info.elementSize;
    }

    if (COMMENTS) {
        std::cout << "Elements in main: " << std::endl;
        for (element e : info.main) {
            std::cout << "i:" << e.index << " value: " << e.value << " {" << std::flush;
            for (const auto& value : e.element_vec) {
                std::cout << value << " ";
            }
            std::cout << "}" << std::endl;
        }
        std::cout << std::endl;
    
        std::cout << "Elements in the pend: " << std::endl;
        for (element e : info.pend) {
            std::cout << "i:" << e.index << " value: " << e.value << " {" << std::flush;
            for (const auto& value : e.element_vec) {
                std::cout << value << " ";
            }
            std::cout << "}" << std::endl;
        }
        std::cout << std::endl;

        if (!info.outsider.element_vec.empty()) {
            std::cout << "Outsider element: " <<std::endl;
            std::cout << "value: " << info.outsider.value << " {" << std::flush;
            for (const auto& value : info.outsider.element_vec) {
                std::cout << value << " ";
            }
            std::cout << "}\n" << std::endl;
        }
    }
}

std::vector<int> mergeInsertSort(sortInfo info) {
    
    if (COMMENTS) {
        std::cout << "\nLEVEL: " << info.level << std::endl;
        std::cout << "Element size: " << info.elementSize << std::endl;
        std::cout << "\nInput values: " << std::endl;
        for (int i : info.args) {
            std::cout << i << " " << std::flush;
        }
        std::cout << std::endl;
    }

    initialSort(info);

    if (COMMENTS) {
        std::cout << "\nAfter initial sort: " << std::endl;
        for (int i : info.initialSort) {
            std::cout << i << " " << std::flush;
        }
        std::cout << std::endl;
    
        std::cout << "Outsider: " << std::endl;
        for (int i : info.outsider.element_vec) {
            std::cout << i << " " << std::flush;
        }
        std::cout << std::endl;
    }

    if (info.elementSize * 4 <= info.totalValues) {
        if (COMMENTS) {
            std::cout << "\nGoing deeper into recursion" << "----------------------------------" << std::endl;
        }
        sortInfo newInfo = info;
		newInfo.level = info.level + 1;
		newInfo.elementSize = std::pow(2, newInfo.level);
		newInfo.comparisons = info.totalValues / (newInfo.elementSize * 2);
		newInfo.args = info.initialSort;
		newInfo.initialSort.clear();
        newInfo.totalElements = info.totalElements / 2;
        newInfo.outsider.element_vec.clear();

		info.initialSort = mergeInsertSort(newInfo);
        if (COMMENTS) {
            std::cout << "\nGetting back from recursion" << "----------------------------------" << std::endl;
            std::cout << "\nLEVEL: " << info.level << std::endl;
            std::cout << "Element size: " << info.elementSize << std::endl;
        }
    }

    createMainAndPend(info);
    
    int elementsInPend = info.pend.size();
    for (int i = 3; i <= elementsInPend; i++) {     //i is the index in jacobsthal
        for (int j = info.jacobsthal[i]; j >= 2 && j > info.jacobsthal[i - 1]; j--) {   //j is the actual jacobsthal to insert
            try {
                if (info.pend.empty()) {
                    break ;
                }
                auto elementIt = getElement(j, info.pend);
                binaryInsert(*(elementIt), info.main);
                info.pend.erase(elementIt);
            }
            catch (...) {
                
            }
        }
    }

    while (!info.pend.empty()) {
        std::vector<element>::iterator toInsert = info.pend.end() - 1;
        binaryInsert(*toInsert, info.main);
        info.pend.erase(info.pend.end() -1);
    }

    if (!info.outsider.element_vec.empty()) {
        binaryInsertOutsider(info.outsider, info.main);
    }

    std::vector<int> sorted;
    for (element e : info.main) {
        for (int i : e.element_vec) {
            sorted.insert(sorted.end(), i);
        }
    }

    if (COMMENTS) {
        std::cout << "\nRETURNING: " << std::endl;
        for (int i : sorted) {
            std::cout << i << " " << std::flush;
        }
        std::cout << std::endl;
    }

    return (sorted);
}

std::vector<int> sort(std::vector<int> args, int size) {
	sortInfo info;
	info.level = 0;
	info.elementSize = 1;
	info.args = args;
	info.totalValues = size;
    info.totalElements = size;
	info.comparisons = info.totalValues / (info.elementSize * 2);
    info.jacobsthal = jacobsthalSequence();
    std::vector<int> sorted = mergeInsertSort(info);
    std::cout << "Comparisons: " << comparisonCounter << std::endl;
    comparisonCounter = 0;
	return (sorted);
}

std::vector<int> createArgVec(char *argv[]) {
    std::vector<int> argVec;
    for (int i = 0; argv[i] != NULL; i++) {
        int num = std::stoi(argv[i]);
        argVec.push_back(num);
    }
    return (argVec);
}

/*************************************************************************************************/

std::vector<int> jacobsthalSequence() {
    std::vector<int> result = {0, 1};
    for (int i = 2; i < 30; i++) {
        result.insert(result.end(), result[i - 1] + 2 * result[i - 2]);
    }
    return (result);
}
