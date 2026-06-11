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
				return ;
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

			// Example: pairs [(3,1), (5,2)] → largers [3, 5]
			Container largers;
			std::cout << "size here is: " << pairs.size() << std::endl;
			for (size_t i = 0; i < pairs.size(); ++i)
				largers.push_back(pairs[i].first);

			mergeInsertionSort(largers);

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