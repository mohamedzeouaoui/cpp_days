#include "Fixed.hpp"

Fixed::Fixed() : val(0)
{

}

Fixed::Fixed(const int a){
    this->val = a << Fixed::fractional_bits;
}

Fixed::Fixed(const float b)
{
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
    if (this != &original)
    {
        this->val = original.val;
    }
    return *this;
}



int Fixed::getRawBits( void ) const
{
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


Fixed Fixed::operator+(const Fixed& value) const
{
    return this->toFloat() + value.toFloat();
}

Fixed Fixed::operator-(const Fixed& value) const
{
    return this->toFloat() - value.toFloat();
}

Fixed Fixed::operator*(const Fixed& value) const
{
    return this->toFloat() * value.toFloat();
}

Fixed Fixed::operator/(const Fixed& value) const
{
    return this->toFloat() / value.toFloat();
}

bool Fixed::operator>(const Fixed& other) const
{
    if (this->toFloat() > other.toFloat())
        return true;
    else
        return false;

}
bool Fixed::operator<(const Fixed& other) const
{
    if (this->toFloat() < other.toFloat())
        return true;
    else
        return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->toFloat() >= other.toFloat())
        return true;
    else
        return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->toFloat() <= other.toFloat())
        return true;
    else
        return false;
}

bool Fixed::operator==(const Fixed& other) const
{
    if (this->toFloat() == other.toFloat())
        return true;
    else
        return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->toFloat() != other.toFloat())
        return true;
    else
        return false;
}

Fixed& Fixed::operator++()      // Pre-increment
{
    ++this->val;
    return *this;
}
Fixed Fixed::operator++(int)    // Post-increment
{
    Fixed tmp = *this;
    ++this->val;
    return tmp;
}
Fixed& Fixed::operator--()      // Pre-decrement
{
    --this->val;
    return *this;
}
Fixed Fixed::operator--(int)    // Post-decrement
{
    Fixed tmp = *this;
    --this->val;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a > b)
        return b;
    else
        return a;    
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return b;
    else
        return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a < b)
        return b;
    else
        return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a < b) ? b : a;
}



Fixed::~Fixed()
{
    // std::cout << "Destructor called " << (this->val >> 8) << std::endl;
}