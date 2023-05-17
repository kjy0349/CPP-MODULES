#include "PmergeMe.hpp"
#include <sys/time.h>

int main(int argc, char *argv[]) {
    std::stringstream ss;
    std::vector<int> input_vec;
    std::deque<int> input_deq;
    std::string tmp;
    int elem = 0;
    int K = 5;
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
        ss >> tmp;
        if (!ss.fail()) {
            std::cout << "Error\n";
            return -1;
        }
    }
    if (input_vec.empty() || input_deq.empty()) {
        std::cout << "Error\n";
        return -1;
    }
    PmergeMe a = PmergeMe(K);
    long sort_time;
    std::cout << "Before:   ";
    for (std::vector<int>::iterator it = input_vec.begin(); it != input_vec.end(); it++) {
        std::cout << *it << " ";
    }
    struct timeval start_v, end_v, start_d, end_d;
    gettimeofday(&start_v, NULL);
    a.sort(input_vec);
    gettimeofday(&end_v, NULL);
    gettimeofday(&start_d, NULL);
    a.sort(input_deq);
    gettimeofday(&end_d, NULL);
    std::cout << "\nAfter:    ";
    for (std::vector<int>::iterator it = input_vec.begin(); it != input_vec.end(); it++) {
        std::cout << *it << " ";
    }
    sort_time = (end_v.tv_sec - start_v.tv_sec) * 1000000 + (end_v.tv_usec - start_v.tv_usec);
    std::cout << "\nTime to process a range of " << input_vec.size() << " elements with " << "std::vector" << " : " << sort_time << " us\n";
    sort_time = (end_d.tv_sec - start_d.tv_sec) * 1000000 + (end_d.tv_usec - start_d.tv_usec);
    std::cout << "Time to process a range of " << input_deq.size() << " elements with " << "std::deque" << "  : " << sort_time << " us\n";
}
