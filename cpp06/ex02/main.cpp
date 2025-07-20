#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main()
{

    std::srand(std::time(NULL)); // initialisation de rand()

    Base* obj = generate();         // générer une instance aléatoire

    identify(obj);                  // identifier via pointeur
    identify(*obj);                // identifier via référence

    delete obj;                    // libérer la mémoire
    return 0;
}



    // Base* obj = new A();
    // obj->value = 42;
    // obj->print() ;
    // A* a = dynamic_cast<A*>(obj);
    // if (a) {
        // std::cout << "Dynamic cast to A successful." << std::endl;
    // } else {
        // std::cout << "Dynamic cast to A failed." << std::endl;
    // }
    // obj->print();
    // a->print();
    // std::cout << "Value in A: " << a->value << std::endl;