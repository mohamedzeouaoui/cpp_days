#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base()
{
}

Base::~Base()
{
}

Base * generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;
    if (random == 0)
    {
        std::cout << "Generated A" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Generated B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated C" << std::endl;
        return new C();
    }
}

void identify(Base* p)
{
    std::cout << "identify pointer" << " \n";
    if (!p) {
        std::cout << "nullptr\n";
        return;
    }
    std::cout << "dynamic_cast: ";
    if (dynamic_cast<A*>(p)) std::cout << "A\n";
    else if (dynamic_cast<B*>(p)) std::cout << "B\n";
    else if (dynamic_cast<C*>(p)) std::cout << "C\n";

}

#include <iostream>

void identify(Base& p)
{
    std::cout << "identify & \n";
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (...) {}
}

