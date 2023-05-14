#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <map>
# include <sstream>
# include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float, std::greater<std::string> > db;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		BitcoinExchange(std::string date, double value);
		BitcoinExchange(std::string date, int value);
		void save_data(void);
		void calculate(std::string input);
		class InvaildFile : public std::exception
		{
			public:
				const char * what(void) const throw();
		};
};

#endif
