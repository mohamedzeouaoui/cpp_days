
# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name_v);
        ~ScavTrap();
		void guardGate();

        void attack(const std::string& target);
};




#endif