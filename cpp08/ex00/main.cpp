#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Valeur trouvée : " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Valeur trouvée : " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    try
    {
        std::list<int> lst ;
        lst.push_front(5);
        lst.push_front(15);
        lst.push_front(25);
        lst.push_front(35);
        std::list<int>::iterator iter= easyfind(lst, 25);
        std::cout << "valeur trouvee : " << *iter << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << "Erreur_list : " << e.what() << '\n';
    }
    


    return 0;
}