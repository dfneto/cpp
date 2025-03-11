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


	public:
		PmergeMe();
		~PmergeMe();
		void		pmergeMe(char **);
		
};

#endif
