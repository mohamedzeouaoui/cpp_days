#include "Contact.hpp"

void Contact::setFirstName(std::string name)
{
    this->firstName = name;
}
std::string Contact::getFirstName()
{
    return this->firstName;
}
 
void Contact::setLastName(std::string name)
{
    this->lastName = name;
}
std::string Contact::getLastName()
{
    return this->lastName;
}
void Contact::setNickname(std::string name)
{
    this->nickname = name;
}
std::string Contact::getNickname()
{
    return this->nickname;
}
void Contact::setPhoneNumber(std::string name)
{
    this->phoneNumber = name;
}
std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}
void Contact::setDarkestSecret(std::string name)
{
    this->darkestSecret = name;
}
std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}
