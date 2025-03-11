#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe &src) {
    (void) src;
}

PmergeMe&		PmergeMe::operator=(const PmergeMe &rhs) {
    (void) rhs;
    return *this;
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void printGroupedPairs(const GroupedPairs& groups) {
    for (size_t i = 0; i < groups.size(); i++) {
        std::cout << "(";
        for (size_t j = 0; j < groups[i].size(); j++) {
            std::cout << groups[i][j];
            if (j < groups[i].size() - 1) std::cout << ", ";
        }
        std::cout << ") ";
    }
    std::cout << std::endl;
}

// Function to initialize pairing from a list of numbers
GroupedPairs initializePairs(const std::vector<int>& values) {
    GroupedPairs pairedValues;

    for (size_t i = 0; i + 1 < values.size(); i += 2) {
        std::vector<int> pair;
        if (values[i] < values[i+1]) {
            pair.push_back(values[i]);
            pair.push_back(values[i + 1]);
        } else {
            pair.push_back(values[i + 1]);
            pair.push_back(values[i]);
        }
        pairedValues.push_back(pair);
    }

    return pairedValues;
}

//Pair and merge the input into elements (pair of numbers, pair of pair of numbers etc.)
void PmergeMe::pmergeMe(char **argv)
{
    std::vector<int> values = convertInputIntoAVector(argv);
       

    GroupedPairs pairedValues = initializePairs(values);
    std::cout << "Step 1:" << std::endl;
    printGroupedPairs(pairedValues);

}

std::vector<int> PmergeMe::convertInputIntoAVector(char **argv)
{
    (void) argv;
    // Define a vector and manually insert elements (C++98 compatible)
    std::vector<int> values;
    int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    size_t size = sizeof(arr) / sizeof(arr[0]);


    // Copy elements from the array into the vector
    for (size_t i = 0; i < size; ++i) {
        values.push_back(arr[i]);
        std::cout << arr[i];
        if (i != size - 1)
            std::cout << ", ";
        else 
            std::cout << std::endl;
    }
    return values;
}
