#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm(void);
		
	public:
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		void execute(const Bureaucrat& b) const;
		Form* clone(std::string name) const;
};

#endif

