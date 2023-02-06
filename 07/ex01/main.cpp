#include "iter.hpp"

int main()
{
	int i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	iter(i, 10, print<int>);
	std::cout << std::endl;

	iter(i, 10, power);
	iter(i, 10, print);
	std::cout << std::endl;

	return (0);
}