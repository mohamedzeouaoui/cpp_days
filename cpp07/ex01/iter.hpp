#ifndef INTER_HPP
# define INTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>


template <typename T, typename F>
void iter(T *array, size_t length, F funct) {
    for (size_t i = 0; i < length; ++i) {
        funct(array[i]);
    }
}

template <typename T>
void print(T &value) {
    std::cout << value << std::endl;
}
template <typename T>
void increment(T &value) {
    value++;
}
template <typename T>
void decrement(T &value) {
    value--;
}
template <typename T>
void doubleValue(T &value) {
    value *= 2;
}




#endif