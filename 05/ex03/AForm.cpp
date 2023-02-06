#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const AForm& obj) : name_(obj.getName()), signed_(obj.getSigned()), signGrade_(obj.getSignGrade()), execGrade_(obj.getExecGrade())
{
}

AForm& AForm::operator=(const AForm& obj)
{
	if(this == &obj) return *this;
	const_cast<std::string &>(this->name_) = obj.getName();
	const_cast<int &>(this->signGrade_) = obj.getSignGrade();
	const_cast<int &>(this->execGrade_) = obj.getExecGrade();
	this->signed_ = obj.signed_;
	return (*this);
}

AForm::~AForm(void)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade) : name_(name), signed_(false), signGrade_(signGrade), execGrade_(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
	{
		throw GradeTooLowException();
	}
	else if (signGrade < 1 || execGrade < 1)
	{
		throw GradeTooHighException();
	}
}

const char *AForm::GradeTooHighException::what(void) const throw() 
{
	return "Grade too high...";
}

const char *AForm::GradeTooLowException::what(void) const throw() 
{
	return "Grade too low...";
}

const char *AForm::ThisIsNotSignedException::what(void) const throw() 
{
	return "this is not signed, can not do this...";
}

const std::string& AForm::getName(void) const
{
	return (this->name_);
}

bool AForm::getSigned(void) const
{
	return (this->signed_);
}

int AForm::getSignGrade(void) const
{
	return (this->signGrade_);
}

int AForm::getExecGrade(void) const
{
	return (this->execGrade_);
}

void AForm::beSigned(const Bureaucrat& b)
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

void AForm::checkExec(const Bureaucrat& b) const
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

void AForm::setName(std::string name)
{
	const_cast<std::string&>(this->name_) = name;
}

void AForm::setSigned(bool b)
{
	this->signed_ = b;
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << f.getName() 
		<< std::boolalpha <<", signed : " << f.getSigned()
		<< ", signGrade_ : " << f.getSignGrade()
		<< ", execGrade : " << f.getExecGrade();
	return (out);
}
