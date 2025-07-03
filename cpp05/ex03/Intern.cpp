#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &obj)
{
    *this = obj;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &obj)
{
    if (this == &obj)
        return *this;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Intern &intern)
{
    os << "Intern object at address: " << &intern;
    return os;
}

static AForm* createShrubbery(const std::string& target) 
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) 
{
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) 
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) 
{
    struct FormEntry
    {
        const char* name;
        AForm* (*create)(const std::string& target);
    };

    FormEntry forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPardon}
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }

    std::cout << "Intern: Error! Unknown form name \"" << formName << "\"" << std::endl;
    return NULL;
}