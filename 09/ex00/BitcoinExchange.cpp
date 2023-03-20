#include "BitcoinExchange.hpp"

const char * BitcoinExchange::FileNotFound::what(void) const throw()
{
	return "Error: File not found..";
}

const char * BitcoinExchange::InvaildFile::what(void) const throw()
{
	return "Error: Invaild file..";
}

const char * BitcoinExchange::NotPositiveValue::what(void) const throw()
{
	return "Error: not a positive number.";
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if(this == &obj) return *this;
	
	this->date_ = obj.date_;
	this->value_ = obj.value_;
	this->type_ = obj.type_;
	return (*this);
}

BitcoinExchange::BitcoinExchange(void)
{
	this->date_ = "";
	this->type_ = "";
	this->value_ = 0.0f;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	this->date_ = obj.date_;
	this->value_ = obj.value_;
	this->type_ = obj.type_;
}

BitcoinExchange::BitcoinExchange(std::string date, float value)
{
	this->date_ = date;
	this->value_ = value;
	this->type_ = typeid(value).name();
}

BitcoinExchange::BitcoinExchange(std::string date, int value)
{
	this->date_ = date;
	this->value_ = value;
	this->type_ = typeid(value).name();
}
