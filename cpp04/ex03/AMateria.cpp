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

AMateria& AMateria::operator=(const AMateria &obj)
{
    this->_type = obj._type;
    return *this;
}

AMateria::AMateria(const AMateria &copy)
{
    this->_type = copy._type;
}

