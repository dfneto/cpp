#include "PmergeMe.hpp"
#include <iostream>

#include <vector>
#include <utility>  // For std::pair


// TODO: tenho que reler os artigos para criar a condicao de parada de pairing
// atualmente estou fazendo o Step 1: the division into the pairs & sorting

//TODO: implement error message in standard error4
//TODO: management of errors related to duplicates. Should I check the input for some error?
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
