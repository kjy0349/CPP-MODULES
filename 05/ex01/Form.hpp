#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string name_;
		bool signed_;
		const int signGrade_;
		const int execGrade_;
		
		Form(void);
	public:
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form(void);
		Form(std::string name, int signGrade, int execGrade);
		class GradeTooHighException : public std::exception
		{
			public:
			const char * what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char * what(void) const throw();
		};
		const std::string& getName(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif