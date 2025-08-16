#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure Default Constructor has been called\n";
}

Cure::~Cure()
{
    std::cout << "Cure Destructor has been called\n";
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
    std::cout << "Cure Copy Constructor has been called\n";
    *this = copy;
}

AMateria *Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure Copy assignement has been called\n";
    (void)other;
    return *this;
}
