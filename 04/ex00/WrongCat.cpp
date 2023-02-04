#include "WrongCat.hpp"

WrongCat::WrongCat(void) 
{
	this->type_ = "WrongCat";
	std::cout << "WrongCat Class Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) 
{
	this->type_ = obj.type_;
	std::cout << "WrongCat Class copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) 
{
	this->type_ = obj.type_;
	std::cout << "WrongCat Class operator= called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Class Destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat say 'meow...'" << std::endl;
}
