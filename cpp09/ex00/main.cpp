#include "BitcoinExchange.hpp"

int main(int ac, char const *av[])
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1; 
    }
    std::ifstream(av[1]);

    return 0;
}
