#include "Fixed.hpp"

Fixed::Fixed() : val(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int a){
    std::cout << "Int constructor called" << std::endl;
    this->val = a << Fixed::fractional_bits;
}

Fixed::Fixed(const float b)
{
    std::cout << "Float constructor called" << std::endl;
    this->val = roundf(b * (1 << Fixed::fractional_bits));

}

float Fixed::toFloat( void ) const
{
    return ((float)this->val / (1 << Fixed::fractional_bits));
}

int Fixed::toInt( void ) const
{
    return (this->val >> Fixed::fractional_bits );
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

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
    out << value.toFloat();
    return out;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called " << (this->val >> 8) << std::endl;
}