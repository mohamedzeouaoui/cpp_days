#include "Cat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    AAnimal *animals[6];
    // AAnimal annny;

    for (int i = 0; i < 3; i++)
        animals[i] = new Dog();
    for (int i = 3; i < 6; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 6; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 6; i++)
        delete animals[i];
    // std::cout << "-------- Wrong Animal --------\n";
    // annny.makeSound();
}