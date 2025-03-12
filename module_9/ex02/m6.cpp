#include <iostream>
#include <deque>
#include <vector>

int main() {
    // Define a deque of vectors of integers
    std::deque<std::vector<int> > dq;

    // Create some vectors and add them to the deque
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    std::vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    std::vector<int> v3;
    v3.push_back(7);
    v3.push_back(8);
    // v3.push_back(9);

    // Push vectors into the deque
    dq.push_back(v1);
    dq.push_back(v2);
    dq.push_back(v3);

    // Iterate through the deque and print each vector
    for (std::deque<std::vector<int> >::iterator it = dq.begin(); it != dq.end(); ++it) {
        std::cout << "[ ";
        for (std::vector<int>::iterator vit = it->begin(); vit != it->end(); ++vit) {
            std::cout << *vit << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
