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

const char * BitcoinExchange::BadInput::what() const throw()
{
	return "Error: bad input => " ;
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

BitcoinExchange::BitcoinExchange(std::string date, double value)
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
BitcoinExchange::~BitcoinExchange() {

}

bool validate_date(std::string date) {
	int idx;
	int n_idx;
	long y, m, d;
	std::string year, month, day;
	std::stringstream ss;

	idx = date.find('-', 0);
	year = date.substr(0, idx);
	n_idx = date.find('-', idx + 1);
	month = date.substr(idx + 1, n_idx - idx - 1);
	day = date.substr(n_idx + 1);
	ss.str(year);
	ss >> y;
	ss.clear();
	ss.str(month);
	ss >> m;
	ss.clear();
	ss.str(day);
	ss >> d;
	if (y > 9999 || y < 0) return false;
	if (m > 12 || m < 1) return false;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if (d > 31 || d < 1) return false;
	} else {
		if (d > 30 || d < 1) return false;
	}
	return true;
}

void BitcoinExchange::save_data(void) {
	std::ifstream fs("data.csv");
	try {
		if (fs.fail())
			throw BitcoinExchange::FileNotFound();
		std::string line1, line2;
		std::getline(fs, line1, ',');
		std::getline(fs, line2);
		double value;
		if (!((line1 == "date") && (line2 == "exchange_rate")))
			throw BitcoinExchange::InvaildFile();
		while (!fs.eof()) {
			std::getline(fs, line1, ',');
			std::getline(fs, line2);
			std::stringstream ss(line2);
			ss >> value;
			if (!line1.empty() && !line2.empty()) {
				db.insert(std::pair<std::string, double>(line1, value));
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void BitcoinExchange::calculate(std::string input) {
	std::ifstream fs(input);
	try {
		if (fs.fail())
			throw BitcoinExchange::FileNotFound();
		std::string line, date, s_value;
		int target;
		double value;
		double rate;
		bool checked;
		std::getline(fs, line);
		target = line.find('|', 0);
		date = line.substr(0, target);
		s_value = line.substr(target + 1);
		if (!((date == "date ") && (s_value == " value")))
			throw BitcoinExchange::InvaildFile();
		while (!fs.eof()) {
			checked = false;
			std::getline(fs, line);
			target = line.find('|', 0);
			date = line.substr(0, target);
			s_value = line.substr(target + 1);
			date.erase(date.find_last_not_of(" ") + 1);
			s_value.erase(0, s_value.find_first_not_of(" "));
			std::stringstream ss(s_value);
			ss >> value;
			if (!date.empty() && !s_value.empty()) {
				if (value < 0) {
					std::cerr << "Error: not a positive number." << '\n';
					continue;
				}
				else if (value > 2147483647) {
					std::cerr << "Error: too large a number." << '\n';
					continue;
				} else if (!validate_date(date)) {
					std::cerr << "Error: bad input => " + date + "\0" << '\n';
					continue;
				}
				std::map<std::string, double>::iterator iter = db.find(date);
				if (iter != db.end())
					rate = value * iter->second;
				else {
					for (std::map<std::string, double>::iterator it = db.begin(); it != db.end(); it++) {
						if (date.compare(it->first) >= 0) {
							rate = value * it->second;
							checked = true;
							break;
						}
					}
					if (!checked) {
						std::cerr << "Error: bad input => " + date + "\0" << '\n';
						continue;
					}
					if (value > 2147483647) {
						std::cerr << "Error: too large a number." << '\n';
						continue;
					}
				}
				std::cout.precision(2);
				std::cout << date << " => " << value << " = " << rate << '\n';
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
