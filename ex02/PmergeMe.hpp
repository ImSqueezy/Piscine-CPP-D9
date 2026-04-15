#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <stdexcept>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

    public:
    	PmergeMe();
    	PmergeMe(const PmergeMe &src);
    	PmergeMe &operator=(const PmergeMe &src);
    	~PmergeMe();

		void	parseInput(int ac, char** av);
		void	sort();
};

#endif