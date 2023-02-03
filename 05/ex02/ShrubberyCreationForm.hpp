#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
 private:
	ShrubberyCreationForm(void);

 public:
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	void execute(const Bureaucrat& b) const;
};

#endif
