#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z = newZombie("Alex");
	z->announce();
	randomChump("Bruno");
	delete z;
}
