#include "BitcoinExchange.hpp"

int main(int ac, char const *av[])
{
    std::map<std::string ,double> data;
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1; 
    }
    insert_data(data);

    return 0;
}
