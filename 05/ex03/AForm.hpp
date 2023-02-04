#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string name_;
		bool signed_;
		const int signGrade_;
		const int execGrade_;
		
		AForm(void);
	public:
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm(void);
		AForm(std::string name, int signGrade, int execGrade);
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
		class ThisIsNotSignedException : public std::exception
		{
			public:
			const char * what(void) const throw();
		};
		const std::string& getName(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(const Bureaucrat& b);

		virtual void execute(const Bureaucrat& b) const = 0;
		void checkExec(const Bureaucrat& b) const;
		void setName(std::string name);
		void setSigned(bool b);

		virtual AForm* clone(std::string name) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
