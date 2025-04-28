#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;
    Zombie *zmb = new Zombie[N];
    for (int i = 0; i < N; i++)
        zmb[i].setName(name);
    return zmb;
}
