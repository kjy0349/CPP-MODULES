#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : Form(obj)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if(this == &obj) return *this;
	this->setSigned(obj.getSigned());
	this->setName(obj.getName());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5)
{
}

void PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	checkExec(b);
	
	std::cout << this->getName() << " was pardoned by President Zaphod Beeblebrox.." << std::endl;
}
