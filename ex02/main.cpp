#include "PmergeMe.hpp"

int	main(int ac, char** av) {
	if (ac < 2) {
		std::cerr << "Error: Usage: ./PmergeMe <int1> <int2> ..." << std::endl;
		return 1;
	}
	// try catch because i will throw errors when an invalid input is given or else
	try {
		PmergeMe sorter;
		sorter.parseInput(ac, av);
		// i will later have this sort the numbers, i don't know how yet
		sorter.sort();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}