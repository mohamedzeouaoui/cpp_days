# ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
	    Animal();
        Animal(Animal& obj);
        Animal(std::string _type);
        Animal& operator=(Animal &obj);
	    virtual ~Animal();
		std::string getType() const;
		void setType(std::string _type);
		virtual void makeSound() const;
};


#endif