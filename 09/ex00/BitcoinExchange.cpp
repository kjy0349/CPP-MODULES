#include "BitcoinExchange.hpp"

const char * BitcoinExchange::InvaildFile::what(void) const throw()
{
	return "Error: Invaild file..";
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if(this == &obj) return *this;

	this->db = obj.db;
	return (*this);
}

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	this->db = obj.db;
}

BitcoinExchange::~BitcoinExchange() 
{
}

bool validate_date(std::string date) {
	size_t idx, n_idx;
	int y, m, d;
	std::string year, month, day;
	std::stringstream ss;

	idx = date.find('-', 0);
	if (idx == std::string::npos)
		return false;
	year = date.substr(0, idx);
	n_idx = date.find('-', idx + 1);
	if (idx == std::string::npos)
		return false;
	month = date.substr(idx + 1, n_idx - idx - 1);
	day = date.substr(n_idx + 1);
	ss.str(year);
	ss >> y;
	if (ss.fail())
		return false;
	ss.clear();
	ss.str(month);
	ss >> m;
	if (ss.fail())
		return false;
	ss.clear();
	ss.str(day);
	ss >> d;
	if (ss.fail())
		return false;
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
	if (fs.fail()) {
		fs.close();
		throw BitcoinExchange::InvaildFile();
	}
	std::string line1, line2;
	std::getline(fs, line1, ',');
	std::getline(fs, line2);
	float value;
	if (!((line1 == "date") && (line2 == "exchange_rate"))) {
		fs.close();
		throw BitcoinExchange::InvaildFile();
	}
	while (std::getline(fs, line1, ',')) {
		std::getline(fs, line2);
		std::stringstream ss(line2);
		ss >> value;
		if (ss.fail() || value < 0 || value > 2147483647 || !validate_date(line1))
			throw BitcoinExchange::InvaildFile();
		if (!line1.empty() && !line2.empty()) {
			db.insert(std::pair<std::string, float>(line1, value));
		}
	}
	fs.close();
}

void BitcoinExchange::calculate(std::string input) {
	std::ifstream fs(input);
	if (fs.fail()) {
		fs.close();
		throw BitcoinExchange::InvaildFile();
	}
	std::string line, date, s_value;
	size_t target;
	float value;
	float rate;
	bool checked;
	std::getline(fs, line);
	target = line.find('|', 0);
	if (target == std::string::npos)
		throw BitcoinExchange::InvaildFile();
	date = line.substr(0, target);
	s_value = line.substr(target + 1);
	if (!((date == "date ") && (s_value == " value"))) {
		fs.close();
		throw BitcoinExchange::InvaildFile();
	}
	while (std::getline(fs, line)) {
		checked = false;
		target = line.find('|', 0);
		if (target == std::string::npos) {
			std::cout << "Error: bad input => " << line << '\n';
			continue;
		}
		date = line.substr(0, target);
		s_value = line.substr(target + 1);
		date.erase(date.find_last_not_of(" ") + 1);
		s_value.erase(0, s_value.find_first_not_of(" "));
		std::stringstream ss(s_value);
		ss >> value;
		if (!date.empty() && !s_value.empty()) {
			if (value < 0) {
				std::cout << "Error: not a positive number.\n";
				continue;
			}
			else if (value > 1000) {
				std::cout << "Error: too large a number.\n";
				continue;
			} else if (!validate_date(date)) {
				std::cout << "Error: bad input => " << date << '\n';
				continue;
			} else if (ss.fail()) {
				std::cout << "Error: Invaild input.\n";
				continue;
			}
			std::map<std::string, float>::iterator iter = db.find(date);
			if (iter != db.end())
				rate = (float)value * iter->second;
			else {
				for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); it++) {
					if (date.compare(it->first) >= 0) {
						rate = (float)value * it->second;
						checked = true;
						break;
					}
				}
				if (!checked) {
					std::cout << "Error: bad input => " + date << '\n';
					continue;
				}
				if (value > 2147483647) {
					std::cout << "Error: too large a number.\n";
					continue;
				}
			}
			std::cout << date << " => " << value << " = " << rate << std::endl;
		} else std::cout << "Error: Invaild Input.\n";
	}
	fs.close();
}
