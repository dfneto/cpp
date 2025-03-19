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
        GroupedPairs mergeAndSwap(const GroupedPairs &input);
        GroupedPairs initializePairs(const std::vector<int>& values);
        GroupedPairs getRest(GroupedPairs &pairedVector);
        GroupedPairs getOdd(GroupedPairs &pairedVector);
        GroupedPairs makeGroups(const std::vector<int>& result, size_t group_size);

        template <typename Container>
        Container convertPairsToContainer(const GroupedPairs& pairedValues) {
            Container result;
            for (size_t i = 0; i < pairedValues.size(); i++) {
                for (size_t j = 0; j < pairedValues[i].size(); j++) {
                    result.push_back(pairedValues[i][j]);
                }
            }
            return result;
        }

        template <typename Container>
        void removeExtraElements(Container& result);

        template <typename Container>
        GroupedPairs makeGroups(const Container& result, size_t group_size);

        template <typename Container>
        Container mergeInsertionSort(Container& result, size_t group_size) {
            group_size /= 2;

            // Use the generic makeGroups function
            GroupedPairs pairedVector = makeGroups(result, group_size);
            
            GroupedPairs main;
            GroupedPairs pend;
            GroupedPairs rest = getRest(pairedVector);
            GroupedPairs odd = getOdd(pairedVector);

            extract(pairedVector, main, pend);
            moveFromTo(pend, main);
            // moveFromTo(odd, main);
            if (!odd.empty())
            {
                for (size_t i = 0; i < main.size(); i++)
                {
                    if (odd.back().back() < main[i].back()) {
                        main.insert(main.begin() + i, odd.back());
                        odd.pop_back();
                        break;
                    }
                }
            }

            // Add odd and rest to main
            main.insert(main.end(), odd.begin(), odd.end());
            main.insert(main.end(), rest.begin(), rest.end());

            // Convert to the correct container type (vector or deque)
            result = convertPairsToContainer<Container>(main);

            if (group_size == 1) {
                removeExtraElements(result);
                return result;
            }

            return mergeInsertionSort(result, group_size);
        }

        
        public:
        static int  nbrOfComps;
		
        PmergeMe();
		~PmergeMe();
        
        //Pair the input into pairs of numbers
        //Merge and swap the pairs into pairs of pairs and so on
        //Finally apply merge-insertion sort using Jacobsthal's number
        template <typename Container>
        Container pmergeMe(Container values)
        {
            size_t inputSize = values.size();

            // Create pair of numbers. 1 2 -> (1, 2)
            GroupedPairs pairedValues = initializePairs(values);
            
            size_t group_size = 2;

            // Merging and swapping pairs
            while (isPairable(inputSize, group_size)) 
            { 
                pairedValues = mergeAndSwap(pairedValues);
                group_size *= 2;
            }
            
            // Container result = convertPairsToVector(pairedValues);
            Container result = convertPairsToContainer<Container>(pairedValues);

            return mergeInsertionSort(result, group_size);
        }

        
};

#endif
