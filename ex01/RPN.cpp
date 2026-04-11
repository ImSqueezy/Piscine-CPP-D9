#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

bool	RPN::isOperator(char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	RPN::applyOperator(char op) {
	(void)op;
	if (_stack.size() < 2) {
		std::cerr << "Error" << std::endl;
		return false;
	}
	return true;
}

bool	RPN::evaluate(const std::string& expression) {
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token) {
		std::cout << token << std::endl;
		if (token.length() == 1 && isdigit(token[0]))
			_stack.push(token[0] - '0');
		else if (token.length() == 1 && isOperator(token[0])) {
			// it would return false if:
			//  - the stack size is less than 2
			//  - division by zero
			if (!applyOperator(token[0]))
				return false;
		} else {
			std::cerr << "Error" << std::endl;
			return false;
		}
	}
	return true;
}