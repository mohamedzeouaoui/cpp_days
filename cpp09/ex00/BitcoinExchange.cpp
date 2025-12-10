#include "BitcoinExchange.hpp"

void insert_data(std::map<std::string, double> &data)
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        throw errore_opening_file();
    }
    std::string line;

    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream new_line(line);
        std::string data1, value;

        if (std::getline(new_line, data1, ',') && std::getline(new_line, value))
        {
            float value_float = std::atof(value.c_str());
            data[data1] = value_float;
        }
    }
}

int is_numeric(char *str)
{
    int dot = 0;
    if (*str == '.')
        return 1;
    if (*str == '+')
        str++;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            dot++;
            continue;
        }
        if (!isdigit(str[i]) || dot > 1)
            return 1;
    }
    if (dot > 1)
        return 1;
    return 0;
}

int valid_date(char *date)
{
    for (size_t i = 0; i < strlen(date); i++)
    {
        if (!isdigit(date[i]))
            return 1;
    }
    return 0;
}

void valid_line(std::string line)
{
    if (is_numeric((char *)line.substr(0, 4).c_str()) || valid_date((char *)line.substr(0, 4).c_str()))
        throw invalid_input();
    if (line.substr(4, 1) != "-")
        throw invalid_input();
    if (is_numeric((char *)line.substr(5, 2).c_str()) || valid_date((char *)line.substr(5, 2).c_str()) || atoi(((char *)line.substr(5, 2).c_str())) > 12)
        throw invalid_input();
    if (line.substr(7, 1) != "-")
        throw invalid_input();
    if (is_numeric((char *)line.substr(8, 2).c_str()) || valid_date((char *)line.substr(8, 2).c_str()) || atoi((char *)line.substr(8, 2).c_str()) > 31)
        throw invalid_input();
    if (line.substr(10, 3) != " | ")
        throw invalid_input();
    std::string val = line.substr(13);
    if (val == "")
        throw invalid_input();
    if (val[0] == '-')
        throw negative_value();
    if (is_numeric((char *)val.c_str()))
        throw invalid_input();
    if (atof(val.c_str()) > 1000)
        throw big_number();
}

float findClosestDate(const std::map<std::string, double> &db, const std::string &date)
{
    std::map<std::string, double>::const_iterator it = db.lower_bound(date);

    // if (it != db.end() && it->first == date)
    // {
    //     return it->second;
    // }
    // if (it == db.begin())
    // {
    //     throw std::runtime_error("Error: no earlier date in database.");
    // }
    // --it;
    if (it == db.end())
    {
        // date > toutes les dates : prendre le dernier
        --it;
    }
    else if (it->first != date)
    {
        // date est dans un "trou": prendre la date juste avant
        if (it == db.begin())
            throw std::runtime_error("no earlier date in database");
        --it;
    }
    return it->second;
}

void input_file(std::map<std::string, double> &data, std::string file_inp)
{
    std::ifstream file(file_inp.c_str());
    if (!file.is_open())
    {
        throw errore_opening_file();
    }
    std::string line;
    std::getline(file, line);
    if (line != "date | value")
        throw invalid_input();

    while (getline(file, line))
    {
        if (line.empty())
            continue;
        try
        {
            valid_line(line);
            std::string key = line.substr(0, 10);
            double nb_btc = atof(line.substr(13).c_str());
            double price = findClosestDate(data, key);
            double result = price * nb_btc;
            std::cout << key << " => " << nb_btc << " = " << result << std::endl;
        }

        catch (invalid_input &e)
        {
            std::cout << e.what() << line << "\n";
        }
        catch (std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}