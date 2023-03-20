#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <typeinfo>

class BitcoinExchange
{
	private:
		std::string	date_;
		std::string type_;
		float value_;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		BitcoinExchange(std::string date, float value);
		BitcoinExchange(std::string date, int value);
		class FileNotFound : public std::exception
		{
			public:
				const char * what(void) const throw();
		};
		class InvaildFile : public std::exception
		{
			public:
				const char * what(void) const throw();
		};
		class NotPositiveValue : public std::exception
		{
			public:
				const char * what(void) const throw();
		};
};

#endif
