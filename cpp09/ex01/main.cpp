#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try {
        long result = RPN::evaluate(argv[1]);
        std::cout << result << std::endl;
        return 0;
    } catch (const std::exception &) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
}
