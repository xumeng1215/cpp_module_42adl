#include <string>
#include <iostream>
class Zombie
{
private:
	/* data */
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	void set_name(std::string name);
};
