#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
T min(T &A, T &B) {
    return (A < B) ? A : B;
}

template <typename T>
T max(T &A, T &B) {
    return (A > B) ? A : B;
}





#endif