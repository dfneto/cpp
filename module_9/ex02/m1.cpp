//easy version
#include <iostream>
#include <vector>
#include <utility>  // For std::pair

typedef std::vector<std::pair<int, int> > PairVector;
typedef std::vector<std::vector<int> > GroupedPairs;

GroupedPairs mergePairs(const PairVector& paired_values) {
    GroupedPairs mergedPairs;
    
    // Ensure we have an even number of pairs
    // if (paired_values.size() % 2 != 0) {
    //     std::cerr << "Error: Number of pairs is not even!" << std::endl;
    //     return mergedPairs;
    // }

    // Merge adjacent pairs
    for (size_t i = 0; i < paired_values.size(); i += 2) {
        std::vector<int> group;
        group.push_back(paired_values[i].first);
        group.push_back(paired_values[i].second);
        group.push_back(paired_values[i + 1].first);
        group.push_back(paired_values[i + 1].second);
        mergedPairs.push_back(group);
    }

    return mergedPairs;
}

int main() {
    // Example input: Initial pairs
    PairVector paired_values = {
        std::make_pair(2, 11), std::make_pair(0, 17),
        std::make_pair(8, 16), std::make_pair(6, 15),
        std::make_pair(3, 10), std::make_pair(1, 21),
        std::make_pair(9, 18), std::make_pair(14, 19),
        std::make_pair(5, 12), std::make_pair(4, 20),
        std::make_pair(7, 13)
    };

    // Get merged groups
    GroupedPairs result = mergePairs(paired_values);

    // Print output
    std::cout << "Merged Pairs:" << std::endl;
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "(";
        for (size_t j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
            if (j < result[i].size() - 1) std::cout << ", ";
        }
        std::cout << ")" << std::endl;
    }

    return 0;
}
