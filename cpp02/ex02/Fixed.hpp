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
        Fixed operator+(const Fixed& value) const;
        Fixed operator-(const Fixed& value) const;
        Fixed operator*(const Fixed& value) const;
        Fixed operator/(const Fixed& value) const;

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed& operator++();      // Pre-increment
        Fixed operator++(int);    // Post-increment
        Fixed& operator--();      // Pre-decrement
        Fixed operator--(int);    // Post-decrement


        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);


        
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
std::ostream& operator<<(std::ostream& out, const Fixed& value);


#endif