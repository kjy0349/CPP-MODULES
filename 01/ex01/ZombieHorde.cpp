#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *hords = new Zombie[N];
	for (int i = 0; i < N; i++)
		hords[i].setName(name);
	return (hords);
}
