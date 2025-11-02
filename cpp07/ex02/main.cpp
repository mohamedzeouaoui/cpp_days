#include "Array.hpp"

// #define MAX_VAL 750

// int main(int, char**)
// {
    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
        // const int value = rand();
        // numbers[i] = value;
        // mirror[i] = value;
    // }
    // // SCOPE
    // {
        // Array<int> tmp = numbers;
        // Array<int> test(tmp);
    // }
// 
    // for (int i = 0; i < MAX_VAL; i++)
    // {
        // if (mirror[i] != numbers[i])
        // {
            // std::cerr << "didn't save the same value!!" << std::endl;
            // return 1;
        // }
    // }
    // try
    // {
        // numbers[2] = 0;
    // }
    // catch(const std::exception& e)
    // {
        // std::cerr << e.what() << '\n';
    // }
    // try
    // {
        // numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
        // std::cerr << e.what() << '\n';
    // }
// 
    // for (int i = 0; i < MAX_VAL; i++)
    // {
        // numbers[i] = rand();
    // }
    // delete [] mirror;//
    // return 0;
// }

int main() 
{
    std::cout << "Testing default constructor:" << std::endl;
    const Array<const int> a;
    try{
        std::cout << a[0] << "\n";
    }
    catch(std::exception &e)
    {

    }
    std::cout << "Size of a: " << a.size() << std::endl;

    std::cout << "\nTesting constructor with size:" << std::endl;
    Array<std::string> b(3);
    b[0] = "Hello";
    b[1] = "42";
    b[2] = "Students";

    for (unsigned int i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    std::cout << "\nTesting copy constructor:" << std::endl;
    Array<std::string> c(b);
    c[1] = "World";
    std::cout << "b[1] = " << b[1] << std::endl;
    std::cout << "c[1] = " << c[1] << std::endl;

    std::cout << "\nTesting out-of-bounds:" << std::endl;
    try {
        std::cout << b[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}


// #include <iostream>
// // #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     // SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

