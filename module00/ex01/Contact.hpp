#ifndef CONTACT_H
#define CONTACT_H

#include <string>

typedef std::string str;

class Contact
{
private:
	str last_name;
	str first_name;
	str nick_name;
	str phone;
	str note;

public:
	Contact();
	~Contact();

	void setLastName(str last_name);
	str getLastName();
	void setFirstName(str first_name);
	str getFirstName();
	void setNickName(str nick_name);
	str getNickName();
	void setPhone(str phone);
	str getPhone();
	void setNote(str note);
	str getNote();
};

#endif