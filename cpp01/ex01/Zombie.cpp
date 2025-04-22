#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << this->name << " has been destroyed." << std::endl;
}
void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl ;
}
void Zombie::setName(std::string name)
{
    this->name = name;
}
std::string Zombie::getName(void)
{
    return this->name;
}
