#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if(this == &obj) return *this;
	this->setSigned(obj.getSigned());
	this->setName(obj.getName());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
}

void RobotomyRequestForm::execute(const Bureaucrat& b) const
{
	checkExec(b);
	srand(time(NULL));
	int tmp = (rand() % 2); 

	std::cout << "drill say : drrrrrrrrrrrr...!" << std::endl;

	if (tmp)
	{
		std::cout << "wow! " << this->getName() << " succeeded in becoming a robot" << std::endl;
	}
	else
	{
		std::cout << "sorry... " << this->getName() << " failed to becoming a robot" << std::endl;
	}
}

AForm* RobotomyRequestForm::clone(std::string name) const
{
	return (new RobotomyRequestForm(name));
}
