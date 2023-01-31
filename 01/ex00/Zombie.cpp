#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name_ = name;
	std::cout << "Zombie " << this->name_ << " created." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->name_ << " destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}
