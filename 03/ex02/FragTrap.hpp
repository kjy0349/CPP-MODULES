#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
 public:
	FragTrap(void);
	FragTrap(const FragTrap& obj);
	FragTrap& operator=(const FragTrap& obj);
	~FragTrap(void);
	FragTrap(std::string name);
	void highFivesGuys(void);
};

#endif