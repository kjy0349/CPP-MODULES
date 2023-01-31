#include "Zombie.hpp"

int	main(void)
{
	int	size;

	size = 5;
	Zombie *horde = zombieHorde(size, "zombiename");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}
