#include "RPN.hpp"

Rpn::Rpn(void) {
    this->flag = true;
}

Rpn::Rpn(const Rpn& obj) {
    this->stk = obj.stk;
    this->flag = true;
}

Rpn::~Rpn() {

}

Rpn &Rpn::operator=(const Rpn& obj) {
    if(this == &obj) return *this;
	
	this->stk = obj.stk;
    this->flag = obj.flag;
	return (*this);    
}

long Rpn::calculate(std::string oper) {
    std::stringstream ss;
    int op1;
    int op2;
    
    if (!stk.empty())
        ss.str(stk.top());
    else {
        flag = false;
        return -1;
    }
    stk.pop();
    ss >> op2;
    ss.clear();
    if (!stk.empty())
        ss.str(stk.top());
    else {
        flag = false;
        return -1;
    }
    stk.pop();
    ss >> op1;
    if (oper.compare("+") == 0) {
        return op1 + op2;
    } else if (oper.compare("-") == 0) {
        return op1 - op2;
    } else if (oper.compare("*") == 0) {
        return op1 * op2;
    } else if (oper.compare("/") == 0) {
        return op1 / op2;
    } else return 0;
}

void Rpn::solution(std::string input) {
    std::stringstream ss(input);
    std::string elem;
    long sub_sum;
    while (ss >> elem) {
        if (elem.compare("0") > 0 && elem.compare("9") <= 0)
            stk.push(elem);
        else if (elem == "+" || elem == "-" || elem == "*" || elem == "/") {
            sub_sum = calculate(elem);
            if (sub_sum > 2147483647 || sub_sum < -2147483648) {
                this->flag = false;
                return ;
            }
            stk.push(std::to_string(sub_sum));
        }
        else {
            this->flag = false;
            return ;
        }
    }
}

void Rpn::print_ans(void) {
    std::stringstream ss;
    if (this->flag && stk.size() == 1) {
        std::cout << stk.top() << '\n';
    } else {
        std::cout << "Error\n";
    }
}
