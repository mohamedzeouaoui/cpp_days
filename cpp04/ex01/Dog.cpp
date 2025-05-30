#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->type = "Dog";
    this->brain = new Brain;
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& obj)
{
    std::cout << "Dog Copy Constructor has been called\n";
    *this = obj;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy assignement called\n";
	if (this != &other)
	{
		Animal::operator=(other);
		// delete brain;
		brain = new Brain(*other.getBrain());
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

