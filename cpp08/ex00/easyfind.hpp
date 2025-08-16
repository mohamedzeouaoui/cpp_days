#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

class NotFoundException : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Element not found";
    }
};

template <typename T> 
typename T::iterator easyfind(T &CONT, int F)
{
    typename T::iterator res = find(CONT.begin() , CONT.end(), F);
    if (res == CONT.end())
    {
        throw NotFoundException();
    }
    return res;
}





#endif