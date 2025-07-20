#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>

template <typename T>
class Array
{
    private:
        T* _array;
        size_t _size;

    public:
        Array() : _array(NULL), _size(0) {}

        Array(unsigned int n) : _array(new T[n]()), _size(n) {}

        Array(const Array& other) : _array(new T[other._size]), _size(other._size)
        {
            for (size_t i = 0; i < _size; ++i)
                _array[i] = other._array[i];
        }

        ~Array()
        {
            delete[] _array;
        }

        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _array;
                _size = other._size;
                _array = new T[_size];
                for (size_t i = 0; i < _size; ++i)
                    _array[i] = other._array[i];
            }
            return *this;
        }

        T& operator[](size_t index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }

        const T& operator[](size_t index) const
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }

        size_t size() const
        {
            return _size;
        }
};

#endif
