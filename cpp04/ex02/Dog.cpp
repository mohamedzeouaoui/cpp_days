#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    this->type = "Dog";
    this->brain = new Brain;
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    std::cout << "Dog copy constructor called\n";
    brain = new Brain(*other.brain); // Deep copy
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called\n";
    if (this != &other)
    {
        delete brain; // Libérer l’ancien
        brain = new Brain(*other.brain); // Deep copy
    }
    return *this;
}


Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const 
{
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return brain;
}

