#include "Serializer.hpp"

int main()
{
    Data originalData;
    originalData.value = 42;
    originalData.stringg = "Hello, World!";

    std::cout << "Original - Address: " << &originalData << std::endl;
    std::cout << "Original - Value: " << originalData.value << std::endl;
    std::cout << "Original - Text: " << originalData.stringg << std::endl;

    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "\nSerialized value: " << serialized << std::endl;


    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "\nDeserialized - Address: " << deserialized << std::endl;
    std::cout << "Deserialized - Value: " << deserialized->value << std::endl;
    std::cout << "Deserialized - Text: " << deserialized->stringg << std::endl;
    return 0;
}

