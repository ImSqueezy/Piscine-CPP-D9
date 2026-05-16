#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <stdexcept>
# include <ctime>
# include <algorithm>
# include <iterator>

class PmergeMe {
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		void mergeInsertionSortVec(std::vector<int>& seq);
		void mergeInsertionSortDeq(std::deque<int>& seq);
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void parseInput(int ac, char** av);
		void sort();
};

#endif