#include "Convert.hpp"

int main(int ac, char **av)
{
	Convert c;

	if (ac != 2)
	{
		std::cout << "argument count is not 2" << std::endl;
		return (1);
	}	
	c.setValue(av[1]);
	std::cout << c << std::endl;
	return (0);
}
