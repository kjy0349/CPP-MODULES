#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm(void);
		
	public:
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		void execute(const Bureaucrat& b) const;
		AForm* clone(std::string name) const;
};

#endif
