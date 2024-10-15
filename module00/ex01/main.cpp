#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook myPhoneBook;
	str line;

	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT." << std::endl;
		std::getline(std::cin, line);
		if (!line.compare("ADD"))
			myPhoneBook.add_contact();
		else if (!line.compare("SEARCH"))
			myPhoneBook.search_contact();
		else if (!line.compare("EXIT"))
			break;
	}
	return 0;
}