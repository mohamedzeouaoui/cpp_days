#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <utility>
#include <exception>
#include <string.h>
#include <string>
#include <ctype.h>
#include <sstream>

class errore_opening_file : public std::exeption ()
{
    public:
        const char * what() const throw()
        {
            return "Error while oppening file";
        }
}



#endif