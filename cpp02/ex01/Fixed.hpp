#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
class Fixed
{
    private:
        int val;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const int a);
        Fixed(const float b);
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed& operator=(const Fixed& original);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
std::ostream& operator<<(std::ostream& out, const Fixed& value);


#endif