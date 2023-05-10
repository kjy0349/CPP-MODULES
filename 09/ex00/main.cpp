#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Error: Invaild Input.\n";
		return -1;
	}
	BitcoinExchange b = BitcoinExchange();
	try {
		b.save_data();
		b.calculate(argv[1]);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}
