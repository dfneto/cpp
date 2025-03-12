#include <iostream>
#include <vector>

//ok
typedef std::vector<std::vector<int> > GroupedPairs;

void mergePairs(const GroupedPairs &input, size_t i, GroupedPairs &mergedPairs);

void addInOrder(GroupedPairs &mergedPairs, const GroupedPairs &input, size_t i);

// ok
GroupedPairs generatePairs(const GroupedPairs& input) {
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

//ok
void addInOrder(GroupedPairs &mergedPairs, const GroupedPairs &input, size_t i)
{
    mergedPairs.push_back(input[i]);
    mergedPairs.push_back(input[i + 1]);
}

//ok
void mergePairs(const GroupedPairs &input, size_t i, GroupedPairs &mergedPairs)
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

// ok
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

// ok
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

    // TODO: fix this shit
    // If an odd element is left pair it with MAX_INT
    if (values.size() % 2 != 0) {
        std::vector<int> lastPair ;
        lastPair.push_back(values.back());
        lastPair.push_back(1000);
        pairedValues.push_back(lastPair);
    }

    return pairedValues;
}

bool isPairable(GroupedPairs &pairedValues);

int main()
{
    // ok
    int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7, 40, 41, 42, 43, 44, 45, 46, 47, 48};
    
    std::vector<int> values;
    for (int i = 0; i < 31; i++) {
        values.push_back(arr[i]);
    }

    GroupedPairs pairedValues = initializePairs(values);
    std::cout << "Step 1:" << std::endl;
    printGroupedPairs(pairedValues);

    // Continue merging pairs
    int step = 2;
    while (isPairable(pairedValues))
    { 
        pairedValues = generatePairs(pairedValues);

        std::cout << "Step " << step << ":" << std::endl;
        printGroupedPairs(pairedValues);
        step++;
    }

    return 0;
}

//ok
bool isPairable(GroupedPairs &pairedValues)
{
    // std::cout << "First pair size: " << pairedValues[0].size() << std::endl;
    // std::cout << "group size: " << pairedValues.size() << std::endl;
    if (pairedValues[0].size() == pairedValues[1].size())
    {
        return true;
    }
    return false;
}

// TODO 1:
// Criar uma condicao para que eu pare no step 3, seja no main seja na funcao que julgo ser melhor
// Step 1:
// (2, 11) (0, 17) (8, 16) (6, 15) (3, 10) (1, 21) (9, 18) (14, 19) (5, 12) (4, 20) (7, 13) 
// Step 2:
// (2, 11, 0, 17) (6, 15, 8, 16) (3, 10, 1, 21) (9, 18, 14, 19) (5, 12, 4, 20) (7, 13) 
// Step 3:
// (6, 15, 8, 16, 2, 11, 0, 17) (9, 18, 14, 19, 3, 10, 1, 21) (5, 12, 4, 20) (7, 13) 
// Step 4:
// (6, 15, 8, 16, 2, 11, 0, 17, 9, 18, 14, 19, 3, 10, 1, 21) (5, 12, 4, 20) (7, 13) 
