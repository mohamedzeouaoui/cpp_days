#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <stdint.h>

typedef struct Data {
    int value;
    float fvalue;
    std::string stringg;
} Data;

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t ptr);
    private:
        Serializer(); // Prevent instantiation
        ~Serializer(); // Prevent deletion
        Serializer(const Serializer& other); // Prevent copying
        Serializer& operator=(Serializer& other); // Prevent assignment
};

#endif