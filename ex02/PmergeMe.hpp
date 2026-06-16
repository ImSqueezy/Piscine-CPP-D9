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
# include <iomanip>

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		std::vector<int>	generateJacobsthalOrder(int n);

		template<typename Container>
		void	mergeInsertionSort(Container& seq) {
			int		n = seq.size();
			int		strag = 0;
			bool	odd = n % 2;

			if (n <= 1)
				return ;
			if (odd) {
				strag = seq.back();
				seq.pop_back();
				n--;
			}
			std::vector<std::pair<int, int> > pairs;
			for (int i = 0; i < n; i += 2) {
				int first = seq[i];
				int second = seq[i+1];

				if (first < second)
					std::swap(first, second);
				pairs.push_back(std::make_pair(first, second));
			}
			Container			largers;
			for (size_t i = 0; i < pairs.size(); ++i)
				largers.push_back(pairs[i].first);
			mergeInsertionSort(largers);
			std::vector<std::pair<int, int> > sortedPairs;
			for (size_t i = 0; i < largers.size(); ++i) {
				for (size_t j = 0; j < pairs.size(); ++j) {
					if (pairs[j].first == largers[i]) {
						sortedPairs.push_back(pairs[j]);
						pairs.erase(pairs.begin() + j);
						break;
					}
				}
			}
			Container			chain;
			chain.push_back(sortedPairs[0].second);
			for (size_t i = 0; i < sortedPairs.size(); ++i)
				chain.push_back(sortedPairs[i].first);
			std::vector<int>	pend;
			for (size_t i = 1; i < sortedPairs.size(); ++i)
				pend.push_back(sortedPairs[i].second);
			std::vector<int>	jacobsthalOrder = generateJacobsthalOrder(pend.size());
			for (size_t i = 0; i < jacobsthalOrder.size(); ++i) {
				int idx = jacobsthalOrder[i];
				if (idx >= static_cast<int>(pend.size()))
					break;
				int element = pend[idx];
				typename Container::iterator it = std::upper_bound(chain.begin(), chain.end(), element);
				chain.insert(it, element);
			}
			seq.clear();
			for (size_t i = 0; i < chain.size(); ++i)
				seq.push_back(chain[i]);
			if (odd)
				seq.insert(std::lower_bound(seq.begin(), seq.end(), strag), strag);
		}

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void parseInput(int ac, char** av);
		void sort();
};

#endif