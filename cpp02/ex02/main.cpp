#include "Fixed.hpp"

// int main( void ) {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }

int main( void ) {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 0 ) );
//     std::cout << "b===" << b << std::endl;

//     Fixed const c( Fixed( 5.05f ) / Fixed( 0 ) );
//     std::cout << "c===" << c << std::endl;
 
//     Fixed const d( Fixed( 5.05f ) + Fixed( 0 ) );
//     std::cout << "d===" << d << std::endl;

//     Fixed const e( Fixed( 5.05f ) - Fixed( 0 ) );
//     std::cout << "e===" << e << std::endl;

    // Fixed a(10.5f);
    // Fixed b(20.25f);
    // Fixed c(10.5f);

    // std::cout << std::boolalpha; // print bools as true/false

    // std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;

    // std::cout << "\n--- COMPARISONS ---\n";

    // std::cout << "a > b:  " << (a > b) << std::endl;
    // std::cout << "a < b:  " << (a < b) << std::endl;
    // std::cout << "a >= b: " << (a >= b) << std::endl;
    // std::cout << "a <= b: " << (a <= b) << std::endl;
    // std::cout << "a == b: " << (a == b) << std::endl;
    // std::cout << "a != b: " << (a != b) << std::endl;

    // std::cout << "\nComparing a and c (equal values):\n";

    // std::cout << "a == c: " << (a == c) << std::endl;
    // std::cout << "a != c: " << (a != c) << std::endl;
    // std::cout << "a >= c: " << (a >= c) << std::endl;
    // std::cout << "a <= c: " << (a <= c) << std::endl;

    // Fixed a;
    // Fixed b;
    // std::cout << a++ << std::endl; // use a, then increment
    // std::cout << "a: " << a << std::endl;

    // std::cout << ++a << std::endl; // increment, then use
    // std::cout << "a: " << a << std::endl;

    // std::cout << b-- << std::endl; // use a, then decrement
    // std::cout << "b: " << b << std::endl;

    // std::cout << --b << std::endl; // decrement, then use
    // std::cout << "b: " << b << std::endl;

    Fixed a(5.5f);
    Fixed b(2.25f);
    Fixed c(5.5f);

    std::cout << "a = " << a.toFloat() << std::endl;
    std::cout << "b = " << b.toFloat() << std::endl;
    std::cout << "c = " << c.toFloat() << std::endl;

    // Test min
    std::cout << "min(a, b) = " << Fixed::min(a, b).toFloat() << std::endl;
    std::cout << "min(a, c) = " << Fixed::min(a, c).toFloat() << std::endl;

    // Test max
    std::cout << "max(a, b) = " << Fixed::max(a, b).toFloat() << std::endl;
    std::cout << "max(a, c) = " << Fixed::max(a, c).toFloat() << std::endl;

    // Modify result of min (only works on non-const version)
    Fixed& smaller = Fixed::min(a, b);
    smaller = Fixed(0.0f); // Now a or b is set to 0.0 depending on which was smaller

    std::cout << "After modifying min(a, b):" << std::endl;
    std::cout << "a = " << a.toFloat() << std::endl;
    std::cout << "b = " << b.toFloat() << std::endl;



    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}