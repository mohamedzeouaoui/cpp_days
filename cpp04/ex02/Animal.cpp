#include "Animal.hpp"


AAnimal::AAnimal()
{
    std::cout << "Animal constructor called" << std::endl;
    type = "Animal";
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->type;
}

void AAnimal::setType(std::string _type)
{
    this->type = _type;
}

void AAnimal::makeSound() const
{
    std::cout << "Some generic animal sound" << std::endl;
}
