#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat a("a", 1);
		Bureaucrat c("c", 150);
		Intern b;

		AForm* rrf;
		rrf = b.makeForm("shrubbery creation", "Bender");

		a.signForm(*rrf);

		std::cout << *rrf << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		a.executeForm(*rrf);
		c.executeForm(*rrf);

		rrf = b.makeForm("asd", "Check");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
