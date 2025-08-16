#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& obj);
        WrongAnimal(std::string _type);
        WrongAnimal& operator=(const WrongAnimal &obj);
        ~WrongAnimal();

        void makeSound() const; // ❌ PAS virtual
        std::string getType() const;
};

#endif
