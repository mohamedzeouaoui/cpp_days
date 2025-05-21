#include "Cat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{

    std::cout << "-------- Declaration & Initialization --------\n";
    int numAnimals = 6;
    AAnimal* animals[numAnimals];

    for (int i = 0; i < numAnimals/2; i++)
        animals[i] = new Dog();

    std::cout << "\n";

    for (int i = numAnimals/2; i < numAnimals; i++)
        animals[i] = new Cat();
    std::cout << "------------------------------------------\n\n";
    

    std::cout << "====== Making Sounds ==============\n";
    for (int i = 0; i < numAnimals; i++)
        animals[i]->makeSound();
    std::cout << "====================================\n\n";
    

    std::cout << "-------- freeing alocated memmory --------\n";
    for (int i = 0; i < numAnimals; i++)
        delete animals[i];
    std::cout << "---------------------------------------\n\n";

    std::cout << "======= Testing Deep Copy =======\n";
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Running around outside");
    dog1.getBrain()->setIdea(1 ,"Fetch the ball");
    
    Dog dog2 = dog1;
    dog2.getBrain()->setIdea(0,"Sleep all day" );

    std::cout << "Dog1 Idea 0: " << dog1.getBrain()->getIdea(0) << "\n";
    std::cout << "Dog1 Idea 1: " << dog1.getBrain()->getIdea(1) << "\n";
    std::cout << "Dog2 Idea 0: " << dog2.getBrain()->getIdea(0) << "\n";
    std::cout << "Dog2 Idea 1: " << dog2.getBrain()->getIdea(1) << "\n";
    std::cout << "=============================\n";

    // -------------------------------------------------------------------------------
    // -------------------------------------------------------------------------------

    std::cout << "======== pointers ============\n";
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;
    std::cout << "=========================\n";

    return 0;
}

