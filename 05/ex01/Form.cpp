#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const Form& obj) : name_(obj.getName()), signed_(obj.getSigned()), signGrade_(obj.getSignGrade()), execGrade_(obj.getExecGrade())
{
}

Form& Form::operator=(const Form& obj)
{
	if(this == &obj) return *this;
	
	const_cast<std::string &>(this->name_) = obj.getName();
	const_cast<int &>(this->signGrade_) = obj.getSignGrade();
	const_cast<int &>(this->execGrade_) = obj.getExecGrade();
	this->signed_ = obj.signed_;
	return (*this);
}

Form::~Form(void)
{
}

Form::Form(std::string name, int signGrade, int execGrade) : name_(name), signed_(false), signGrade_(signGrade), execGrade_(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
	{
		throw GradeTooHighException();
	}
	else if (signGrade < 1 || execGrade < 1)
	{
		throw GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what(void) const throw() 
{
	return "Grade too high...";
}

const char *Form::GradeTooLowException::what(void) const throw() 
{
	return "Grade too low...";
}

const std::string& Form::getName(void) const
{
	return (this->name_);
}

bool Form::getSigned(void) const
{
	return (this->signed_);
}

int Form::getSignGrade(void) const
{
	return (this->signGrade_);
}

int Form::getExecGrade(void) const
{
	return (this->execGrade_);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (this->signGrade_ >= b.getGrade())
	{
		signed_ = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << f.getName() 
		<< std::boolalpha <<", signed : " << f.getSigned()
		<< ", signGrade : " << f.getSignGrade()
		<< ", execGrade : " << f.getExecGrade();
	return (out);
}
