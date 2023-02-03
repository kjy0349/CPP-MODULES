#include "Dog.hpp"

Dog::Dog(void)
{
	this->type_ = "Dog";
	std::cout << "Dog Class Constructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
	this->type_ = obj.type_;
	std::cout << "Dog Class copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) 
{
	this->type_ = obj.type_;
	std::cout << "Dog Class operator= called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog Class Destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog say 'Bark Bark!'" << std::endl;
}
