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
		virtual ~Form(void);
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

		class ThisIsNotSignedException : public std::exception
		{
			public:
			const char * what(void) const throw();
		};
		virtual void execute(const Bureaucrat& b) const = 0;
		void checkExec(const Bureaucrat& b) const;
		void setName(std::string name);
		void setSigned(bool b);
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
