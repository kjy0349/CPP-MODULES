#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
}

PmergeMe::PmergeMe(const PmergeMe& obj) {
    this->deq = obj.deq;
    this->vtr = obj.vtr;
    this->K = obj.K;
}

PmergeMe::PmergeMe(int K) {
    this->K = K;
}

PmergeMe::~PmergeMe() {

}

PmergeMe &PmergeMe::operator=(const PmergeMe& obj) {
    if(this == &obj) return *this;
	
	this->vtr = obj.vtr;
    this->deq = obj.deq;
    this->K = obj.K;
	return (*this);
}

void insert_vtr(std::vector<int> &vtr, int l, int r) {
    for (int i = l; i < r; i++) {
        int compare = vtr[i + 1];
        int j = i + 1;
        while (j > l && vtr[j - 1] > compare) {
            vtr[j] = vtr[j - 1];
            j--;
        }
        vtr[j] = compare;
    }
}

void merge_vtr(std::vector<int> &vtr, int l, int m, int r) {
    int left_size = m - l + 1;
    int right_size = r - m;
    std::vector<int> left_vec(vtr.begin() + l, vtr.begin() + m + 1);
    std::vector<int> right_vec(vtr.begin() + m + 1, vtr.begin() + r + 1);
    int l_idx = 0, r_idx = 0;
    for (int i = l; i < r + 1; i++) {
        if (r_idx == right_size) {
            vtr[i] = left_vec[l_idx];
            l_idx++;
        } else if (l_idx == left_size) {
            vtr[i] = right_vec[r_idx];
            r_idx++;
        } else if (right_vec[r_idx] > left_vec[l_idx]) {
            vtr[i] = left_vec[l_idx];
            l_idx++;
        } else {
            vtr[i] = right_vec[r_idx];
            r_idx++;
        }
    }
}

void PmergeMe::sort_vector(int l, int r) {
    if (r - l >= this->K) {
        int m = (r - l) / 2 + l;
        sort_vector(l, m);
        sort_vector(m + 1, r);
        merge_vtr(this->vtr, l, m, r);
    } else insert_vtr(this->vtr, l, r);
}

void PmergeMe::sort(std::vector<int> &input_vec) {
    this->vtr = input_vec;
    sort_vector(0, this->vtr.size() - 1);
    input_vec = this->vtr;
}

void insert_deq(std::deque<int> &deq, int l, int r) {
    for (int i = l; i < r; i++) {
        int compare = deq[i + 1];
        int j = i + 1;
        while (j > l && deq[j - 1] > compare) {
            deq[j] = deq[j - 1];
            j--;
        }
        deq[j] = compare;
    }
}

void merge_deq(std::deque<int> &deq, int l, int m, int r) {
    int left_size = m - l + 1;
    int right_size = r - m;
    std::deque<int> left_deq(deq.begin() + l, deq.begin() + m + 1);
    std::deque<int> right_deq(deq.begin() + m + 1, deq.begin() + r + 1);
    int l_idx = 0, r_idx = 0;
    for (int i = l; i < r + 1; i++) {
        if (r_idx == right_size) {
            deq[i] = left_deq[l_idx];
            l_idx++;
        } else if (l_idx == left_size) {
            deq[i] = right_deq[r_idx];
            r_idx++;
        } else if (right_deq[r_idx] > left_deq[l_idx]) {
            deq[i] = left_deq[l_idx];
            l_idx++;
        } else {
            deq[i] = right_deq[r_idx];
            r_idx++;
        }
    }
}

void PmergeMe::sort_deque(int l, int r) {
    if (r - l >= this->K) {
        int m = (r - l) / 2 + l;
        sort_deque(l, m);
        sort_deque(m + 1, r);
        merge_deq(this->deq, l, m, r);
    } else insert_deq(this->deq, l, r);
}

void PmergeMe::sort(std::deque<int> &input_deq)  {
    this->deq = input_deq;
    sort_deque(0, this->deq.size() - 1);
    input_deq = this->deq;
}
