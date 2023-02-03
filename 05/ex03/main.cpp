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
		Intern b;

		Form* rrf;
		rrf = b.makeForm("robotomy request", "Bender");

		a.signForm(*rrf);

		std::cout << *rrf << std::endl;
		std::cout << std::endl;
		a.executeForm(*rrf);		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
