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
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		static std::vector<int>	generateJacobsthalOrder(int n);

		template<typename Container>
		void	mergeInsertionSort(Container& seq) {
			int		n = seq.size();

			if (n <= 1)
				return 0;
			int		strag = 0;
			bool	odd = n % 2;

			(void)strag;
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
			std::vector<std::pair<int, int> >::iterator it;

			for (it = pairs.begin(); it != pairs.end(); ++it) {
				std::cout << "first: " << it->first
						  << ", second: " << it->second
						  << std::endl;
			}

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