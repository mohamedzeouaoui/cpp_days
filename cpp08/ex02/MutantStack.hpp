#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iterator> 
#include <stdexcept>

template <typename T>
class MutantStack : public std::stack< T >
{
    private:

    public:
        MutantStack();
        ~MutantStack();
        typedef typename std::stack <T>::containers
};



#endif