#ifndef phonebook_h_HPP
#define phonebook_h_HPP
#include <string>
#include <iostream>
#include <cstdlib>

#include "Contact.hpp"

class PhoneBook
{
private:
    int     nbContacts;
    Contact contacts[8];
    
public:
    PhoneBook();
    Contact getcontacts(int index);
    void addContact();
    void searchContact();
    void exit_program();


};




#endif
