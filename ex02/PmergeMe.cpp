#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        this->_vec = src._vec;
        this->_deq = src._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::parseInput(int ac, char** av) {
	for (int i = 1; i < ac; ++i) {
		std::istringstream	iss(av[i]);
		int					n;
		if (!(iss >> n) || n < 0)
			throw std::runtime_error("Error: invalid input");
		std::string leftover;
		if (iss >> leftover)
			throw std::runtime_error("Error: invalid input");
		_vec.push_back(n);
		_deq.push_back(n);
	}
}

void	PmergeMe::sort() {
	// view what's in _vec and _deq
	std::cout << "_deq has: " << std::endl;
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "_vec has: " << std::endl;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it) {
		std::cout << *it << std::endl;
	}
}