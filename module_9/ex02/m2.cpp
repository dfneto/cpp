//easy version 2
#include <iostream>
#include <vector>
#include <utility>  // For std::pair

typedef std::vector<std::vector<int> > GroupedPairs;

GroupedPairs mergePairs(const GroupedPairs& paired_values) {
    GroupedPairs mergedPairs;

    // If we reach the final stage with 2 groups, return as is
    if (paired_values.size() == 2) {
        return paired_values;
    }

    // Ensure we have an even number of groups
    // if (paired_values.size() % 2 != 0) {
    //     std::cerr << "Error: Number of pairs is not even!" << std::endl;
    //     return mergedPairs;
    // }

    // Merge adjacent groups
    for (size_t i = 0; i < paired_values.size(); i += 2) {
        std::vector<int> group;
        group.insert(group.end(), paired_values[i].begin(), paired_values[i].end());
        group.insert(group.end(), paired_values[i + 1].begin(), paired_values[i + 1].end());
        mergedPairs.push_back(group);
    }

    // Recursively merge again
    return mergePairs(mergedPairs);
}

int main() {
    // Initial pairing
    GroupedPairs paired_values = {
        {2, 11}, {0, 17}, {8, 16}, {6, 15}, {3, 10}, {1, 21}, {9, 18}, {14, 19}, {5, 12}, {4, 20}, {7, 13}
    };

    // First level merge
    GroupedPairs firstMerge = mergePairs(paired_values);

    // Print results
    std::cout << "Final Merged Pairs:" << std::endl;
    for (size_t i = 0; i < firstMerge.size(); i++) {
        std::cout << "(";
        for (size_t j = 0; j < firstMerge[i].size(); j++) {
            std::cout << firstMerge[i][j];
            if (j < firstMerge[i].size() - 1) std::cout << ", ";
        }
        std::cout << ")" << std::endl;
    }

    return 0;
}
