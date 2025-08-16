#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <list>

class Span
{
    private:
        std::vector<int> _numbers;
        unsigned int max_size;

    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void add_numbers(int number);

        int shortestSpan();
        int longestSpan();
};



#endif