#include "ClapTrap.hpp"

int main( void ) 
{
    ClapTrap clap("Bender");

    clap.attack("Fry");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(10);
    clap.attack("Leela");
    clap.beRepaired(2);

    return 0;
}
