# ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <vector>
# include <deque>
# include <sstream>
# include <iostream>

class PmergeMe {
    private:
        std::deque<int> deq;
        std::vector<int> vtr;
        int K;
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& obj);
        PmergeMe(int K);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe& obj);
        void sort_vector(int l, int r);
        void sort_deque(int l, int r) ;
        void sort(std::vector<int> &input_vec);
        void sort(std::deque<int> &input_deq);
};

#endif
