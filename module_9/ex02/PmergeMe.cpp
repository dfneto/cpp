#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe &src) {
    (void) src;
}

// Define the splitPairs function
// std::deque<GroupedPairs> PmergeMe::splitPairs(const std::vector<int> & group) {
//     std::deque<GroupedPairs> main;
//     GroupedPairs    b;
//     std::vector<int> b_;
//     GroupedPairs    a;
//     std::vector<int> a_;
//     for (size_t i = 0; i < group.size(); ++i) {
//         if (i < group.size() / 2)
//             b_.push_back(group[i]);
//         else
//             a_.push_back(group[i]);
//     }
//     b.push_back(b_);
//     a.push_back(a_);
//     main.push_back(b);
//     main.push_back(a);
//     return main;
// }

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

//Make groups of group_size size and what doesn't fit in the group is added to the last group
GroupedPairs makeGroups(const std::vector<int>& result, size_t group_size) {
    GroupedPairs groups;
    size_t i = 0;
    while (i < result.size()) {
        std::vector<int> group;
        size_t j = 0;
        while (j < group_size && i + j < result.size()) {
            group.push_back(result[i + j]);
            j++;
        }
        groups.push_back(group);
        i += group_size;
    }
    return groups;
}

void PmergeMe::printVector(std::__1::vector<int> &result, const std::string &msg)
{
    std::cout << msg << ": ";
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i];
        if (i != result.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
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

// Function to initialize pairing from a list of numbers. Eg:
// input: 11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7
// output: (2, 11) (0, 17) (8, 16) (6, 15) (3, 10) (1, 21) (9, 18) (14, 19) (5, 12) (4, 20) (7, 13)
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

// Can I pair the values?
// When the order reaches 16, it is less than half the size of the list. 
// In other words, we cannot make two pairs to swap them. At this point, 
// we start using insertion. We divide the order by 2 and start sorting using insertion.
bool PmergeMe::isPairable(size_t inputSize, size_t groupSize)
{
    if (groupSize > inputSize / 2)
        return false;
    return true;
}

// TODO: condição de parada aqui? Acho que somente se eu transformar de while para recursivo
// Function to merge adjacent groups (elements are the name of groups of numbers)
GroupedPairs PmergeMe::mergeAndSwap(const GroupedPairs& input) {
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

std::vector<int> PmergeMe::convertPairsToVector(const GroupedPairs& pairedValues) {
    std::vector<int> result;
    for (size_t i = 0; i < pairedValues.size(); i++) {
        for (size_t j = 0; j < pairedValues[i].size(); j++) {
            result.push_back(pairedValues[i][j]);
        }
    }
    return result;
}

// Split pairedVector into main, pend, odd, and rest
void PmergeMe::splitSortInsert(GroupedPairs& pairedVector, size_t group_size) {
    (void) pairedVector;
    std::cout << "splitSortInsert called with group_size: " << group_size << std::endl;
    
}

GroupedPairs PmergeMe::getRest(GroupedPairs &pairedVector) {
    GroupedPairs rest;
    size_t lastGroupSize = pairedVector.back().size();
    if (lastGroupSize != pairedVector[0].size())
        rest = makeGroups(pairedVector.back(), pairedVector.back().size());
    pairedVector.erase(pairedVector.end() - 1);
    return rest;
}

GroupedPairs PmergeMe::getOdd(GroupedPairs &pairedVector) {
    GroupedPairs odd;
    if (pairedVector.size() % 2 == 1)
        odd = makeGroups(pairedVector.back(), pairedVector.back().size());
    pairedVector.erase(pairedVector.end() - 1);
    return odd;
}

// Define the mergeInsertion function
std::vector<int> PmergeMe::mergeInsertion(std::vector<int>& result, size_t group_size) {
    // std::sort(result.begin(), result.end());
    //gs = 16 não faço nada
    group_size /= 4;                                                            // gs=8
    GroupedPairs pairedVector = makeGroups(result, group_size);
    printGroupedPairs(pairedVector);
    
    //separar em main pend oddd rest e insert usando jacobsthal number
    GroupedPairs main;
    GroupedPairs pend;
    GroupedPairs rest = getRest(pairedVector);
    GroupedPairs odd = getOdd(pairedVector);

    for (size_t i = 0; i < pairedVector.size(); i++)
    {
        if (i < 2)
            main.push_back(pairedVector[i]);
        else if (i % 2 == 1)
            main.push_back(pairedVector[i]);
        else if (i % 2 == 0)
            pend.push_back(pairedVector[i]);
    }

    
    
    
    
    result = convertPairsToVector(pairedVector);
    
    if (group_size == 1)
        return result;
    return mergeInsertion(result, group_size);


}

//Pair the input into pairs of numbers
//Merge and swap the pairs into pairs of pairs and so on
//Finally apply merge-insertion sort using Jacobsthal's number
void PmergeMe::pmergeMe(char **argv)
{
    std::vector<int> values = convertInputIntoAVector(argv);
    size_t inputSize = values.size();

    // Create pair of numbers. 1 2 -> (1, 2)
    GroupedPairs pairedValues = initializePairs(values);
    // std::cout << "Step 1:" << std::endl;
    // printGroupedPairs(pairedValues);
    
    size_t group_size = 2;

    // Merging and swap pairs
    // int step = 2;
    while (isPairable(inputSize, group_size)) 
    { 
        //make pair and swap
        pairedValues = mergeAndSwap(pairedValues);
        group_size *= 2;
        // std::cout << "Step " << step << ":" << std::endl;
        // printGroupedPairs(pairedValues);
        // step++;
    }
    
    std::vector<int> result = convertPairsToVector(pairedValues);

    printVector(result, "Final result before merge and swap");

    result = mergeInsertion(result, group_size);
    printVector(result, "Final result after merge and swap");


    // //Start to use insertion
    // std::deque<GroupedPairs> main;
    // std::deque<GroupedPairs> pend;
    // std::deque<int> odd;
    // std::deque<int> rest;
    
    // main = splitPairs(pairedValues[0]);

    // //Iteracao 1: separar o pairedValues em main, odd e rest
    // for (size_t i = 0; i < pairedValues.size(); i++)
    // {
    //     for (size_t j = 0; j < pairedValues[i].size(); j++)
    //     {
    //         if (i == 1)
    //             odd.push_back(pairedValues[i][j]);
    //         else if (i == 2)
    //             rest.push_back(pairedValues[i][j]);
    //     }
    // }

    // // Iterate through the deque and print each vector
    // std::cout << "Main: ";
    // for (std::deque<GroupedPairs>::iterator it = main.begin(); it != main.end(); ++it) {
    //     std::cout << *it;
    //     if (it + 1 != main.end())
    //         std::cout << ", ";
    // }
    // std::cout << "\nOdd: ";
    // for (std::deque<int>::iterator it = odd.begin(); it != odd.end(); ++it) {
    //     std::cout << *it;
    //     if (it + 1 != odd.end())
    //         std::cout << ", ";
    // }
    // std::cout << "\nRest: ";
    // for (std::deque<int>::iterator it = rest.begin(); it != rest.end(); ++it) {
    //     std::cout << *it;
    //     if (it + 1 != rest.end())
    //         std::cout << ", ";
    // }
    // std::cout << std::endl;

    // //Iteracao 2: separar o main em main e pend
    // for (size_t i = 0; i < main.size(); i++)
    // {
    //     if (i % 2 == 0)
    //         main.push_back(main[i]);
    //     else
    //         pend.push_back(main[i]);
    // }
}
