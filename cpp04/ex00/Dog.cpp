#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const 
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog::Dog(const Dog& obj)
{
    std::cout << "Dog Copy Constructor has been called\n";
    *this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Dog copy assignement has been called\n";
    if (this != &obj)
        type = obj.type;
    return *this;
}
