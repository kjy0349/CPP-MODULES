#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) 
{
	this->hitpoint_ = 100;
	this->energypoint_ = 50;
	this->attackdamage_ = 20;

	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name_ = name;
	this->hitpoint_ = 100;
	this->energypoint_ = 50;
	this->attackdamage_ = 20;
	
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) 
{
	this->name_ = obj.name_;
	this->attackdamage_ = obj.attackdamage_;
	this->hitpoint_ = obj.hitpoint_;
	this->energypoint_ = obj.energypoint_;
	std::cout << "ScavTrap " << name_ << " copy constructor called" << std::endl;

}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) 
{
	this->name_ = obj.name_;
	this->attackdamage_ = obj.attackdamage_;
	this->hitpoint_ = obj.hitpoint_;
	this->energypoint_ = obj.energypoint_;
	std::cout << "ScavTrap operator = " << name_ << " called" << std::endl;
	return (*this);

}

ScavTrap::~ScavTrap(void) 
{
	std::cout << "ScavTrap " << this->name_ << " destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (!this->hitpoint_ || !this->energypoint_)
	{
		std::cout << "ScavTrap " << this->name_ << " can not move..." << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->name_ << " has entered gate guard mode" << std::endl;
		this->energypoint_--;
	}
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->hitpoint_ || !this->energypoint_)
	{
		std::cout << "ScavTrap " << this->name_ << " can not move..." << std::endl;
	}
	else
	{
		std::cout	<< "ScavTrap " << this->name_ << " attacks " << target 
					<< ", causing " << this->attackdamage_ << " points of damage!"
					<< std::endl;
		this->energypoint_--;
	}
}