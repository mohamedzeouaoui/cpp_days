#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    return new Zombie(name);
    // return new(std::nothrow) Zombie(name);

}