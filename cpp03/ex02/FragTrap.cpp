#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap " << name << " constructed.\n";
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destructed.\n";
}


void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests high fives from everyone! ✋\n";
}

