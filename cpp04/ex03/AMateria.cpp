#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type)
{
}

AMateria::~AMateria()
{
}


std::string const & AMateria::getType() const //Returns the materia type
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}

// AMateria* AMateria::clone() const
// {
   
// }
