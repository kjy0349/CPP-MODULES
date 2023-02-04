#include "Animal.hpp"

Animal::Animal(void) 
{
	this->type_ = "Animal";
	std::cout << "Animal Class Constructor called" << std::endl;
}

Animal::Animal(const Animal& obj) 
{
	this->type_ = obj.type_;
	std::cout << "Animal Class copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& obj) 
{
	this->type_ = obj.type_;
	std::cout << "Animal Class operator= called" << std::endl;
	return (*this);
}

Animal::~Animal(void) 
{
	std::cout << "Animal Class Destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
	return (type_);
}
