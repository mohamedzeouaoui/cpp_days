#include "Cure.hpp"


Cure::Cure(): AMateria("Cure")
{

}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
