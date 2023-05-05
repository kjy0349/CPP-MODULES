#include "BitcoinExchange.hpp"
// 1번째, 맵
// 2번째, stack을 이용한 전위표기법을 이용한 사칙연산
// 3번째, 벡터, 리스트

int	main(int argc, char *argv[])
{
	BitcoinExchange b = BitcoinExchange();
	(void)argc;
	try {
		b.save_data();
		b.calculate(argv[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
