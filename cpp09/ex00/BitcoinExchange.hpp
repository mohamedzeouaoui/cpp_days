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

class errore_opening_file : public std::exception
{
    public:
        const char * what() const throw()
        {
            return "Error while oppening file";
        }
};

class invalid_input : public std::exception
{
    public:
        const char * what()const throw()
        {
            return "Error: bad input => ";
        }
};

class negative_value : public std::exception
{
    public:
        const char * what()const throw()
        {
            return "is a negative number.";
        }
};

class big_number : public std::exception
{
    public:
        const char * what()const throw()
        {
            return "too large a number.";
        }
};


void insert_data(std::map<std::string ,double>& data);
void input_file(std::map<std::string , double>& data,std::string file_inp);

#endif