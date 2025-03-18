#ifndef PMERGEME
#define PMERGEME

#include	<iostream> 	//cout, cerr
#include	<vector>


typedef std::vector<std::vector<int> > GroupedPairs;

class PmergeMe {
	private:
        int         _toRemove;                  //gambiarra to remove a possible extra element added

		PmergeMe(const PmergeMe &src);
		PmergeMe&		operator=(const PmergeMe &rhs);

        void mergePairs(const GroupedPairs &input, size_t i, GroupedPairs &mergedPairs);
        void addInOrder(GroupedPairs &mergedPairs, const GroupedPairs &input, size_t i);
        void extract(GroupedPairs &pairedVector, GroupedPairs &main, GroupedPairs &pend);
        void removeExtraElements(std::__1::vector<int> &result);
        void moveFromTo(GroupedPairs &pend, GroupedPairs &main);
        void log(GroupedPairs &pend, GroupedPairs &main, GroupedPairs &odd, GroupedPairs &rest);
        void printGroupedPairs(const GroupedPairs &groups);
        void printVector(std::__1::vector<int> &result, const std::string &msg);
        bool isPairable(size_t inputSize, size_t groupSize);
        std::vector<int> convertPairsToVector(const GroupedPairs &pairedValues);
        std::vector<int> mergeInsertion(std::vector<int> &result, size_t group_size);
        GroupedPairs mergeAndSwap(const GroupedPairs &input);
        GroupedPairs initializePairs(const std::vector<int>& values);
        GroupedPairs getRest(GroupedPairs &pairedVector);
        GroupedPairs getOdd(GroupedPairs &pairedVector);
        GroupedPairs makeGroups(const std::vector<int>& result, size_t group_size);
        
    public:
        static int  nbrOfComps;
		
        PmergeMe();
		~PmergeMe();
        std::vector<int> pmergeMe(std::vector<int> values);

};

#endif
