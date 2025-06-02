#include "Bureaucrat.hpp"

int main( void )
{
    try
    {
        Bureaucrat bob("Simo", 151); // Should throw exception
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Zmagri", 2);
        alice.incrementGrade(); // grade becomes 1
        alice.incrementGrade(); // should throw GradeTooHighException
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
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
