#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name_v): name(name_v) , Hit_points(10) , Energy_points(10), Attack_damage(0)
{
    std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (Hit_points <= 0) {
        std::cout << "ClapTrap " << name << " is dead and cannot attack!" << std::endl;
    } else if (Energy_points <= 0) {
        std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
    } else {
        Energy_points--;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << Attack_damage << " points of damage!" << std::endl;
    }

}
void ClapTrap::takeDamage(unsigned int amount)
{
    this->Hit_points -= amount;
    if (this->Hit_points < 0)
        this->Hit_points = 0;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage. "
              << "Remaining hit points: " << this->Hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->Hit_points <= 0) {
        std::cout << "ClapTrap " << this->name << " is out of hit points and cannot be repaired." << std::endl;
    } else if (this->Energy_points <= 0) {
        std::cout << "ClapTrap " << this->name << " has no energy left to repair." << std::endl;
    } else {
        --this->Energy_points;
        this->Hit_points += amount;
        std::cout << "ClapTrap " << this->name << " repairs itself, recovering "
                  << amount << " hit points. Total hit points: " << this->Hit_points << std::endl;
    }
}