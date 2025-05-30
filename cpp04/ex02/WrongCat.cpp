#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow? (WrongCat)" << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
    std::cout << "WrongCat Copy Constructor has been called\n";
    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    std::cout << "WrongCat copy assignement has been called\n";
    if (this != &obj)
        type = obj.type;
    return *this;
}

