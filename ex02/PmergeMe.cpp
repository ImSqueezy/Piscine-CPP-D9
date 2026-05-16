#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) { _vec = src._vec; _deq = src._deq; }
	return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int ac, char** av) {
	for (int i = 1; i < ac; ++i) {
		std::istringstream iss(av[i]);
		int n;
		std::string s;
		if (!(iss >> n) || n < 0 || (iss >> s)) throw std::runtime_error("Error: invalid input");
		_vec.push_back(n); _deq.push_back(n);
	}
}

void PmergeMe::sort() {
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << (i ? " " : "") << _vec[i];
	std::cout << "\n";

	std::clock_t s1 = std::clock();
	mergeInsertionSortVec(_vec);
	std::clock_t e1 = std::clock();

	std::clock_t s2 = std::clock();
	mergeInsertionSortDeq(_deq);
	std::clock_t e2 = std::clock();

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << (i ? " " : "") << _vec[i];
	std::cout << "\n";

	std::cout << "Time to process a range of " << _vec.size()
				<< " elements with std::vector : " << (double)(e1 - s1) / CLOCKS_PER_SEC * 1e6 << " us\n";
	std::cout << "Time to process a range of " << _deq.size()
				<< " elements with std::deque  : " << (double)(e2 - s2) / CLOCKS_PER_SEC * 1e6 << " us\n";
}