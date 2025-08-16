#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type)
{
    std::cout << "AMateria Constructor has been called\n";
}

AMateria::AMateria() : _type("AMateria")
{
    std::cout << "AMateria Default Constructor has been called\n";
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor has been called\n";
}


std::string const & AMateria::getType() const //Returns the materia type
{
    return this->_type;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
    std::cout << "AMateria copy assignement operator has been called\n";
    if (this != &obj) 
        _type = obj._type;
    return *this;
}

AMateria::AMateria(const AMateria &copy)
{
    std::cout << "Character Copy constructur called\n";
    *this = copy;
}


void AMateria::use(ICharacter& target)
{
    (void)target;
}

