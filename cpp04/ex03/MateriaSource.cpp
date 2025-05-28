// MateriaSource.cpp
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _count(0)
{
    std::cout << "MateriaSource Default constructur called\n";
    for (int i = 0; i < 4; ++i)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource Copy Constructor has been called\n";
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "MateriaSource Copy assignement has been called\n";
    if (this != &other)
    {
        _count = other._count;
        for (int i = 0; i < 4; ++i)
        {
            _templates[i] = other._templates[i] ? other._templates[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Destructor has been called\n";
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i])
            delete _templates[i];
    }
}



void MateriaSource::learnMateria(AMateria* m)
{
    if(_count >=0 && _count < 4)
    {
        _templates[_count] = m;
        _count++;
    
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i) {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i];
    }
    return NULL;
}
