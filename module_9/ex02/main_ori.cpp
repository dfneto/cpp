#include "PmergeMe.hpp"
#include <iostream>

#include <vector>
#include <utility>  // For std::pair


int main(int argc, char *argv[]) {
    (void) argc;
    PmergeMe p;
    p.pmergeMe(argv + 1);

    return 0;
}
