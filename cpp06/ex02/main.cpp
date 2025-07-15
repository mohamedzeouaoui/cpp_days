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


