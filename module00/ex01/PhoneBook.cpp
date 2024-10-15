#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contact_index(0), count(0)
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact()
{
	str first_name;
	str last_name;
	str nick_name;
	str phone;
	str note;

	if (this->contact_index == 8)
		this->contact_index = 0;
	std::cout << "Enter First Name:";
	std::getline(std::cin, first_name);
	std::cout << "Enter Last Name:";
	std::getline(std::cin, last_name);
	std::cout << "Enter Nick Name:";
	std::getline(std::cin, nick_name);
	std::cout << "Enter Phone:";
	std::getline(std::cin, phone);
	std::cout << "Enter Note:";
	std::getline(std::cin, note);
	this->array[this->contact_index].setFirstName(first_name);
	this->array[this->contact_index].setLastName(last_name);
	this->array[this->contact_index].setNickName(nick_name);
	this->array[this->contact_index].setPhone(phone);
	this->array[this->contact_index].setNote(note);
	std::cout << "You just added a contact." << std::endl;
	this->contact_index++;
	if (count < 8)
		count++;
}

void PhoneBook::search_contact()
{
	int i = 0;
	str last_name, first_name, nick_name, phone, note;

	if (this->count == 0)
	{
		std::cout << "No contact in the Phonebook." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "LastName" << "|"
			  << std::setw(10) << "FirstName" << "|"
			  << std::setw(10) << "NickName" << std::endl;
	while (i < this->count)
	{
		last_name = this->array[i].getLastName();
		if (last_name.length() >= 10)
			last_name = last_name.substr(0, 9) + ".";

		first_name = this->array[i].getFirstName();
		if (first_name.length() >= 10)
			first_name = first_name.substr(0, 9) + ".";

		nick_name = this->array[i].getNickName();
		if (nick_name.length() >= 10)
			nick_name = nick_name.substr(0, 9) + ".";

		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << last_name << "|"
				  << std::setw(10) << first_name << "|"
				  << std::setw(10) << nick_name << std::endl;
		i++;
	}
	std::cout << "Enter the index of a contact:";
	std::cin >> i;
	if (!(i >= 0 && i < this->count))
	{
		std::cout << "Check the contact list and try again." << std::endl;
	}
	else
	{
		std::cout << "Last Name: " << this->array[i].getLastName() << std::endl;
		std::cout << "First Name: " << this->array[i].getFirstName() << std::endl;
		std::cout << "Nick Name: " << this->array[i].getNickName() << std::endl;
		std::cout << "Phone: " << this->array[i].getPhone() << std::endl;
		std::cout << "Note: " << this->array[i].getNote() << std::endl;
	}
	getchar();
}