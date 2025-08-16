#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice Default Constructor has been called\n";
}

Ice::~Ice()
{
    std::cout << "Ice Destructor has been called\n";
}

AMateria *Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
    std::cout << "Ice Copy Constructor has been called\n";
    *this = copy;
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice Copy assignement has been called\n";
    (void)other;
    return *this;
}
