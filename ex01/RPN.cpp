#include "RNP.hpp"

RNP::RNP() {}

RNP::~RNP() {}

RNP::RNP(const RNP& other) {
	*this = other;
}

RNP& RNP::operator=(const RNP& other) {
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

bool	RNP::evaluate(const std::string& expression) {
	(void)expression;
	return 0;
}