#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try{
        Bureaucrat b1("Alice", 1);
        ShrubberyCreationForm f1("home");
        RobotomyRequestForm f2("Bender");
        PresidentialPardonForm f3("Rick");
        std::cout << "\n--------------------------------------\n" << std::endl;
        b1.signForm(f1);
        std::cout << "\n--------------------------------------\n" << std::endl;

        b1.executeForm(f1);

        std::cout << "\n--------------------------------------\n" << std::endl;

        b1.signForm(f2);
        std::cout << "\n--------------------------------------\n" << std::endl;
        b1.executeForm(f2);

        std::cout << "\n--------------------------------------\n" << std::endl;
        b1.signForm(f3);
        std::cout << "\n--------------------------------------\n" << std::endl;
        b1.executeForm(f3);
        std::cout << "\n--------------------------------------\n" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
