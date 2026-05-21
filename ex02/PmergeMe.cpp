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

		if (!(iss >> n) || n < 0 || (iss >> s))
			throw std::runtime_error("Error: invalid input");
		_vec.push_back(n);
		_deq.push_back(n);
	}
}

static std::vector<int> generateJacobsthalOrder(int n) {
	std::vector<int> jac, order;
	if (n <= 0) return order;
	jac.push_back(1); jac.push_back(3);
	while (jac.back() < n) jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);
	std::vector<bool> used(n, false);
	int prev = 0;
	for (size_t k = 0; k < jac.size(); ++k) {
		int hi = std::min(jac[k], n);
		for (int idx = hi; idx > prev; --idx) {
			if (!used[idx - 1]) { order.push_back(idx - 1); used[idx - 1] = true; }
		}
		prev = jac[k];
		if (prev >= n) break;
	}
	for (int i = 0; i < n; ++i) if (!used[i]) order.push_back(i);
	return order;
}

void	PmergeMe::mergeInsertionSortVec(std::vector<int>& seq) {
	int n = seq.size();
	if (n <= 1)
		return;
	bool odd = n % 2;
	int strag = 0;
	
	if (odd) { strag = seq.back(); seq.pop_back(); --n; }
	std::vector<std::pair<int, int> > pairs;
	for (int i = 0; i < n; i += 2) {
		int a = seq[i], b = seq[i+1];
		if (a < b) std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	std::vector<int> largers;
	for (size_t i = 0; i < pairs.size(); ++i) largers.push_back(pairs[i].first);
	mergeInsertionSortVec(largers);
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
	std::vector<int> chain;
	chain.push_back(sortedPairs[0].second);
	for (size_t i = 0; i < sortedPairs.size(); ++i) chain.push_back(sortedPairs[i].first);

	std::vector<int> pend;
	for (size_t i = 1; i < sortedPairs.size(); ++i) pend.push_back(sortedPairs[i].second);
	
	std::vector<int> pPos(pend.size());
	for (size_t i = 0; i < pend.size(); ++i)
		pPos[i] = i + 2;

	std::vector<int> order = generateJacobsthalOrder(pend.size());
	for (size_t k = 0; k < order.size(); ++k) {
		int idx = order[k], val = pend[idx], hi = pPos[idx];
		std::vector<int>::iterator it = std::lower_bound(chain.begin(), chain.begin() + hi, val);
		int pos = std::distance(chain.begin(), it);
		chain.insert(it, val);
		for (size_t j = 0; j < pPos.size(); ++j)
			if (pPos[j] >= pos) ++pPos[j];
	}
	if (odd)
		chain.insert(std::lower_bound(chain.begin(), chain.end(), strag), strag);
	seq = chain;
}

void	PmergeMe::mergeInsertionSortDeq(std::deque<int>& seq) {
	int n = seq.size();
	if (n <= 1)
		return;
	bool odd = n % 2;
	int strag = 0;

	if (odd) {
		strag = seq.back();
		seq.pop_back(); --n;
	}
	std::vector<std::pair<int, int> > pairs;
	for (int i = 0; i < n; i += 2) {
		int a = seq[i], b = seq[i+1];
		if (a < b) std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); ++i) largers.push_back(pairs[i].first);
	mergeInsertionSortDeq(largers);
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
	std::deque<int> chain;
	chain.push_back(sortedPairs[0].second);
	for (size_t i = 0; i < sortedPairs.size(); ++i)
		chain.push_back(sortedPairs[i].first);

	std::vector<int> pend;
	for (size_t i = 1; i < sortedPairs.size(); ++i)
		pend.push_back(sortedPairs[i].second);

	std::vector<int> pPos(pend.size());
	for (size_t i = 0; i < pend.size(); ++i)
		pPos[i] = i + 2;

	std::vector<int> order = generateJacobsthalOrder(pend.size());
	for (size_t k = 0; k < order.size(); ++k) {
		int idx = order[k], val = pend[idx], hi = pPos[idx];
		std::deque<int>::iterator it = std::lower_bound(chain.begin(), chain.begin() + hi, val);
		int pos = std::distance(chain.begin(), it);

		chain.insert(it, val);
		for (size_t j = 0; j < pPos.size(); ++j)
			if (pPos[j] >= pos) ++pPos[j];
	}
	if (odd)
		chain.insert(std::lower_bound(chain.begin(), chain.end(), strag), strag);
	seq = chain;
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