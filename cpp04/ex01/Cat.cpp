#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return brain;
}
