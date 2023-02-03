#include "ClapTrap.hpp"

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a("A");
	ScavTrap b("B");

	std::cout << std::endl;
	
	a.attack("B");
	b.takeDamage(a.getDamege());
	b.beRepaired(3);
	std::cout << std::endl;

	b.attack("A");
	a.takeDamage(b.getDamege());
	a.beRepaired(10);
	std::cout << std::endl;

	a.guardGate();
	std::cout << std::endl;

	return (0);
}
