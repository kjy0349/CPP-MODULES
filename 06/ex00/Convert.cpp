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
	setValue(str);
}

void Convert::setValue(std::string str)
{
	std::string::size_type n;
	std::string::size_type f;

	// try to alloc str to member variable input_
	try 
	{
		this->input_ = str;
	}
	// if str is too long, exception gonna be happend
	catch(const std::bad_alloc& e)
	{
		this->err_ = true;
		return ;
	}

	// if str contains '.' and not contains f, it's double 
	n = str.find('.');
	f = str.find('f', str.length() - 1);
	if (input_ == "nan" || input_ == "inf" || input_ == "+inf" || \
	input_ == "-inf" || input_ == "nanf"|| input_ == "inff" || input_ == "+inff" || input_ == "-inff")
	{
		// nan -> nothing. sign bit = 0, all exponent = 1
		if (input_ == "nan" || input_ == "nanf")
		{
			v_double_ = 0.0/0.0;
		}
		else
		{	
			// inf's all exponent = 0
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
		v_int_ = atoi(str.c_str());
		std::stringstream stream;
		stream << v_int_;
		if (stream.str() != input_)
		{
			if (v_int_ > 0 && f == str.length() - 1)
			{
				v_char_ = static_cast<char>(v_int_);
				v_float_ = static_cast<float>(v_int_);
				v_double_ = static_cast<double>(v_int_);
			}
			else
			{
				err_ = true;
			}
		}
		else
		{
			v_char_ = static_cast<char>(v_int_);
			v_float_ = static_cast<float>(v_int_);
			v_double_ = static_cast<double>(v_int_);
		}
	}
	else
	{
		const char *temp = str.c_str();
		char *end = NULL;

		v_double_ = strtod(temp, &end);
		if ((*end && !(*end == 'f' && end == &temp[str.length() - 1])))
		{
			err_ = true;
		}
		else
		{
			v_int_ = static_cast<int>(v_double_);
			v_char_ = static_cast<char>(v_double_);
			v_float_ = static_cast<float>(v_double_);
		}
	}
}

char Convert::printChar(void) const
{
	std::stringstream stream;

	stream << v_int_;
	if (err_ || std::isnan(v_double_) || std::isinf(v_double_))
		throw std::runtime_error("impossible");
	else if (v_int_ >= 32 && v_int_ <= 126)
		return (v_char_);
	else if (v_int_ < 32 && v_int_ >= 0)
		throw std::runtime_error("Non displayable");
	else
		throw std::runtime_error("impossible");
}

int Convert::printInt(void) const
{
	std::stringstream stream;

	stream << v_int_;
	if (err_ || std::isnan(v_double_) || std::isinf(v_double_))
		throw std::runtime_error("impossible");
	return (v_int_);
}

float Convert::printFloat(void) const
{
	if (err_)
		throw std::runtime_error("impossible");
	if (std::isnan(v_double_))
		throw std::runtime_error("nanf");
	if (std::isinf(v_double_) && v_double_ > 0)
		throw std::runtime_error("inff");
	else if (std::isinf(v_double_) && v_double_ < 0)
		throw std::runtime_error("-inff");
	return (v_float_);
}

double Convert::printDouble(void) const
{
	if (err_)
		throw std::runtime_error("impossible");
	if (std::isnan(v_double_))
		throw std::runtime_error("nan");
	if (std::isinf(v_double_) && v_double_ > 0)
		throw std::runtime_error("inf");
	else if (std::isinf(v_double_) && v_double_ < 0)
		throw std::runtime_error("-inf");
	return (v_double_);	
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

std::ostream& operator<<(std::ostream &out, const Convert &b)
{
	std::stringstream ss;
	ss << b.getInt();

	try
	{
		out << "char: " << b.printChar() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		out << "int: " << b.printInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		if (static_cast<float>(b.getInt()) == b.getFloat())
		{
			out << "float: " << std::setprecision(6) << b.printFloat() << ".0f" << std::endl;
		}
		else
		{
			out << "float: " << std::setprecision(6) << b.printFloat() << "f" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		if (static_cast<double>(b.getInt()) == b.getDouble())
		{
			out << "double: " << std::setprecision(16) << b.printDouble() << ".0" << std::endl;
		}
		else
		{
			out << "double: " << b.printDouble() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (out);
}
