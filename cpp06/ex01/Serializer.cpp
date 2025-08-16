#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t ptr)
{
    return reinterpret_cast<Data*>(ptr);
}

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer& Serializer::operator=(Serializer& other)
{
    (void)other; // Prevent unused parameter warning
    return *this;
}

