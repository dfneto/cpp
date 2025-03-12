#ifndef PMERGEME
#define PMERGEME

#include	<iostream> 	//cout, cerr
#include	<vector>
#include 	<stdexcept>  // Required for standard exceptions

typedef std::vector<std::vector<int> > GroupedPairs;

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
