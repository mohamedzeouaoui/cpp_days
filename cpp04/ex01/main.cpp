#include "Cat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    return 0;
}







// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << "--------------------------------------------------\n";
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << "---------------------------------------------------\n";

//     std::cout << i->getType() << " " << std::endl;
//     std::cout << "--------------------------------------------------\n";

//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();

//     delete meta;
//     delete j;
//     delete i;

//     return 0;
// }

// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

// int main() {
//     const WrongAnimal* wrong = new WrongAnimal();
//     const WrongAnimal* wrongCat = new WrongCat();
//     std::cout << "--------------1------------------------------------\n";

//     std::cout << wrong->getType() << std::endl;     // WrongAnimal
//     std::cout << "------------------2--------------------------------\n";

//     std::cout << wrongCat->getType() << std::endl;  // WrongCat
//     std::cout << "-------------------3-------------------------------\n";

//     wrong->makeSound();       // WrongAnimal sound
//     std::cout << "-----------------4---------------------------------\n";

//     wrongCat->makeSound();    // ❌ WrongAnimal sound aussi (car pas virtual)

//     delete wrong;
//     delete wrongCat;

//     return 0;
// }
