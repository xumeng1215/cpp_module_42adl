#include <string>
#include <iostream>
class Zombie
{
private:
	/* data */
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

