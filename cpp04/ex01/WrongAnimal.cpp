#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal constructor called" << std::endl;
    type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a wrong sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}

WrongAnimal::WrongAnimal(std::string _type) : type(_type)
{
    std::cout << "WrongAnimal Default Constructor has been called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal& obj)
{
    std::cout << "WrongAnimal Copy Constructor has been called\n";
    *this = obj;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& obj)
{
    std::cout << "WrongAnimal copy assignement has been called\n";
    if (this != &obj)
        this->type = obj.type;
    return *this;
}