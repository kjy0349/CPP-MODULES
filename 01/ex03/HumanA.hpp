#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	name_;
		Weapon		&weapon_;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	attack(void);
		void	setWeapon(Weapon weapon);
};
