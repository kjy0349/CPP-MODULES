#include "Bureaucrat.hpp"
#include "Form.hpp"

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade too high...";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low...";
}

Bureaucrat::Bureaucrat(void) : name_("Default")
{
	this->grade_ = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name_(obj.getName())
{
	this->grade_ = obj.getGrade();
	if (grade_ < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade_ > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if(this == &obj) return *this;
	
	const_cast<std::string&>(this->name_) = obj.getName();
	this->grade_ = obj.getGrade();
	if (grade_ < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade_ > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name)
{
	this->grade_ = grade;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

void Bureaucrat::incrementGrade(void)
{
	int checker = this->grade_ - 1;

	if (checker < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade_ = checker;
}

void Bureaucrat::decrementGrade(void)
{
	int checker = this->grade_ + 1;

	if (checker > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade_ = checker;
}

std::string Bureaucrat::getName() const
{
	return (this->name_);
}

int Bureaucrat::getGrade() const
{
	return (this->grade_);
}

void Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name_ << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name_ << " couldn't sign " << f.getName() << " because "<< e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
