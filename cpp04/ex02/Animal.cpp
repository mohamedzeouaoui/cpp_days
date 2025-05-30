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


AAnimal::AAnimal(std::string _type) : type(_type)
{
    std::cout << "Animal Default Constructor has been called\n";
}

AAnimal::AAnimal(const AAnimal& obj)
{
    std::cout << "Animal Copy Constructor has been called\n";
    *this = obj;
}

AAnimal& AAnimal::operator=(const AAnimal& obj)
{
    std::cout << "Animal copy assignement has been called\n";
    if (this != &obj)
        this->type = obj.type;
    return *this;
}
