#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name_;
		Weapon		*weapon_;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};
