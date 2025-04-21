
#include "PhoneBook.hpp"

int main(int argc, char const *argv[])
{
	PhoneBook phonebook_P;
	std::string cmd;
	while (1)
	{
		std::cout << "Enter your command: ";
		// std::cin >> cmd;
		// std::cout << "==> {" << cmd << "}\n";
		if (!std::getline(std::cin, cmd)) {
			std::cout << "\nExit\n";
			exit(0);
		}
		if (cmd == "ADD")
		{
			phonebook_P.addContact();
			// std::cout << phonebook_P.getcontacts(0).getFirstName() << "\n";
			// std::cout << phonebook_P.getcontacts(0).getLastName() << "\n";

		}
		if (cmd == "SEARCH") {

			phonebook_P.searchContact();
		}
		if(cmd == "EXIT") {
			phonebook_P.exit_program();
		}
	}
	

	return 0;
}
