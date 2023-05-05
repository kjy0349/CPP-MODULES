#include "RPN.hpp"

int main(int argc, char *argv[]){
    if (argc != 2) {
        std::cout << "Invaild input." << '\n';
        return 1;
    }
    Rpn rpn = Rpn();
    rpn.solution(argv[1]);
    rpn.print_ans();
}
