
#include "PmergeMe.hpp"

/*************************************************************************************************/
// DEQUE

std::deque<element<std::deque>>::iterator getElement(int jacobsthal, std::deque<element<std::deque>> & deque) {
    for (auto it = deque.begin(); it != deque.end(); it++) {
        if (it->index == jacobsthal) {
            return (it);
        }
    }
    return (deque.end());
}

void binaryInsert(element<std::deque> toInsert, std::deque<element<std::deque>> & main) {

    auto start = main.begin();
    auto end = getElement(toInsert.index, main);

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
        std::cout << "index: " << toInsert.index << " value: " << toInsert.value << " {" << std::flush;
        for (const auto& value : toInsert.element_vec) {
            std::cout << value << " ";
        }
        std::cout << "}" << " before " << start->value << std::endl;
    }

    main.insert(start, toInsert);
}

void initialSort(sortInfo<std::deque> & info) {

    std::deque<int>::iterator leftBegin;
	std::deque<int>::iterator leftEnd;
	std::deque<int>::iterator rightBegin;
	std::deque<int>::iterator rightEnd;

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
        element<std::deque> outsider;
        outsider.element_vec.insert(outsider.element_vec.end(), rightEnd, rightEnd + info.elementSize);
        outsider.value = *(outsider.element_vec.end() - 1);
        info.outsider = outsider;
    }
}

void createMainAndPend(sortInfo<std::deque> & info) {

    std::deque<int>::iterator leftBegin;
	std::deque<int>::iterator leftEnd;
	std::deque<int>::iterator rightBegin;
	std::deque<int>::iterator rightEnd;

    auto it = info.initialSort.begin();
    int i = 0;
    for ( ; i < info.comparisons; i++) {
        if (it >= info.initialSort.end()) {
            break ;
        }
		leftBegin = it;
		leftEnd = it + info.elementSize;
		rightBegin = it + info.elementSize;
		rightEnd = it + 2 * info.elementSize;
        element<std::deque> b;
        b.element_vec.insert(b.element_vec.end(), leftBegin, leftEnd);
        b.value = *(b.element_vec.end() - 1);
        b.index = i + 1;
        element<std::deque> a;
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

    if (!info.outsider.element_vec.empty()) {
        info.outsider.index = i + 1;
        info.pend.insert(info.pend.end(), info.outsider);
        info.outsider.element_vec.clear();
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
    }
}

std::deque<int> mergeInsertSort(sortInfo<std::deque> info) {
    
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
        sortInfo<std::deque> newInfo = info;
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
                if (elementIt == info.pend.end()) {
                    elementIt--;
                }
                binaryInsert(*(elementIt), info.main);
                info.pend.erase(elementIt);
            }
            catch (...) {
                
            }
        }
    }

    while (!info.pend.empty()) {
        std::deque<element<std::deque>>::iterator toInsert = info.pend.end() - 1;
        binaryInsert(*toInsert, info.main);
        info.pend.erase(info.pend.end() -1);
    }


    std::deque<int> sorted;
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

std::deque<int> sort(std::deque<int> args, int size) {
    if (COMMENTS) {
        std::cout << "\n----DEQUE---------------------------------------------------------------------------" << std::endl;
    }
	sortInfo<std::deque> info;
	info.level = 0;
	info.elementSize = 1;
	info.args = args;
	info.totalValues = size;
    info.totalElements = size;
	info.comparisons = info.totalValues / (info.elementSize * 2);
    info.jacobsthal = jacobsthalSequence();
    std::deque<int> sorted = mergeInsertSort(info);
	return (sorted);
}

std::deque<int> createArgDeq(char *argv[]) {
    std::deque<int> argVec;
    for (int i = 0; argv[i] != NULL; i++) {
        int num = std::stoi(argv[i]);
        argVec.push_back(num);
    }
    return (argVec);
}

/*************************************************************************************************/
// VECTOR

std::vector<element<std::vector>>::iterator getElement(int jacobsthal, std::vector<element<std::vector>> & vector) {
    for (auto it = vector.begin(); it != vector.end(); it++) {
        if (it->index == jacobsthal) {
            return (it);
        }
    }
    return (vector.end());
}

void binaryInsert(element<std::vector> toInsert, std::vector<element<std::vector>> & main) {

    auto start = main.begin();
    auto end = getElement(toInsert.index, main);

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
        std::cout << "index: " << toInsert.index << " value: " << toInsert.value << " {" << std::flush;
        for (const auto& value : toInsert.element_vec) {
            std::cout << value << " ";
        }
        std::cout << "}" << " before " << start->value << std::endl;
    }

    main.insert(start, toInsert);
}

void initialSort(sortInfo<std::vector> & info) {

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
        element<std::vector> outsider;
        outsider.element_vec.insert(outsider.element_vec.end(), rightEnd, rightEnd + info.elementSize);
        outsider.value = *(outsider.element_vec.end() - 1);
        info.outsider = outsider;
    }
}

void createMainAndPend(sortInfo<std::vector> & info) {

    std::vector<int>::iterator leftBegin;
	std::vector<int>::iterator leftEnd;
	std::vector<int>::iterator rightBegin;
	std::vector<int>::iterator rightEnd;

    auto it = info.initialSort.begin();
    int i = 0;
    for ( ; i < info.comparisons; i++) {
        if (it >= info.initialSort.end()) {
            break ;
        }
		leftBegin = it;
		leftEnd = it + info.elementSize;
		rightBegin = it + info.elementSize;
		rightEnd = it + 2 * info.elementSize;
        element<std::vector> b;
        b.element_vec.insert(b.element_vec.end(), leftBegin, leftEnd);
        b.value = *(b.element_vec.end() - 1);
        b.index = i + 1;
        element<std::vector> a;
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

    if (!info.outsider.element_vec.empty()) {
        info.outsider.index = i + 1;
        info.pend.insert(info.pend.end(), info.outsider);
        info.outsider.element_vec.clear();
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
    }
}

std::vector<int> mergeInsertSort(sortInfo<std::vector> info) {
    
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
        sortInfo<std::vector> newInfo = info;
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
                if (elementIt == info.pend.end()) {
                    elementIt--;
                }
                binaryInsert(*(elementIt), info.main);
                info.pend.erase(elementIt);
            }
            catch (...) {
                
            }
        }
    }

    while (!info.pend.empty()) {
        std::vector<element<std::vector>>::iterator toInsert = info.pend.end() - 1;
        binaryInsert(*toInsert, info.main);
        info.pend.erase(info.pend.end() -1);
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
    if (COMMENTS) {
        std::cout << "\n----VECTOR-------------------------------------------------------------------------" << std::endl;
    }
	sortInfo<std::vector> info;
	info.level = 0;
	info.elementSize = 1;
	info.args = args;
	info.totalValues = size;
    info.totalElements = size;
	info.comparisons = info.totalValues / (info.elementSize * 2);
    info.jacobsthal = jacobsthalSequence();
    std::vector<int> sorted = mergeInsertSort(info);
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
