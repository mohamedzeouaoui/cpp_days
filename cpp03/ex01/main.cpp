#include "ScavTrap.hpp"

int main( void ) 
{
    std::cout << "---- ClapTrap Test ----\n";
    ClapTrap clap("CL4P-TP");
    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n---- ScavTrap Test ----\n";
    ScavTrap scav("SC4V-TP");
    
    scav.attack("Psycho");
    std::cout << "\n----------------------------------------- ----\n";
    scav.takeDamage(40);
    scav.beRepaired(20);
    scav.guardGate();
    std::cout << "\n----------------------------------------- ----\n";




    return 0;
}
