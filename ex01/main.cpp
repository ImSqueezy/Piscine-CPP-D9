#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr	<< "Error: Invalid number of args!" 
					<< std::endl
					<< "Usage: ./RPN \"<expression>\""
					<< std::endl;
		return 1;
	}

	RPN p_calculator;
	if (!p_calculator.evaluate(av[1]))
		return 1;
	return 0;
}