#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon_B->getType() << std::endl ;
}
void HumanB::setWeapon(Weapon &Weapon)
{
	this->weapon_B = &Weapon;
}
HumanB::HumanB(std::string name)
{
	this->name = name;
}