#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n---- DiamondTrap Test ----\n";
    DiamondTrap diamond("simooo");
    std::cout << "\n----hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh ----\n";

    diamond.attack("Badass");
    std::cout << "\n----ggggggggggggggggggggggggggggggggggg ----\n";

    diamond.whoAmI();
    std::cout << "\n----VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV ----\n";

    diamond.takeDamage(20);
    std::cout << "\n----lllllllllllllllllllllllllllllllllllllllllllll ----\n";

    diamond.beRepaired(10);
    std::cout << "\n----oooooooooOOOOOOoooooOOOOOoooooooooooooOOOOOOO ----\n";


    return 0;
}
