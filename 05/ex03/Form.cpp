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

const char *Form::ThisIsNotSignedException::what(void) const throw() 
{
	return "this is not signed, can not do this...";
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

void Form::checkExec(const Bureaucrat& b) const
{
	if (this->signed_ == false)
	{
		throw ThisIsNotSignedException();
	}
	else if (b.getGrade() > execGrade_)
	{
		throw GradeTooLowException();
	}	
}

void Form::setName(std::string name)
{
	const_cast<std::string&>(this->name_) = name;
}

void Form::setSigned(bool b)
{
	this->signed_ = b;
}


std::ostream& operator<<(std::ostream& out, const Form& f)
{
	out << f.getName() 
		<< std::boolalpha <<", signed : " << f.getSigned()
		<< ", signGrade_ : " << f.getSignGrade()
		<< ", execGrade : " << f.getExecGrade();
	return (out);
}

