#include "PmergeMe.hpp"
#include <iostream>

#include <vector>
#include <utility>  // For std::pair


int main(int argc, char *argv[]) {
    (void) argc;
    // if (argc <= 2) {
    //     std::cerr << "Missing more params" << std::endl;
    //     return 1;
    // }

    PmergeMe p;
    p.pmergeMe(argv + 1);

    return 0;
}
