#include "Convert.hpp"

Convert::Convert(void)
{
    this->v_char_ = 0;
    this->v_float_ = 0;
    this->v_int_ = 0;
    this->v_double_ = 0;
    this->err_ = false;
	this->input_ = "(null)";
}

Convert::Convert(const Convert& obj)
{
	this->input_ = obj.getInput();
    this->v_char_ = obj.getChar();
	this->v_int_ = obj.getInt();
	this->v_float_ = obj.getFloat();
	this->v_double_ = obj.getDouble();
	this->err_ = obj.getErr();
}

Convert& Convert::operator=(const Convert& obj)
{
    this->v_char_ = obj.getChar();
	this->v_int_ = obj.getInt();
	this->v_float_ = obj.getFloat();
	this->v_double_ = obj.getDouble();
	this->err_ = obj.getErr();
	return (*this);
}

Convert::~Convert(void)
{
}


Convert::Convert(std::string str)
{
    this->v_char_ = 0;
    this->v_float_ = 0;
    this->v_int_ = 0;
    this->v_double_ = 0;
	this->err_ = false;
	this->input_ = str;
}

void Convert::setValue(std::string str)
{
	std::string::size_type n;
	std::string::size_type f;

	try 
	{
		this->input_ = str;
	}
	catch(const std::bad_alloc& e)
	{
		this->err_ = true;
		return ;
	}

	n = str.find('.');
	f = str.find('f', str.length() - 1);
	if (input_ == "nan" || input_ == "inf" || input_ == "+inf" || \
	input_ == "-inf" || input_ == "nanf"|| input_ == "inff" || input_ == "+inff" || input_ == "-inff")
	{
		if (input_ == "nan" || input_ == "nanf")
		{
			v_double_ = 0.0/0.0;
		}
		else
		{
			if (str[0] == '-')
			{
				v_double_ = -1.0/0.0;
			}
			else
			{
				v_double_ = 1.0/0.0;
			}
		}
	}
	else if (str.length() == 1 && !std::isdigit(static_cast<char>(str[0])))
	{
		v_char_ = static_cast<char>(str[0]);
		v_int_ = static_cast<int>(str[0]);
		v_float_ = static_cast<float>(str[0]);
		v_double_ = static_cast<double>(str[0]);
	}
	else if (n == std::string::npos)
	{
		v_int_ = atoi()
	}
}

std::string Convert::getInput(void) const
{
	return (this->input_);
}

char Convert::getChar(void) const
{
	return (this->v_char_);
}

int Convert::getInt(void) const
{
	return (this->v_int_);
}

float Convert::getFloat(void) const
{
	return (this->v_float_);
}

double Convert::getDouble(void) const
{
	return (this->v_double_);
}

bool Convert::getErr(void) const
{
	return (this->err_);
}
