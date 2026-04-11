#ifndef RPN_hPP
#define RPN_hPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN {
	private:
		std::stack<int>	_stack;

		bool	isOperator(char c) const;
		bool	applyOperator(char op);
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		bool evaluate(const std::string& expression);
};

#endif