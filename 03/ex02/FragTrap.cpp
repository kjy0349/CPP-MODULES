#include "FragTrap.hpp"

FragTrap::FragTrap(void) 
{
	this->name_ = "default";
	this->attackdamage_ = 30;
	this->hitpoint_ = 100;
	this->energypoint_ = 100;
	
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) 
{
	this->name_ = obj.name_;
	this->attackdamage_ = obj.attackdamage_;
	this->hitpoint_ = obj.hitpoint_;
	this->energypoint_ = obj.energypoint_;
	std::cout << "FragTrap " << name_ << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) 
{
	this->name_ = obj.name_;
	this->attackdamage_ = obj.attackdamage_;
	this->hitpoint_ = obj.hitpoint_;
	this->energypoint_ = obj.energypoint_;
	std::cout << "FragTrap operator = " << name_ << " called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void) 
{
	std::cout << "FragTrap " << this->name_ << " destructor called" << std::endl;

}

FragTrap::FragTrap(std::string name)
{
	this->name_ = name;
	this->attackdamage_ = 30;
	this->hitpoint_ = 100;
	this->energypoint_ = 100;
	
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (!this->hitpoint_) 
	{
		std::cout << "FragTrap " << this->name_ << " can not move..." << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->name_ << " high five!\n";
	}
}