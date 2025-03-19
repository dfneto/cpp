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
        void moveFromTo(GroupedPairs &pend, GroupedPairs &main);
        void log(GroupedPairs &pend, GroupedPairs &main, GroupedPairs &odd, GroupedPairs &rest);
        void printGroupedPairs(const GroupedPairs &groups);
        void printVector(std::__1::vector<int> &result, const std::string &msg);
        bool isPairable(size_t inputSize, size_t groupSize);
        std::vector<int> convertPairsToVector(const GroupedPairs &pairedValues);
        GroupedPairs mergeAndSwap(const GroupedPairs &input);
        GroupedPairs getRest(GroupedPairs &pairedVector);
        GroupedPairs getOdd(GroupedPairs &pairedVector);

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
        GroupedPairs makeGroups(const Container& result, size_t group_size) {
            GroupedPairs groups;
            typename Container::const_iterator it = result.begin();
            
            while (it != result.end()) {
                std::vector<int> group;
                size_t j = 0;
                
                // Create groups with `group_size` elements
                while (j < group_size && it != result.end()) {
                    group.push_back(*it);
                    ++it;
                    ++j;
                }
                groups.push_back(group);
            }
            return groups;
        }


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

        template <typename Container>
        void removeExtraElements(Container& result) {
            for (size_t i = 0; i < result.size(); i++) {
                if (result[i] == _toRemove) {
                    result.erase(result.begin() + i);
                    break;
                }
            }
        }

        template <typename Container>
        void printContainer(Container& container, const std::string& msg) {
            std::cout << msg;
            for (size_t i = 0; i < container.size(); i++) {
                std::cout << container[i];
                if (i < container.size() - 1) std::cout << ", ";
            }
            std::cout << std::endl;
        }

        template <typename Container>
        GroupedPairs initializePairs(const Container& values) {
            GroupedPairs pairedValues;

            // Iterate over the container to create pairs
            for (typename Container::size_type i = 0; i + 1 < values.size(); i += 2) {
                std::vector<int> pair;  // Always use std::vector<int> for pairs
                if (values[i] < values[i + 1]) {
                    pair.push_back(values[i]);
                    pair.push_back(values[i + 1]);
                } else {
                    pair.push_back(values[i + 1]);
                    pair.push_back(values[i]);
                }
                pairedValues.push_back(pair);
            }

            // If an odd element is left, pair it with itself and remove it in the end
            if (values.size() % 2 != 0) {
                std::vector<int> lastPair;  // Always use std::vector<int> for the last pair
                lastPair.push_back(values.back());
                lastPair.push_back(values.back());
                _toRemove = values.back();
                pairedValues.push_back(lastPair);
            }

            return pairedValues;
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

            result = mergeInsertionSort(result, group_size);
            printContainer(result, "Sorted container: ");
            return result;
        }

};

#endif
