#include "easyfind.hpp"

int main()
{
    std::vector<int> vector;
    std::list<int> list;
    std::deque<int> queue;
    std::deque<int> const &temp = queue;
    const std::deque<int> &temp1 = queue;
    const int a = 3;

    for (int i = 0; i < 10; i++)
    {
        vector.push_back(i);
        list.push_back(i);
        queue.push_back(i);
    }

    std::cout << *(easyfind(vector, 5)) << std::endl;
    std::cout << *(easyfind(list, 5)) << std::endl;
    std::cout << *(easyfind(queue, 5)) << std::endl;

    std::cout << *(easyfind(vector, a)) << std::endl;
    std::cout << *(easyfind(list, a)) << std::endl;
    std::cout << *(easyfind(queue, a)) << std::endl;

    std::cout << *(easyfind(temp, a)) << std::endl;
    std::cout << *(easyfind(temp1, a)) << std::endl;
    std::cout << *(easyfind(temp, 6)) << std::endl;
    std::cout << *(easyfind(temp1, 6)) << std::endl;
}
