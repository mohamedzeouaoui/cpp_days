#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal& obj);
        WrongAnimal(std::string _type);
        WrongAnimal& operator=(WrongAnimal &obj);
        ~WrongAnimal();
    
        void makeSound() const; // ❌ PAS virtual
        std::string getType() const;
};

#endif
