#ifndef PMERGEME
#define PMERGEME

#include	<iostream> 	//cout, cerr
#include	<vector>
// #include 	<deque>


typedef std::vector<std::vector<int> > GroupedPairs;
// Overload operator<< for GroupedPairs
// inline std::ostream& operator<<(std::ostream& os, const GroupedPairs& pairs) {
//     // os << "[";
//     for (std::vector<std::vector<int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
//         os << " [";
//         for (std::vector<int>::const_iterator vit = it->begin(); vit != it->end(); ++vit) {
//             os << *vit;
//             if (vit + 1 != it->end()) os << ", "; // Avoid trailing comma
//         }
//         os << "]";
//     }
//     // os << " ]";
//     return os;
// }

class PmergeMe {
	private:
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
        // std::deque<GroupedPairs> splitPairs(const std::vector<int> &group);

    public:
		PmergeMe();
		~PmergeMe();
        void pmergeMe(char **);

        void printVector(std::__1::vector<int> &result, const std::string &msg);

};

#endif
