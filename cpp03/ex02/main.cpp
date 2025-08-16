#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "---- ClapTrap Test ----\n";
    ClapTrap clap("CL4P-TP");
    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n---- ScavTrap Test ----\n";
    ScavTrap scav("SC4V-TP");
    scav.attack("Psycho");
    scav.takeDamage(40);
    scav.beRepaired(20);
    scav.guardGate();

    std::cout << "\n---- FragTrap Test ----\n";
    FragTrap frag("FR4G-TP");
    frag.attack("Raider");
    frag.takeDamage(60);
    frag.beRepaired(40);
    frag.highFivesGuys();

    return 0;
}
