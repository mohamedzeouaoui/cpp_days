#include "Zombie.hpp"

int main(int ac, char const *av[])
{
    std::string N;
    (void)ac;
    (void)av;

    std::getline(std::cin, N);
    Zombie *n_zomb = zombieHorde(std::stoi(N), "Mohamed");

    for (int i = 0; i < std::stoi(N); i++)
        std::cout << "zombie number: " << i << " have a name => " << n_zomb[i].getName() << std::endl ;
    delete[] n_zomb;

    return 0;
}

