#include "Harl.hpp"


int main(int ac, char const *av[])
{
    Harl obj;
    int i;
    int next;
    std::string input[]={"DEBUG", "INFO", "WARNING", "ERROR"};

    if (ac != 2)
    {
        std::cerr << "Please provide exactly one log level: DEBUG, INFO, WARNING, or ERROR." << std::endl;
        return 1;
    }
    
    i = -1;
    while (++i < 4)
    {
        if (input[i] == av[1])
            break;
    }
    switch (i)
    {
        case 0:
            obj.complain("DEBUG");
        case 1:
            obj.complain("INFO");
        case 2:
            obj.complain("WARNING");
        case 3:
            obj.complain("ERROR");
        break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    
    }
    return 0;
}
