#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        // Intern(const Intern &obj);
        ~Intern();
    
        // Intern &operator=(const Intern &obj);
    
        AForm *makeForm(const std::string &formName, const std::string &target);
};

std::ostream &operator<<(std::ostream &os, const Intern &intern);

#endif