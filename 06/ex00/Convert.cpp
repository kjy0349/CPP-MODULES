#include "Convert.hpp"

Convert::Convert(void)
{
    this->input_ = "(null)";
    this->v_char_ = 0;
    this->v_float_ = 0;
    this->v_int_ = 0;
    this->v_double_ = 0;
    this->err_ = false;
}

Convert::Convert(const Convert& obj)
{
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

Convert(std::string str)
{

}
void setValue(std::string s)
{

}
char getChar(void) const
{

}
int getInt(void) const
{

}
float getFloat(void) const
{

}
double getDouble(void) const
{

}
bool getErr(void) const
{

}
char printChar(void) const
{

}
int printInt(void) const
{

}
float printFloat(void) const
{

}
double printDouble(void) const
{

}