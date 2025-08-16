#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->nbContacts = 0;
}
Contact PhoneBook::getcontacts(int index)
{
    return this->contacts[index];
}


void PhoneBook::addContact()
{
    int i ;
    std::string name;
    std::string lastname;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "Enter first name: ";
    if(!std::getline(std::cin, name))
    {
        std::cout << "\nExit\n";
			exit(0);
	}
    i = 0;
    while (name[i])
    {
        if (name[i] < 32 || name [i] == 127)
        {
            std::cout << "Wrong first name" << std::endl;
            std::cout << "Enter first name: ";
            std::getline(std::cin, name);
            i = 0;
        }
        else
            i++;
    }
    
    std::cout << "Enter last name: ";
    if(!std::getline(std::cin, lastname))
    {
        std::cout << "\nExit\n";
			exit(0);
	}
    i = 0;
    while (lastname[i])
    {
        if (lastname[i] < 32 || lastname [i] == 127)
        {
            std::cout << "Wrong first last name" << std::endl;
            std::cout << "Enter first last name: ";
            std::getline(std::cin, lastname);
            i = 0;
        }
        else
            i++;
    }

    std::cout << "Enter nickname: ";
    if(!std::getline(std::cin, nickname))
    {
        std::cout << "\nExit\n";
			exit(0);
	}
    i = 0;
    while (nickname[i])
    {
        if (nickname[i] < 32 || nickname [i] == 127)
        {
            std::cout << "Wrong first nickname" << std::endl;
            std::cout << "Enter first nickname: ";
            std::getline(std::cin, nickname);
            i = 0;
        }
        else
            i++;
    }

    std::cout << "Enter phone Number: ";
    if(!std::getline(std::cin, phoneNumber))
    {
        std::cout << "\nExit\n";
			exit(0);
	}
    i = 0;
    while (phoneNumber[i])
    {
        if (phoneNumber[i] < 32 || phoneNumber [i] == 127)
        {
            std::cout << "Wrong first phone Number" << std::endl;
            std::cout << "Enter first phone Number: ";
            std::getline(std::cin, phoneNumber);
            i = 0;
        }
        else
            i++;
    }
    
    std::cout << "Enter darkest secret: ";
    if(!std::getline(std::cin, darkestSecret))
    {
        std::cout << "\nExit\n";
			exit(0);
	}
    
    i = 0;
    while (darkestSecret[i])
    {
        if (darkestSecret[i] < 32 || darkestSecret [i] == 127)
        {
            std::cout << "Wrong first darkest Secret" << std::endl;
            std::cout << "Enter first darkest Secret: ";
            std::getline(std::cin, darkestSecret);
            i = 0;
        }
        else
            i++;
    }
    
    if (this->nbContacts < 8)
    {
        
        this->contacts[this->nbContacts].setFirstName(name);
        this->contacts[this->nbContacts].setLastName(lastname);
        this->contacts[this->nbContacts].setNickname(nickname);
        this->contacts[this->nbContacts].setPhoneNumber(phoneNumber);
        this->contacts[this->nbContacts].setDarkestSecret(darkestSecret);
        this->nbContacts++;
    }
    else
    {
        i = 0;
        while (i < 7)
        {
            this->contacts[i].setFirstName(this->contacts[i + 1].getFirstName());
            this->contacts[i].setLastName(this->contacts[i + 1].getLastName());
            this->contacts[i].setNickname(this->contacts[i + 1].getNickname());
            this->contacts[i].setPhoneNumber(this->contacts[i + 1].getPhoneNumber());
            this->contacts[i].setDarkestSecret(this->contacts[i + 1].getDarkestSecret());
            i++;
        }
        this->contacts[i].setFirstName(name);
        this->contacts[i].setLastName(lastname);
        this->contacts[i].setNickname(nickname);
        this->contacts[i].setPhoneNumber(phoneNumber);
        this->contacts[i].setDarkestSecret(darkestSecret);
        
    }
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact()
{
    int i = 0;
    int index;
    std::string str_index;

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|   Index |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    while (i < this->nbContacts)
    {
        std::cout << "| "<< i << "       |";
        if (this->contacts[i].getFirstName().length() > 10)
            std::cout << this->contacts[i].getFirstName().substr(0, 9) + ".|";
        else
            std::cout << std::string(10 - this->contacts[i].getFirstName().length(), ' ') + this->contacts[i].getFirstName() << "|";
        if (this->contacts[i].getLastName().length() > 10)
            std::cout << this->contacts[i].getLastName().substr(0, 9) << ".|";
        else
            std::cout << std::string(10 - this->contacts[i].getLastName().length(), ' ') + this->contacts[i].getLastName() << "|";
        if (this->contacts[i].getNickname().length() > 10)
            std::cout << this->contacts[i].getNickname().substr(0, 9) << ".|" << std::endl;
        else
            std::cout << std::string(10 - this->contacts[i].getNickname().length(), ' ') + this->contacts[i].getNickname() << "|" << std::endl;
        

        i++;
    }


    while (1)
    {
        int flag = 0;
        std::cout << "Enter the index of the contact you want to search: ";
        if(!std::getline(std::cin, str_index))
        {
            std::cout << "\nExit\n";
                exit(0);
        }

        i = 0;
        while (str_index[i])
        {        
            if (str_index[i] > 57 || str_index[i] < 48)
            {
                std::cout << "Wrong index" << std::endl;
                flag = 1;
                break;
            }
            i++;
        }
        if (flag == 1)
            continue;
        if (str_index[0] <= 57 && str_index[0] >= 48)
        {
            index = std::stoi(str_index);
            if (index < this->nbContacts && index < 8 && index >= 0)
                break;
            else
                std::cout << "Wrong index" << std::endl;    
        }
    }
    
    std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;


}

void PhoneBook::exit_program()
{
    std::cout << "Goodbye!\n";
    exit(0);
}
