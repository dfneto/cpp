#ifndef PMERGEME
#define PMERGEME

#include	<iostream> 	//cout, cerr
#include	<vector>
#include 	<stdexcept>  // Required for standard exceptions


typedef std::vector<std::vector<int> > GroupedPairs;
// Overload operator<< for GroupedPairs
inline std::ostream& operator<<(std::ostream& os, const GroupedPairs& pairs) {
    os << "[";
    for (std::vector<std::vector<int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        os << " [";
        for (std::vector<int>::const_iterator vit = it->begin(); vit != it->end(); ++vit) {
            os << *vit;
            if (vit + 1 != it->end()) os << ", "; // Avoid trailing comma
        }
        os << "]";
    }
    os << " ]";
    return os;
}

class PmergeMe {
	private:
		PmergeMe(const PmergeMe &src);
		PmergeMe&		operator=(const PmergeMe &rhs);
		std::vector<int> convertInputIntoAVector(char **);
		void mergePairs(const GroupedPairs &input, size_t i, GroupedPairs &mergedPairs);
		void addInOrder(GroupedPairs &mergedPairs, const GroupedPairs &input, size_t i);
		GroupedPairs generatePairs(const GroupedPairs& input);
		void printGroupedPairs(const GroupedPairs& groups);
		bool isPairable(GroupedPairs &pairedValues);
		GroupedPairs initializePairs(const std::vector<int>& values);


	public:
		PmergeMe();
		~PmergeMe();
		void		pmergeMe(char **);
		
};

#endif
