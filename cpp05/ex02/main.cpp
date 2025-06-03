#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Alice", 1);
        RobotomyRequestForm robotomyForm("Bob");
        PresidentialPardonForm pardonForm("Charlie");
        ShrubberyCreationForm shrubberyForm("Garden");

        std::cout << bureaucrat << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;
        std::cout << shrubberyForm << std::endl;

        bureaucrat.signForm(robotomyForm);
        bureaucrat.signForm(pardonForm);
        bureaucrat.signForm(shrubberyForm);

        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);
        bureaucrat.executeForm(shrubberyForm);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}