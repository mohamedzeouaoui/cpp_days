#include "HumanB.hpp"

void HumanB::attack()
{
	if (!weapon_B)
		return ;
    std::cout << name << " attacks with their " << weapon_B->getType() << std::endl ;
}
void HumanB::setWeapon(Weapon &Weapon)
{
	this->weapon_B = &Weapon;
}
HumanB::HumanB(std::string name) : weapon_B(NULL)
{
	this->name = name;
}