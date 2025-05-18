# ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    protected:

    public:
        Dog();
        ~Dog();
    void makeSound() const;
};



#endif