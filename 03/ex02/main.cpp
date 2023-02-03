#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a("A");
	FragTrap b("B");

	std::cout << std::endl;
	
	a.attack("B");
	b.takeDamage(a.getDamege());
	b.beRepaired(3);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(b.getDamege());
	a.beRepaired(10);
	std::cout << std::endl;

	a.highFivesGuys();
    b.highFivesGuys();
	std::cout << std::endl;

	return (0);
}