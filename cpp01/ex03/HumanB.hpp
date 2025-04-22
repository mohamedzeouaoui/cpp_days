#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

#include <iostream>
#include <string>

class HumanB
{
    private:
        std::string name;
        Weapon *weapon_B;

    public:
        HumanB(std::string name);
        std::string getName();
        Weapon getWeapon();
        void attack();
        ~HumanB();
};

#endif