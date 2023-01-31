#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon_(NULL)
{
	this->name_ = name;
	std::cout << "HumanB " << name << " created with no weapon" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB " << this->name_ << " destroyed" << std::endl;
}

void	HumanB::attack(void)
{
	
	std::cout << this->name_ << " attacks with his " << \
		(this->weapon_ ? this->weapon_->getType() : "hand" ) << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon_ = &weapon;
}
