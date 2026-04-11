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
	if (_stack.size() < 2) {
		std::cerr << "Error: Second Operand needed!" << std::endl;
		return false;
	}
	int	b, a, result;
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	if (op == '+')
	 	result = a + b;
	else if (op == '-')
	 	result = a - b;
	else if (op == '*')
	 	result = a * b;
	else {
		if (b == 0) {
			std::cerr << "Error: Division by zero!" << std::endl;
			return false;
		}
	 	result = a / b;
	}
	_stack.push(result);
	return true;
}

bool	RPN::evaluate(const std::string& expression) {
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token) {
		if (token.length() == 1 && isdigit(token[0]))
			_stack.push(token[0] - '0');
		else if (token.length() == 1 && isOperator(token[0])) {
			if (!applyOperator(token[0]))
				return false;
		} else {
			std::cerr << "Error" << std::endl;
			return false;
		}
	}
	std::cout << _stack.top() << std::endl;
	return true;
}