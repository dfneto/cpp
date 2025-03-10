
#include <iostream>
#include <vector>
#include <utility>  // For std::pair

int main() {
   // Define a vector and manually insert elements (C++98 compatible)
   std::vector<int> values;
   int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
   size_t size = sizeof(arr) / sizeof(arr[0]);

   // Copy elements from the array into the vector
   for (size_t i = 0; i < size; ++i) {
       values.push_back(arr[i]);
   }
    // Vector to store pairs
    std::vector<std::pair<int, int> > paired_values;

    // Iterate through the vector in steps of 2
    for (size_t i = 0; i + 1 < values.size(); i += 2) {
        paired_values.push_back(std::make_pair(values[i], values[i + 1]));
    }

    // Print the pairs
    std::cout << "Paired values:\n";
    for (size_t i = 0; i < paired_values.size(); ++i) {
        std::cout << "(" << paired_values[i].first << ", " << paired_values[i].second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
