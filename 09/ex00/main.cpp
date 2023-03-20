#include "BitcoinExchange.hpp"
// 1번째, 맵
// 2번째, stack을 이용한 전위표기법을 이용한 사칙연산
// 3번째, 벡터, 리스트

int	main(int argc, char *argv[])
{
	std::ifstream fs("data.csv");
	try {
		if (fs.fail())
			throw BitcoinExchange::FileNotFound();
		std::map<std::string, float> map;
		std::string line1, line2;
		std::getline(fs, line1, ',');
		std::getline(fs, line2);
		if (!((line1 == "date") && (line2 == "exchange_rate")))
			throw BitcoinExchange::InvaildFile();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
