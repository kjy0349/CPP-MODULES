#include "Base.hpp"

int main()
{
	Base * a;
	Base * b;

	srand(time(NULL));
	
	a = generate();
	b = generate();

	identify(a);
	identify(b);

	identify(*a);
	identify(*b);

	delete a;
	delete b;
	return (0);
}
