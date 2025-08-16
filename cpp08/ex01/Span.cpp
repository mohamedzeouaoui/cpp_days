#include "Span.hpp"

Span::Span(unsigned int N)
{
    this->max_size = N;
}

Span::Span(const Span& other): _numbers(other._numbers), 
        max_size(other.max_size)
{
    
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->max_size = other.max_size;
        this->_numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {

}


void Span::add_numbers(int nuumber)
{
    if (this->_numbers.size() >= this->max_size)
    {
        throw std::overflow_error("Span is already full");
    }
    _numbers.push_back(nuumber);
}

int Span::shortestSpan()
{
    if (this->_numbers.size() < 2)
    {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> sorted_vec = _numbers;
    std::sort(sorted_vec.begin(), sorted_vec.end());
    unsigned int i = 0;
    int a;
    int res = sorted_vec[1] - sorted_vec[0];
    while (i < sorted_vec.size() - 1)
    {
        a = sorted_vec[i + 1] - sorted_vec[i];
        if (a < res)
        {
            res = a;
        }
        i++;
    }
    return res;
}

int Span::longestSpan()
{
    if (this->_numbers.size() < 2)
    {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> sorted_vec = _numbers;
    std::sort(sorted_vec.begin(), sorted_vec.end());
    unsigned int i = 0;
    int a;
    int res = sorted_vec[1] - sorted_vec[0];
    while (i < sorted_vec.size() - 1)
    {
        a = sorted_vec[i + 1] - sorted_vec[i];
        if (a > res)
        {
            res = a;
        }
        i++;
    }
    return res;
    
}

