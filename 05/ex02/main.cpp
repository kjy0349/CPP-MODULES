#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat a("a", 150);
	Bureaucrat b("b", 1);
	ShrubberyCreationForm c("cde");
	RobotomyRequestForm d("d");
	PresidentialPardonForm e("e");

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << std::endl;

	a.signForm(c);
	a.signForm(d);
	a.signForm(e);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << std::endl;

	b.signForm(c);
	b.signForm(d);
	b.signForm(e);	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << std::endl;

	a.executeForm(c);
	b.executeForm(c);
	std::cout << std::endl;
	a.executeForm(d);
	b.executeForm(d);
	std::cout << std::endl;
	a.executeForm(e);
	b.executeForm(e);
	return (0);
}
