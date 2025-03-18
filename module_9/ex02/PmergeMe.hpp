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
        std::vector<int> convertPairsToVector(const GroupedPairs &pairedValues);
        void mergePairs(const GroupedPairs &input, size_t i, GroupedPairs &mergedPairs);
        void addInOrder(GroupedPairs &mergedPairs, const GroupedPairs &input, size_t i);
        bool isPairable(size_t inputSize, size_t groupSize);
        GroupedPairs mergeAndSwap(const GroupedPairs &input);
        std::vector<int> mergeInsertion(std::vector<int> &result, size_t group_size);
        void extract(GroupedPairs &pairedVector, GroupedPairs &main, GroupedPairs &pend);
        void removeExtraElements(std::__1::vector<int> &result);
        void moveFromTo(GroupedPairs &pend, GroupedPairs &main);
        void log(GroupedPairs &pend, GroupedPairs &main, GroupedPairs &odd, GroupedPairs &rest);
        void printGroupedPairs(const GroupedPairs &groups);
        GroupedPairs initializePairs(const std::vector<int>& values);
        GroupedPairs getRest(GroupedPairs &pairedVector);
        GroupedPairs getOdd(GroupedPairs &pairedVector);
        void printVector(std::__1::vector<int> &result, const std::string &msg);
        GroupedPairs makeGroups(const std::vector<int>& result, size_t group_size);
        
        public:
		PmergeMe();
		~PmergeMe();
        void pmergeMe(std::vector<int> values);

};

#endif
