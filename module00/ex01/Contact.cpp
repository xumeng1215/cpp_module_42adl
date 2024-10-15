#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setLastName(str last_name) { this->last_name = last_name; }
str Contact::getLastName() { return this->last_name; }

void Contact::setFirstName(str first_name) { this->first_name = first_name; }
str Contact::getFirstName() { return this->first_name; }

void Contact::setNickName(str nick_name) { this->nick_name = nick_name; }
str Contact::getNickName() { return this->nick_name; }

void Contact::setPhone(str phone) { this->phone = phone; }
str Contact::getPhone() { return this->phone; }

void Contact::setNote(str note) { this->note = note; }
str Contact::getNote() { return this->note; }