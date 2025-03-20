// #include 
#include <ostream>
#include <iostream>

void megaphone(char *string)
{
    int i;
    char c;

    i = 0;
    while (string[i])
    {
        if (string[i] <= 'z' && string[i] >= 'a')
        {
            c = string[i] -('a'- 'A');
            std::cout << c ;
        }
        else
            std::cout << string[i];
        i++;
    }
}

int main(int ac, char *av[])
{
    int i;

    i = 1;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
        return (0);
    }
    
    while (i < ac)
    {
        megaphone(av[i]);
        i++;
    }
    std::cout << std::endl;
    return 0;
}
