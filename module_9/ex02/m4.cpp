#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > GroupedPairs;

// Function to pair elements into groups of 2, then 4, then 8...
GroupedPairs generatePairs(const GroupedPairs& input) {
    GroupedPairs mergedPairs;

    // If only 2 groups remain, return them
    if (input.size() <= 2) {
        return input;
    }

    // Merge adjacent groups
    for (size_t i = 0; i < input.size(); i += 2) {
        std::vector<int> group;
        group.insert(group.end(), input[i].begin(), input[i].end());

        if (i + 1 < input.size()) {
            group.insert(group.end(), input[i + 1].begin(), input[i + 1].end());
        }

        mergedPairs.push_back(group);
    }

    return mergedPairs;
}

// Function to print the grouped pairs
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

int main() {
    // Step 1: Initial input as individual numbers
    std::vector<int> values = {2, 11, 0, 17, 8, 16, 6, 15, 3, 10, 1, 21, 9, 18, 14, 19, 5, 12, 4, 20, 7, 13};
    
    // Convert single values into groups of 2
    GroupedPairs paired_values;
    for (size_t i = 0; i < values.size(); i += 2) {
        std::vector<int> pair;
        pair.push_back(values[i]);
        pair.push_back(values[i + 1]);
        paired_values.push_back(pair);
    }

    // Print the first pairing
    std::cout << "Step 1:" << std::endl;
    printGroupedPairs(paired_values);

    // Continue merging pairs
    int step = 2;
    while (paired_values.size() > 1) {
        paired_values = generatePairs(paired_values);
        std::cout << "Step " << step << ":" << std::endl;
        printGroupedPairs(paired_values);
        step++;
    }

    return 0;
}
