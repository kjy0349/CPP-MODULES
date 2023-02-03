#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(5);
	b.beRepaired(5);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(10);
	a.beRepaired(10);
	std::cout << std::endl;

	return (0);
}