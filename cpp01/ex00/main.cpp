#include "Zombie.hpp"

int main(int ac, char const *av[])
{
    (void)ac;
    (void)av;
    Zombie *zm = newZombie( "ahmed" );
    zm->announce();
    delete zm;


    
    std::cout << "\n";
    randomChump( "redouan" );

    return 0;
}

