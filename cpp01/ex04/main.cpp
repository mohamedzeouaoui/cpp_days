#include <string>
#include <iostream>
#include <fstream>

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
        // line.find()
        file_out << line << std::endl;
    }

        


    return 0;
}
