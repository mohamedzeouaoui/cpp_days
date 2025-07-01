#include "Bureaucrat.hpp"

int main( void )
{
    try
    {
        Bureaucrat bob("Simo", 151); // Should throw exception
        std::cout << bob << std::endl;
    }
    catch (std::exception &err)
    {
        std::cerr << err.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Zmagri", 2);
        std::cout << alice << std::endl;
        alice.incrementGrade(); // grade becomes 1
        std::cout << "next -> " << alice << std::endl;
        alice.incrementGrade(); // should throw GradeTooHighException
        std::cout << alice << std::endl;
    }
    catch (std::exception &err)
    {
        std::cerr << err.what() << std::endl;
    }
    return 0;
}


// int main()
// {
//     try
//     {
//         Bureaucrat a("Mohamed", 15);
//         for (int i = 0; i < 150; i++)
//             a.incrementGrade();
//         std::cout << "Hello\n";
//         std::cout << a << "\n";
//     }
//     catch (std::exception &e)
//     {
//         std::cerr << "Error : " << e.what() << std::endl;
//     }
//     // 
// }
