#ifndef WrongCat_HPP
# define WrongCat_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
 public:
	WrongCat(void);
	WrongCat(const WrongCat& obj);
	WrongCat& operator=(const WrongCat& obj);
	~WrongCat(void);
	void makeSound(void) const;
};

#endif