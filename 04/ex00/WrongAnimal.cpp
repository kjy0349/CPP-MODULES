#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) 
{
	this->type_ = "WrongAnimal";
	std::cout << "WrongAnimal Class Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) 
{
	this->type_ = obj.type_;
	std::cout << "WrongAnimal Class copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) 
{
	this->type_ = obj.type_;
	std::cout << "WrongAnimal Class operator= called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) 
{
	std::cout << "WrongAnimal Class Destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal say nothing, this message is something wrong" << std::endl;
}
std::string WrongAnimal::getType(void) const
{
	return (type_);
}
