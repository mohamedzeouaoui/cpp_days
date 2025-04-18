#ifndef phonebook_h_HPP
#define phonebook_h_HPP
#include <string>
#include <iostream>

#include "Contact.hpp"

class PhoneBook
{
private:
    int     nbContacts;
    Contact contacts[8];
    
public:
    PhoneBook();
    void addContact();
    void searchContact();


};




#endif
