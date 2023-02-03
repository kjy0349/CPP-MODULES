#include "Dog.hpp"

Dog::Dog(void) 
{
	this->type_ = "Dog";
	this->brain_ = new Brain();
	std::cout << "Dog Class Constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) 
{
	this->type_ = obj.type_;
	this->brain_ = new Brain();
	*(this->brain_) = *(obj.brain_);
	std::cout << "Dog Class copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) 
{
	this->type_ = obj.type_;
	*(this->brain_) = *(obj.brain_);
	std::cout << "Dog Class operator= called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain_;
	this->brain_ = NULL;
	std::cout << "Dog Class Destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog say 'Bark Bark!'" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain_);
}