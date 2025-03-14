#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe &src) {
    (void) src;
}

// Define the splitPairs function
std::deque<GroupedPairs> PmergeMe::splitPairs(const std::vector<int> & group) {
    std::deque<GroupedPairs> main;
    GroupedPairs    b;
    std::vector<int> b_;
    GroupedPairs    a;
    std::vector<int> a_;
    for (size_t i = 0; i < group.size(); ++i) {
        if (i < group.size() / 2)
            b_.push_back(group[i]);
        else
            a_.push_back(group[i]);
    }
    b.push_back(b_);
    a.push_back(a_);
    main.push_back(b);
    main.push_back(a);
    return main;
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

void PmergeMe::printGroupedPairs(const GroupedPairs& groups) {
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
GroupedPairs PmergeMe::initializePairs(const std::vector<int>& values) {
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

    // TODO: fix this shit
    // If an odd element is left pair it with himself
    if (values.size() % 2 != 0) {
        std::vector<int> lastPair ;
        lastPair.push_back(values.back());
        lastPair.push_back(values.back());
        pairedValues.push_back(lastPair);
    }

    return pairedValues;
}

//Can I pair the values?
bool PmergeMe::isPairable(GroupedPairs &pairedValues)
{
    // When the order reaches 16, it is less than half the size of the list. 
    // In other words, we cannot make two pairs to swap them. At this point, 
    // we start using insertion. We divide the order by 2 and start sorting using insertion.
    // std::cout << "First pair size: " << pairedValues[0].size() << std::endl;
    // std::cout << "group size: " << pairedValues.size() << std::endl;
    if (pairedValues[0].size() == pairedValues[1].size())
    {
        return true;
    }
    return false;
}

// TODO: condição de parada aqui? Acho que somente se eu transformar de while para recursivo
// Function to merge adjacent groups (elements are the name of groups of numbers)
GroupedPairs PmergeMe::generatePairs(const GroupedPairs& input) {
    GroupedPairs mergedPairs;

    // Merge adjacent groups
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        //se o elements atual tem o mesmo tamanho do elements seguinte
        if (input[i].size() == input[i+1].size())
            mergePairs(input, i, mergedPairs);
        else
            addInOrder(mergedPairs, input, i);
    }

    // If an odd group is left, keep it in the next step
    if (input.size() % 2 != 0) {
        mergedPairs.push_back(input.back());
    }

    return mergedPairs;
}

//Add to the merged pairs in the same order they already are
void PmergeMe::addInOrder(GroupedPairs &mergedPairs, const GroupedPairs &input, size_t i)
{
    mergedPairs.push_back(input[i]);
    mergedPairs.push_back(input[i + 1]);
}

//Merge and sort by the last number adjacent groups
void PmergeMe::mergePairs(const GroupedPairs &input, size_t i, GroupedPairs &mergedPairs)
{
    std::vector<int> group;
    if (input[i].back() <= input[i + 1].back())
    {
        group.insert(group.end(), input[i].begin(), input[i].end());
        group.insert(group.end(), input[i + 1].begin(), input[i + 1].end());
    }
    else
    {
        group.insert(group.end(), input[i + 1].begin(), input[i + 1].end());
        group.insert(group.end(), input[i].begin(), input[i].end());
    }
    mergedPairs.push_back(group);
}

std::vector<int> PmergeMe::convertInputIntoAVector(char **argv)
{
    (void) argv;
    // Define a vector and manually insert elements (C++98 compatible)
    std::vector<int> values;
    int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    // int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7, 40, 41, 42, 43, 44, 45, 46, 47, 48};
    size_t size = sizeof(arr) / sizeof(arr[0]);


    std::cout << "[";
    // Copy elements from the array into the vector
    for (size_t i = 0; i < size; ++i) {
        values.push_back(arr[i]);
        std::cout << arr[i];
        if (i != size - 1)
            std::cout << ", ";
        else 
            // std::cout << std::endl;
            std::cout << "]" << std::endl;
    }
    return values;
}

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << ", ";  // Add a comma between elements
        }
    }
    std::cout << "]" << std::endl;
}

//Pair and merge the input into elements (pair of numbers, pair of pair of numbers etc.)
void PmergeMe::pmergeMe(char **argv)
{
    std::vector<int> values = convertInputIntoAVector(argv);

    //compare pairs of group_size and swap
    size_t group_size = 1;

    values = pairAndSwap(group_size, values);
    printVector(values);
}

std::vector<int> & PmergeMe::pairAndSwap(size_t group_size, std::vector<int> &values)
{
    int temp;

    if (group_size > values.size()/2) 
        return values;

    for (size_t i = group_size - 1; i + group_size < values.size(); i += 2 * group_size)
    {
        if (values[i] > values[i + group_size])
        {
            temp = values[i + group_size];
            values[i + group_size] = values[i];
            values[i] = temp;
        }
    }

    group_size = group_size * 2;

    // printVector(values);
    return pairAndSwap(group_size, values);
}
