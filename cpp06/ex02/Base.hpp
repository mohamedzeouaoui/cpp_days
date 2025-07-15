#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>


class Base
{
    public:
        Base();
        virtual ~Base();
};

void identify(Base* p);
void identify(Base& p);
Base* generate(void);


#endif