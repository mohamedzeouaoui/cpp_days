#include "Animal.hpp"


Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
    type = "Animal";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::setType(std::string _type)
{
    this->type = _type;
}

void Animal::makeSound() const
{
    std::cout << "Some generic animal sound" << std::endl;
}

Animal::Animal(std::string _type) : type(_type)
{
    std::cout << "Animal Default Constructor has been called\n";
}

Animal::Animal(const Animal& obj)
{
    std::cout << "Animal Copy Constructor has been called\n";
    *this = obj;
}

Animal& Animal::operator=(const Animal& obj)
{
    std::cout << "Animal copy assignement has been called\n";
    if (this != &obj)
        this->type = obj.type;
    return *this;
}