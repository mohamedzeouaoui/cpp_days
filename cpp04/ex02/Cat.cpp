#include "Cat.hpp"

Cat::Cat() : AAnimal()
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

Cat::Cat(const Cat& obj)
{
    std::cout << "Cat Copy Constructor has been called\n";
    *this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat copy assignement has been called\n";
    if (this != &obj)
    {
        type = obj.type;
        brain = new Brain;
        for (int i = 0; i < 100; i++)
            brain[i] = obj.brain[i];
    }
    return *this;
}
