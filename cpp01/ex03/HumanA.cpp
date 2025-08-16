#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon_A.getType() << std::endl ;
}
HumanA::HumanA(std::string name, Weapon& weapon_A): name(name), weapon_A(weapon_A)
{
    
}
