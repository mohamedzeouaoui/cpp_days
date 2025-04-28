#include "Harl.hpp"


int main(int ac, char const *av[])
{
    Harl obj;

    if (ac != 2)
    {
        std::cerr << "Please provide exactly one log level: DEBUG, INFO, WARNING, or ERROR." << std::endl;
        return 1;
    }

    obj.complain(av[1]);
    return 0;
}
