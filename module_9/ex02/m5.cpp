#include <iostream>
#include <vector>

typedef std::vector<std::vector<int> > GroupedPairs;

// Generic function to create pairs or group existing pairs
GroupedPairs generatePairs(const GroupedPairs& input) {
    GroupedPairs mergedPairs;

    // Stop if the number of groups is odd (we can't continue merging evenly)
    if (input.size() % 2 != 0) {
        return input;
    }

    // Merge adjacent groups
    for (size_t i = 0; i < input.size(); i += 2) {
        std::vector<int> group;
        group.insert(group.end(), input[i].begin(), input[i].end());

        // Merge the next group if it exists
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

// Function to initialize pairing from a list of numbers
GroupedPairs initializePairs(const std::vector<int>& values) {
    GroupedPairs pairedValues;

    // Ensure even number of elements
    if (values.size() % 2 != 0) {
        std::cerr << "Warning: The number of elements is odd. The last element will be left alone." << std::endl;
    }

    for (size_t i = 0; i + 1 < values.size(); i += 2) {
        std::vector<int> pair;
        pair.push_back(values[i]);
        pair.push_back(values[i + 1]);
        pairedValues.push_back(pair);
    }

    return pairedValues;
}

int main() {
    // Step 1: Start with an initial list of numbers
    std::vector<int> values = {2, 11, 0, 17, 8, 16, 6, 15, 3, 10, 1, 21, 9, 18, 14, 19, 5, 12, 4, 20, 7, 13};

    // Create initial pairs
    GroupedPairs pairedValues = initializePairs(values);
    std::cout << "Step 1:" << std::endl;
    printGroupedPairs(pairedValues);

    // Continue merging pairs
    int step = 2;
    while (pairedValues.size() > 1) {
        pairedValues = generatePairs(pairedValues);

        std::cout << "Step " << step << ":" << std::endl;
        printGroupedPairs(pairedValues);
        step++;
    }

    return 0;
}
