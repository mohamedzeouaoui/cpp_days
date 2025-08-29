#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    (void )av;
    std::map<std::string ,double> data;
    if (ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 1; 
    }
    try
    {
        insert_data(data);
        input_file(data, av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
