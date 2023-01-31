#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name_(name), weapon_(weapon)
{
	std::cout << "HumanA " << name << " created with ";
	std::cout << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << this->name_ << " destroyed" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name_ << " attacks with his " << \
		this->weapon_.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->weapon_ = weapon;
}
