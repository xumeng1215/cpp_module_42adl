#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <cstdio>

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact array[8];
	int contact_index;
	int count;

public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();
};

#endif