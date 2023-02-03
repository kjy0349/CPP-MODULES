#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
 private:
	PresidentialPardonForm(void);
	
 public:
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
	~PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	void execute(const Bureaucrat& b) const;
};
#endif
