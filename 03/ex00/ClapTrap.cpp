#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) 
{
	this->name_ = "default";
	this->attackdamage_ = 0;
	this->hitpoint_ = 10;
	this->energypoint_ = 10;
	
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
{
	this->name_ = name;
	this->attackdamage_ = 0;
	this->hitpoint_ = 10;
	this->energypoint_ = 10;
	
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) 
{
	this->name_ = obj.name_;
	this->attackdamage_ = obj.attackdamage_;
	this->hitpoint_ = obj.hitpoint_;
	this->energypoint_ = obj.energypoint_;
	std::cout << "ClapTrap " << name_ << " copy constructor called" << std::endl;

}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) 
{
	this->name_ = obj.name_;
	this->attackdamage_ = obj.attackdamage_;
	this->hitpoint_ = obj.hitpoint_;
	this->energypoint_ = obj.energypoint_;
	std::cout << "ClapTrap operator = " << name_ << " called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void) 
{
	std::cout << "ClapTrap " << this->name_ << " destructor called" << std::endl;
}

unsigned int ClapTrap::getDamege(void) const
{
	return (this->attackdamage_);
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->hitpoint_ || !this->energypoint_)
	{
		std::cout << "ClapTrap " << this->name_ << " can not move..." << std::endl;
	}
	else
	{
		std::cout	<< "ClapTrap " << this->name_ << " attacks " << target 
					<< ", causing " << this->attackdamage_ << " points of damage!"
					<< std::endl;
		this->energypoint_--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hitpoint_)
		this->hitpoint_ = 0;
	else
		this->hitpoint_ -= amount;
	std::cout	<< "ClapTrap " << this->name_ << " has taken " 
				<< amount << " damage..." << std::endl;
	if (!this->hitpoint_)
	{
		std::cout	<< "ClapTrap " << this->name_ << " is died" << std::endl; 
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitpoint_ || !this->energypoint_)
	{
		std::cout << "ClapTrap " << this->name_ << " can not move..." << std::endl;
	}
	else
	{
		this->hitpoint_ += amount;
		this->energypoint_--;
		std::cout	<< "ClapTrap " << this->name_ << " has been repaired of " 
					<< amount << " Hit points. It has now " << this->hitpoint_ 
					<< " Hit points" << std::endl;
	}
}