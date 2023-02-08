#include "iter.hpp"

int main()
{
	int i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	double j[10] = {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1};

	iter(i, 10, print<int>);
	std::cout << std::endl;
	iter(j, 10, print<double>);
	std::cout << std::endl;

	iter(i, 10, power<int>);
	iter(i, 10, print<int>);
	std::cout << std::endl;

	iter(j, 10, power<double>);
	iter(j, 10, print<double>);
	std::cout << std::endl;

	return (0);
}