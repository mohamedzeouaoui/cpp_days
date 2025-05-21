# ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string type;
	public:
	    AAnimal();
	    virtual ~AAnimal();
		std::string getType() const;
		void setType(std::string _type);
		virtual void makeSound() const = 0; // méthode virtuelle pure
};


#endif