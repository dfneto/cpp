#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <set>

static std::string validate_arg(std::string arg)
{
    if (arg[0] == '-')
        return "Negative numbers are not allowed";
    long nbr = strtol(arg.c_str(), NULL, 10);
    if (nbr == 0 && arg != "0")
        return "Non-number arguments not allowed";
    if (nbr > INT_MAX || errno == ERANGE)
        return "Too big arguments are not allowed";
    return "";
}

static std::string validate(int argc, char** argv)
{
    if (argc == 1)
        return "No arguments were provided";
    for (int i = 1; i < argc; i++)
    {
        std::string status = validate_arg(argv[i]);
        if (status != "")
            return status;
    }
    return "";
}

static std::vector<int> argv_to_vector(int argc, char** argv)
{
    std::vector<int> res;
    //Reallocations are usually costly operations in terms of performance. The reserve() 
    //function can be used to eliminate reallocations if the number of elements is known beforehand.
    res.reserve(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

static std::deque<int> argv_to_deque(int argc, char** argv)
{
    std::deque<int> res;
    for (int i = 1; i < argc; i++)
    {
        res.push_back(atoi(argv[i]));
    }
    return res;
}

static std::set<int> argv_to_set(int argc, char** argv)
{
    std::set<int> res;
    for (int i = 1; i < argc; i++)
    {
        res.insert(atoi(argv[i]));
    }
    return res;
}

template <typename T> static bool is_sorted(const T& container)
{
    if (container.size() == 0 || container.size() == 1)
        return true;
    typename T::const_iterator end = container.end();
    std::advance(end, -1);
    for (typename T::const_iterator it = container.begin(); it != end; it++)
    {
        typename T::const_iterator next = it;
        std::advance(next, 1);
        if (*it > *next)
            return false;
    }
    return true;
}

static std::string argv_to_str(int argc, char** argv)
{
    std::string res("");
    res.reserve(argc + 1);
    res += "[";
    res += argv[1];
    for (int i = 2; argv[i]; i++)
    {
        res += " ";
        res += argv[i];
    }
    res += "]";
    return res;
}

static std::string vec_to_str(std::vector<int>& vec)
{
    std::stringstream ss;
    ss << "[" << vec[0];
    for (size_t i = 1; i < vec.size(); i++)
    {
        ss << " " << vec[i];
    }
    ss << "]";
    return ss.str();
}

static bool retained_original_values(std::set<int>& original_values, std::vector<int>& vec)
{
	for (int i = 0; i < (int)vec.size(); i++)
	{
		if (original_values.find(vec[i]) == original_values.end())
			return false;
		original_values.erase(vec[i]);
	}
	return true;
}

int main(int argc, char** argv)
{
    PmergeMe pm;
	
    std::string status = validate(argc, argv);
    if (status != "")
    {
        std::cerr << "Error: " << status << "\n";
        return EXIT_FAILURE;
    }
  	std::set<int> original_values = argv_to_set(argc, argv);

    clock_t start_vec = clock();
    std::vector<int> vec = argv_to_vector(argc, argv);
    vec = pm.pmergeMe(vec); 
    clock_t end_vec = clock();
    double time_elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

    // clock_t start_deque = clock();
    // std::deque<int> deque = argv_to_deque(argc, argv);
    // pm.sort_deque(deque);
    // clock_t end_deque = clock();
    // double time_elapsed_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;

    //TODO: entender isso
    if (!is_sorted(vec) || (int)vec.size() != (argc - 1) || !retained_original_values(original_values, vec))
	{
        std::cout << "Vector was not sorted properly.\n";
		return 1;
	}
    // if (!is_sorted(deque) || (int)deque.size() != (argc - 1))
	// {
    //     std::cout << "Deque was not sorted properly.\n";
	// 	return 1;
	// }

    std::cout << "\033[31mBefore\033[00m: " << argv_to_str(argc, argv) << "\n";
    std::cout << "\033[32mAfter\033[00m:  " << vec_to_str(vec) << "\n";
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << std::fixed << std::setprecision(6)
               << time_elapsed_vec << "s\n";
    // std::cout << "Time to process a range of " << deque.size()
    //           << " elements with std::deque:  " << std::fixed << std::setprecision(6)
    //           << time_elapsed_deque << "s\n";
	std::cout << "Number of comparisons: " << PmergeMe::nbrOfComps << '\n';
}

// int main_chat(int argc, char** argv)
// {
//     PmergeMe pm;
    
//     std::string status = validate(argc, argv);
//     if (status != "")
//     {
//         std::cerr << "Error: " << status << "\n";
//         return EXIT_FAILURE;
//     }
//       std::set<int> original_values = argv_to_set(argc, argv);

//     clock_t start_vec = clock();
//     std::vector<int> vec = argv_to_vector(argc, argv);
//     vec = pm.pmergeMe(vec); 
//     clock_t end_vec = clock();
//     double time_elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

//     // Debug prints
//     std::cout << "Original values: ";
//     for (const auto& val : original_values) {
//         std::cout << val << " ";
//     }
//     std::cout << "\n";

//     std::cout << "Sorted vector: ";
//     for (const auto& val : vec) {
//         std::cout << val << " ";
//     }
//     std::cout << "\n";

//     if (!is_sorted(vec) || (int)vec.size() != (argc - 1) || !retained_original_values(original_values, vec))
//     {
//         std::cout << "Vector was not sorted properly.\n";
//         return 1;
//     }

//     std::cout << "\033[31mBefore\033[00m: " << argv_to_str(argc, argv) << "\n";
//     std::cout << "\033[32mAfter\033[00m:  " << vec_to_str(vec) << "\n";
//     std::cout << "Time to process a range of " << vec.size()
//               << " elements with std::vector: " << std::fixed << std::setprecision(6)
//                << time_elapsed_vec << "s\n";
//     std::cout << "Number of comparisons: " << PmergeMe::nbrOfComps << '\n';
// }

// int main() {
//     PmergeMe pm;

//     // Manually initializing the std::vector (C++98 compatible)
//     std::vector<int> vec;
//     vec.push_back(11);
//     vec.push_back(2);
//     vec.push_back(17);
//     vec.push_back(0);
//     vec.push_back(16);
//     vec.push_back(8);
//     vec.push_back(6);
//     vec.push_back(15);
//     vec.push_back(10);
//     vec.push_back(3);

//     // Sorting the std::vector
//     std::vector<int> sortedVec = pm.sortVec(vec);

//     std::cout << "Sorted Vector: ";
//     // Use traditional for loop instead of range-based for loop
//     for (size_t i = 0; i < sortedVec.size(); ++i) {
//         std::cout << sortedVec[i] << " ";
//     }
//     std::cout << std::endl;

//     // Manually initializing the std::deque (C++98 compatible)
//     std::deque<int> deq;
//     deq.push_back(14);
//     deq.push_back(22);
//     deq.push_back(9);
//     deq.push_back(3);
//     deq.push_back(19);
//     deq.push_back(1);
//     deq.push_back(16);
//     deq.push_back(8);

//     // Sorting the std::deque
//     std::deque<int> sortedDeque = pm.sortDeque(deq);

//     std::cout << "Sorted Deque: ";
//     // Use traditional for loop instead of range-based for loop
//     for (size_t i = 0; i < sortedDeque.size(); ++i) {
//         std::cout << sortedDeque[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }
