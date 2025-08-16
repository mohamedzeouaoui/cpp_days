#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    try {
        Span sp(100);
        sp.add_numbers(1);
        sp.add_numbers(9);
        sp.add_numbers(3);
        sp.add_numbers(5);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
