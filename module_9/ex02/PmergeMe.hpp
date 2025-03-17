#ifndef PMERGEME
#define PMERGEME

#include	<iostream> 	//cout, cerr
#include	<vector>


typedef std::vector<std::vector<int> > GroupedPairs;

class PmergeMe {
	private:
        int     _toRemove;                  //gambiarra to remove a possible extra element added
		PmergeMe(const PmergeMe &src);
		PmergeMe&		operator=(const PmergeMe &rhs);
		std::vector<int> convertInputIntoAVector(char **);
        std::vector<int> convertPairsToVector(const GroupedPairs &pairedValues);
        void splitSortInsert(GroupedPairs &pairedVector, size_t group_size);
        void mergePairs(const GroupedPairs &input, size_t i, GroupedPairs &mergedPairs);
        void addInOrder(GroupedPairs &mergedPairs, const GroupedPairs &input, size_t i);
        bool isPairable(size_t inputSize, size_t groupSize);
        GroupedPairs mergeAndSwap(const GroupedPairs &input);
        std::vector<int> mergeInsertion(std::vector<int> &result, size_t group_size);
        void printGroupedPairs(const GroupedPairs &groups);
        GroupedPairs initializePairs(const std::vector<int>& values);
        GroupedPairs getRest(GroupedPairs &pairedVector);
        GroupedPairs getOdd(GroupedPairs &pairedVector);

    public:
		PmergeMe();
		~PmergeMe();
        void pmergeMe(char **);
        void printVector(std::__1::vector<int> &result, const std::string &msg);

};

#endif
