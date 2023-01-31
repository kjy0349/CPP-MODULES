#include "Contact.hpp"

std::string	Contact::get_fname(void) const
{
	return (this->fname_);
}

std::string	Contact::get_lname(void) const
{
	return (this->lname_);
}

std::string	Contact::get_nick(void) const
{
	return (this->nick_);
}

std::string	Contact::get_pnum(void) const
{
	return (this->pnum_);
}

std::string	Contact::get_secret(void) const
{
	return (this->secret_);
}

void	Contact::set_fname(std::string str)
{
	this->fname_ = str;
}

void	Contact::set_lname(std::string str)
{
	this->lname_ = str;
}

void	Contact::set_nick(std::string str)
{
	this->nick_ = str;
}

void	Contact::set_pnum(std::string str)
{
	this->pnum_ = str;
}

void	Contact::set_secret(std::string str)
{
	this->secret_ = str;
}
