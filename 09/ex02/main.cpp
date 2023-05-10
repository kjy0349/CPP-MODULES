#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char *argv[]) {
    std::stringstream ss;
    std::vector<int> input_vec;
    std::deque<int> input_deq;
    int elem = 0;
    for (int i = 1; i < argc; i++) {
        ss.clear();
        ss.str(argv[i]);
        ss >> elem;
        if (elem < 0 || ss.fail()) {
            std::cout << "Error\n";
            return -1;
        }
        input_vec.push_back(elem);
        input_deq.push_back(elem);
    }
    if (input_vec.empty() || input_deq.empty()) {
        std::cout << "Error\n";
        return -1;
    }
    PmergeMe a = PmergeMe(5);
    double sort_time;
    std::cout << "Before:   ";
    for (std::vector<int>::iterator it = input_vec.begin(); it != input_vec.end(); it++) {
        std::cout << *it << " ";
    }
    clock_t start_v = clock();
    a.sort(input_vec);
    clock_t end_v = clock();
    clock_t start_d = clock();
    a.sort(input_deq);
    clock_t end_d = clock();
    std::cout << "\nAfter:    ";
    for (std::vector<int>::iterator it = input_vec.begin(); it != input_vec.end(); it++) {
        std::cout << *it << " ";
    }
    sort_time = ((double)end_v - start_v) / CLOCKS_PER_SEC * 1000000;
    std::cout << "\nTime to process a range of " << input_vec.size() << " elements with " << "std::vector" << " : " << sort_time << " us\n";
    sort_time = ((double)end_d - start_d) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << input_vec.size() << " elements with " << "std::deque" << "  : " << sort_time << " us\n";
    int tmp = *input_vec.begin();
    for (std::vector<int>::iterator it = ++input_vec.begin(); it != input_vec.end(); it++) {
        if (tmp > *it) {
            std::cout << "Faild." << '\n' << tmp << " " <<*it <<'\n';
            break;
        }
        tmp = *it;
    }
    tmp = *input_deq.begin();
    for (std::deque<int>::iterator it = ++input_deq.begin(); it != input_deq.end(); it++) {
        if (tmp > *it) {
            std::cout << "Faild." << '\n' << tmp << " " <<*it <<'\n';
            break;
        }
        tmp = *it;
    }
}
