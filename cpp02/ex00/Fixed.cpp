#include "Fixed.hpp"

Fixed::Fixed() : val(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->val =copy.val;
}

Fixed& Fixed::operator=(const Fixed& original)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
    {
        this->val = original.val;
    }
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->val;

}

void Fixed::setRawBits( int const raw )
{
    this->val = raw ;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}