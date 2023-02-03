#include "Cat.hpp"

Cat::Cat(void) 
{
	this->type_ = "Cat";
	std::cout << "Cat Class Constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) 
{
	this->type_ = obj.type_;
	std::cout << "Cat Class copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) 
{
	this->type_ = obj.type_;
	std::cout << "Cat Class operator= called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat Class Destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat say 'meow...'" << std::endl;
}