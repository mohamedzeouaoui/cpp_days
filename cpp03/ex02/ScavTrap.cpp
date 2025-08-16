#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name_v) : ClapTrap(name_v)
{
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap " << name_v << " constructed.\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (Energy_points <= 0 || Hit_points <= 0) {
        std::cout << "ScavTrap " << name << " has no energy or hit points left to attack.\n";
        return;
    }
    --Energy_points;
    std::cout << "ScavTrap " << name << " viciously attacks " << target
              << ", causing " << Attack_damage << " points of damage!\n";  
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode.\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << name << " destructed.\n";
}