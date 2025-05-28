#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"


typedef struct g_c
{
    AMateria* p;
    struct g_c *next;
} t_gc;


class Character : public ICharacter {
    private:
        std::string _name;
        AMateria* _inventory[4];
        static t_gc* head;
        int _count;
    
    public:
        Character();
        Character(std::string const & name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();
    
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
        static void cleanMateria();
        static void add_gc(AMateria *p);
};

#endif
