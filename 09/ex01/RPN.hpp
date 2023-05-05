#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <sstream>
# include <iostream>

class Rpn
{
	private:
		std::stack<std::string> stk;
		bool flag;
	public:
		Rpn(void);
		Rpn(const Rpn& obj);
		~Rpn();
		Rpn& operator=(const Rpn& obj);
		void solution(std::string input);
		int calculate(std::string opera);
		void print_ans(void);
};

#endif
