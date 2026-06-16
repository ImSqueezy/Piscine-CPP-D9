#include "PmergeMe.hpp"

static const double CLOCK_TO_MICROSECONDS = CLOCKS_PER_SEC * 1e6;

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

		if (!(iss >> n) || n < 0 || (iss >> s))
			throw std::runtime_error("Error: invalid input");
		_vec.push_back(n);
		_deq.push_back(n);
	}
}

std::vector<int> PmergeMe::generateJacobsthalOrder(int n) {
	std::vector<int> jac, order;
	if (n <= 0)
		return order;
	jac.push_back(1);
	jac.push_back(3);
	while (jac.back() < n)
		jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);
	std::vector<bool> used(n, false);
	int prev = 0;
	for (size_t k = 0; k < jac.size(); ++k) {
		int hi = std::min(jac[k], n);
		for (int idx = hi; idx > prev; --idx) {
			if (!used[idx - 1]) { order.push_back(idx - 1); used[idx - 1] = true; }
		}
		prev = jac[k];
		if (prev >= n)
			break;
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i])
			order.push_back(i);
	}
	return order;
}

void PmergeMe::sort() {
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << (i ? " " : "") << _vec[i];
	std::cout << "\n";

	std::clock_t s1 = std::clock();
	mergeInsertionSort(_vec);
	std::clock_t e1 = std::clock();

	std::clock_t s2 = std::clock();
	mergeInsertionSort(_deq);
	std::clock_t e2 = std::clock();

	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << (i ? " " : "") << _vec[i];
	std::cout << "\n";

	std::cout << "Time to process a range of " << _vec.size()
				<< " elements with std::vector : " << (double)(e1 - s1) / CLOCK_TO_MICROSECONDS << " us\n";
	std::cout << "Time to process a range of " << _deq.size()
				<< " elements with std::deque  : " << (double)(e2 - s2) / CLOCK_TO_MICROSECONDS << " us\n";
}