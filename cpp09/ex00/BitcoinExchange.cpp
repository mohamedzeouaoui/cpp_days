#include "BitcoinExchange.hpp"

void insert_data(std::map<std::string ,double> data)
{
    std::fstream file("data.csv");
    if (!file.is_open())
    {
        throw errore_opening_file();
    }
    std::string line;
    getline(file, line);
    while (getline(file, line))
    {
        data.insert()
    }
    
}