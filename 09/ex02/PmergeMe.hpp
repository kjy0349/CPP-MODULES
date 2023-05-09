# ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <sstream>

class PmergeMe {
    private:
        std::list<int> lst;
        std::vector<int> vtr;
        int K;
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& obj);
        PmergeMe(int K);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe& obj);
        // void sort_list(int l, int r);
        void sort_vector(int l, int r);
        void sort(std::vector<int> &input_vec);
};

#endif
