#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>


class ClapTrap {
  protected:
	std::string name_;
	unsigned int hitpoint_;
	unsigned int energypoint_;
	unsigned int attackdamage_;
 public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	virtual ~ClapTrap(void);
	unsigned int getDamege(void) const;
	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif