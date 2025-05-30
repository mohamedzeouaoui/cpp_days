
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    ICharacter* target = new Character("bob");

    AMateria *ptr;
    ptr = src->createMateria("ice");
    me->equip(ptr);
    ptr = src->createMateria("cure");
    me->equip(ptr);
    
    me->use(0, *target);
    me->use(1, *target);
    me->use(10, *target);

    me->unequip(0);
    me->unequip(1);
    me->unequip(10);


    me->use(2, *target);

    Character::cleanMateria();

    delete target;
    delete me;
    delete src;
    return 0;
}
// int main()
// {
//     std::cout << "=== Creating MateriaSource ===" << std::endl;
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());

//     std::cout << "\n=== Creating Character 'me' ===" << std::endl;
//     ICharacter* me = new Character("me");

//     std::cout << "\n=== Creating Materias from MateriaSource ===" << std::endl;
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);

//     std::cout << "\n=== Creating Character 'bob' ===" << std::endl;
//     ICharacter* bob = new Character("bob");

//     std::cout << "\n=== Using Materias ===" << std::endl;
//     me->use(0, *bob);
//     me->use(1, *bob);
//     me->use(2, *bob);  // Should do nothing

//     std::cout << "\n=== Unequipping Materia at slot 0 ===" << std::endl;
//     me->unequip(0);

//     std::cout << "\n=== Using unequipped Materia ===" << std::endl;
//     me->use(0, *bob);  // Should do nothing

//     std::cout << "\n=== Testing deep copy of Character ===" << std::endl;
//     Character* clone = new Character(*(dynamic_cast<Character*>(me)));
//     std::cout << "\n=== Using Materias from clone ===" << std::endl;
//     clone->use(1, *bob); // Cure still present in slot 1
//     clone->equip(src->createMateria("ice"));
//     clone->use(0, *bob);

//     std::cout << "\n=== Cleaning up ===" << std::endl;
//     delete bob;
//     delete me;
//     delete clone;
//     delete src;

//     return 0;
// }
