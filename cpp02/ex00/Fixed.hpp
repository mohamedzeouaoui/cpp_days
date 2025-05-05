#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed
{
    private:
        int val;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& copy);
        Fixed& operator=(const Fixed& original);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};


#endif