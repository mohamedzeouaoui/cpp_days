#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Cat::Cat(const Cat& obj)
{
    std::cout << "Cat Copy Constructor has been called\n";
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat copy assignement has been called\n";
    if (this != &obj)
        type = obj.type;
    return *this;
}
