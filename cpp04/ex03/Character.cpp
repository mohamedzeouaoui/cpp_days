#include "Character.hpp"
#include <iostream>

t_gc* Character::head = NULL;

Character::Character() : _name("empty"), _count(0)
{
    std::cout << "Character Default constructur called\n";
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name), _count(0) 
{
    std::cout << "Character constructur called\n";
    for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(const Character& other)
{
    std::cout << "Character Copy constructur called\n";
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    std::cout << "Character copy assignement operator has been called\n";
    if (this != &other)
    {
        _name = other._name;
        _count = other._count;
        for (int i = 0; i < 4; ++i)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character Destructor has been called\n";

    for (int i = 0; i < 4; ++i)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m || _count >= 4)
        return ;
    _inventory[_count] = m->clone();
    _count++;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return ;
    add_gc(_inventory[idx]);
    if (_inventory[idx])
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
	return ;
_inventory[idx]->use(target);
	
}

//-----------------------------------------------------

void Character::add_gc(AMateria *p)
{
    t_gc *tmp = head;
    head = new t_gc;
    head->p = p;
    head->next = tmp;
}



void Character::cleanMateria()
{
    t_gc *tmp = head;
    t_gc *d = NULL;
    while(tmp)
    {
        d = tmp;
        tmp = tmp->next;
        delete d->p;
        delete d;
    }
    head = NULL;
}
