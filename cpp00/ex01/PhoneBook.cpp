#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->nbContacts = 0;
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
    std::getline(std::cin, name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastname);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
    
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
    std::string name;
    std::cout << "Enter the contact name: ";
    std::getline(std::cin, name);
    while (i < this->nbContacts)
    {
        if (this->contacts[i].getFirstName);
    }
}

