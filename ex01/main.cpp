#include "RNP.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr	<< "Error: Invalid number of args!" 
					<< std::endl
					<< "Usage: ./RNP \"<expression>\""
					<< std::endl;
		return 1;
	}

	RNP p_calculator;
	if (!p_calculator.evaluate(av[1])) // it takes the arg and evaluates it.
		return 1;
	return 0;
}