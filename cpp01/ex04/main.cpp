#include <string>
#include <iostream>
#include <fstream>

int find_string(std::string line, std::string search)
{
    int position;

    position = line.find(search);

    if (position == std::string::npos)
        return -1;
    else
        return ((int)position);    

}

void replace_in_file(std::string line, std::string search, std::string str_rpl , std::ofstream &file_out)
{
    int pos = find_string(line, search);
    if (pos != -1)
    {
        file_out << line.substr(0,pos) << str_rpl << 
        line.substr(pos + search.length(), line.length() - pos + search.length()) << std::endl;
    }
    else
        file_out << line << std::endl;
}

int main(int ac, char const *av[])
{
    std::string new_file;

    if (ac != 4)
    {
        std::cerr << "Usage: ./program <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    
    if (!av[2])
    {
        std::cerr << "Error: s1 is an empty string!" << std::endl;
        return (1);
    }
    
    std::ifstream file(av[1]);
    
    if (!file)
    {
        std::cerr << "Error: could not open the file." << std::endl;
        return 1;
    }
    new_file.append(av[1]);
    new_file.append(".replace");
    std::ofstream file_out(new_file);
    
    if (!file)
    {
        std::cerr << "Error: could not create or open the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line))
    {
        replace_in_file(line, av[2], av[3], file_out);
        // file_out << line << std::endl;
    }

    return 0;
}

