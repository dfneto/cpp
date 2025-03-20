#include "PmergeMe.hpp"

int PmergeMe::nbrOfComps = 0;

PmergeMe::PmergeMe(const PmergeMe &src) {
    (void) src;
}

PmergeMe&		PmergeMe::operator=(const PmergeMe &rhs) {
    (void) rhs;
    return *this;
}

PmergeMe::PmergeMe() : _toRemove(-1)
{
}

PmergeMe::~PmergeMe()
{
}

//Make groups of group_size size and what doesn't fit in the group is added to the last group
// GroupedPairs PmergeMe::makeGroups(const std::vector<int>& result, size_t group_size) {
//     GroupedPairs groups;
//     size_t i = 0;
//     while (i < result.size()) {
//         std::vector<int> group;
//         size_t j = 0;
//         while (j < group_size && i + j < result.size()) {
//             group.push_back(result[i + j]);
//             j++;
//         }
//         groups.push_back(group);
//         i += group_size;
//     }
//     return groups;
// }

void PmergeMe::printVector(std::vector<int> &result, const std::string &msg)
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
// GroupedPairs PmergeMe::initializePairs(const std::vector<int>& values) {
//     GroupedPairs pairedValues;

//     for (size_t i = 0; i + 1 < values.size(); i += 2) {
//         std::vector<int> pair;
//         if (values[i] < values[i+1]) {
//             pair.push_back(values[i]);
//             pair.push_back(values[i + 1]);
//         } else {
//             pair.push_back(values[i + 1]);
//             pair.push_back(values[i]);
//         }
//         pairedValues.push_back(pair);
//     }

//     // If an odd element is left pair it with himself
//     // and remove it in the end
//     if (values.size() % 2 != 0) {
//         std::vector<int> lastPair ;
//         lastPair.push_back(values.back());
//         lastPair.push_back(values.back());
//         _toRemove = values.back();
//         pairedValues.push_back(lastPair);
//     }

//     return pairedValues;
// }

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

std::vector<int> PmergeMe::convertPairsToVector(const GroupedPairs& pairedValues) {
    std::vector<int> result;
    for (size_t i = 0; i < pairedValues.size(); i++) {
        for (size_t j = 0; j < pairedValues[i].size(); j++) {
            result.push_back(pairedValues[i][j]);
        }
    }
    return result;
}



GroupedPairs PmergeMe::getRest(GroupedPairs &pairedVector) {
    GroupedPairs rest;
    size_t lastGroupSize = pairedVector.back().size();
    if (lastGroupSize != pairedVector[0].size()) {
        rest = makeGroups(pairedVector.back(), pairedVector.back().size());
        pairedVector.erase(pairedVector.end() - 1);
    }
    return rest;
}

GroupedPairs PmergeMe::getOdd(GroupedPairs &pairedVector) {
    GroupedPairs odd;
    if (pairedVector.size() % 2 == 1) {
        odd = makeGroups(pairedVector.back(), pairedVector.back().size());
        pairedVector.erase(pairedVector.end() - 1);
    }
    return odd;
}

//Extract main and pend vector from pairedVector
void PmergeMe::extract(GroupedPairs &pairedVector, GroupedPairs &main, GroupedPairs &pend)
{
    for (size_t i = 0; i < pairedVector.size(); i++)
    {
        if (i < 2)
            main.push_back(pairedVector[i]);
        else if (i % 2 == 1)
            main.push_back(pairedVector[i]);
        else if (i % 2 == 0)
            pend.push_back(pairedVector[i]);
    }
}

//If we added en extra element, remove it
// void PmergeMe::removeExtraElements(std::vector<int> &result)
// {
//     for (size_t i = 0; i < result.size(); i++)
//     {
//         if (result[i] == _toRemove)
//         {
//             result.erase(result.begin() + i);
//             break;
//         }
//     }
// }



//This should be done ideally using jacobsthal's number
void PmergeMe::moveFromTo(GroupedPairs &vec, GroupedPairs &main)
{
    if (!vec.empty())
    {
        for (size_t i = 0; i < vec.size(); i++)
        {
            for (size_t j = 0; j < main.size(); j++)
            {
                if (vec[i].back() <= main[j].back())
                {
                    PmergeMe::nbrOfComps++;
                    main.insert(main.begin() + j, vec[i]);
                    break;
                }
            }
        }
    }
}

void PmergeMe::log(GroupedPairs &pend, GroupedPairs &main, GroupedPairs &odd, GroupedPairs &rest)
{
    std::cout << "Pend: ";
    printGroupedPairs(pend);
    std::cout << "Main: ";
    printGroupedPairs(main);
    std::cout << "Odd: ";
    printGroupedPairs(odd);
    std::cout << "Rest: ";
    printGroupedPairs(rest);
}

// Define the mergeInsertion function
// std::vector<int> PmergeMe::mergeInsertion(std::vector<int>& result, size_t group_size) {
    // group_size /= 2;                                                           
    // GroupedPairs pairedVector = makeGroups(result, group_size);
    
    // GroupedPairs main;
    // GroupedPairs pend;
    // GroupedPairs rest = getRest(pairedVector);
    // GroupedPairs odd = getOdd(pairedVector);

    // extract(pairedVector, main, pend);

    // // log(pend, main, odd, rest);

    // moveFromTo(pend, main);
    // moveFromTo(odd, main);

    // //Add odd and rest to main
    // main.insert(main.end(), odd.begin(), odd.end());
    // main.insert(main.end(), rest.begin(), rest.end());

    // result = convertPairsToVector(main);
    
    // if (group_size == 1)
    // {
    //     removeExtraElements(result);
    //     return result;
    // }
    // return mergeInsertion(result, group_size);

// }
