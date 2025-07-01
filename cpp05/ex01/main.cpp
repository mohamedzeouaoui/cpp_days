#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    try {
        Bureaucrat bob("Bob", 45);
        Form formA("Form A", 45, 30);
        
        std::cout << bob << std::endl;
        std::cout << formA << std::endl;

        bob.incrementGrade();
        std::cout << "After incrementing grade: " << bob << std::endl;

        formA.beSigned(bob);
        std::cout << "After signing: " << formA << std::endl;

        formA.execute(bob);
        std::cout << "After execute: " << formA << std::endl;

        bob.decrementGrade();
        std::cout << "After decrementing grade: " << bob << std::endl;

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n----------------------------------------\n" << std::endl;

    try {
        Bureaucrat alice("Alice", 30);
        Form formB("Form B", 15, 30);
        std::cout << alice << std::endl;
        std::cout << formB << std::endl;
        std::cout << "\n----------------------------------------\n" << std::endl;
        alice.signForm(formB);
        
        formB.beSigned(alice);

        std::cout << "After signing: " << formB << std::endl;
        formB.execute(alice);
        std::cout << "After execution: " << formB << std::endl;

        std::cout << "After signing form B by Alice: " << formB << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

// int main()
// {
//     try {
//         Bureaucrat bob("Bob", 50);
//         Form formA("Form A", 45, 30);
        
//         std::cout << bob << std::endl;
//         std::cout << formA << std::endl;

//         bob.incrementGrade();
//         std::cout << "After incrementing grade: " << bob << std::endl;

//         formA.beSigned(bob);
//         std::cout << "After signing: " << formA << std::endl;

//         bob.decrementGrade();
//         std::cout << "After decrementing grade: " << bob << std::endl;

//     }
//     catch (const std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }
//     std::cout << "\n----------------------------------------\n" << std::endl;

//     try {
//         Bureaucrat alice("Alice", 30);
//         Form formB("Form B", 15, 30);
//         std::cout << alice << std::endl;
//         std::cout << formB << std::endl;
//         formB.beSigned(alice);
//         std::cout << "After signing: " << formB << std::endl;
//         formB.execute(alice);
//         std::cout << "After execution: " << formB << std::endl;


//     }
//     catch (const std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }
//     return 0;
// }
