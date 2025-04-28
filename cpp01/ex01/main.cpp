#include "Zombie.hpp"

int main(int ac, char const *av[])
{
    std::string N;
    (void)ac;
    (void)av;

    std::getline(std::cin, N);
    int n = std::atoi(N.c_str());
    Zombie *n_zomb = zombieHorde(n, "Mohamed");

    for (int i = 0; i < n; i++)
        std::cout << "zombie number: " << i << " have a name => " << n_zomb[i].getName() << std::endl ;
    delete[] n_zomb;

    return 0;
}

