#ifndef RNP_hPP
#define RNP_hPP

# include <iostream>
// enables pop() push() top() size() and empty()
# include <stack>

class RNP {
	private:
		std::stack<int>	_stack;
	public:
		RNP();
		RNP(const RNP& other);
		RNP& operator=(const RNP& other);
		~RNP();

		bool evaluate(const std::string& expression);
};

#endif