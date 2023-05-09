#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    std::stringstream ss;
    std::vector<int> input_vec;
    long elem = 0;
    for (int i = 1; i < argc; i++) {
        ss.clear();
        ss.str(argv[i]);
        ss >> elem;
        if (elem > 2147483647 || elem < 0) {
            std::cout << "Invaild number." << '\n';
            return -1;
        }
        input_vec.push_back(elem);
    }
    int k;
    if (input_vec.size() % 2 == 0) k = 2;
    else k = 3;
    PmergeMe a = PmergeMe(k);
    a.sort(input_vec);
    for (std::vector<int>::iterator it = input_vec.begin(); it != input_vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << '\n';
    int tmp = *input_vec.begin();
    for (std::vector<int>::iterator it = ++input_vec.begin(); it != input_vec.end(); it++) {
        if (tmp > *it) {
            std::cout << "Faild." << '\n' << tmp << " " <<*it <<'\n';
            break;
        }
        tmp = *it;
    }
}
