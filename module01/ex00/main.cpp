#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie *z1 = newZombie("Foo");
	z1->announce();

	Zombie z2("Foo2");
	z2.announce();

	randomChump("Foo3");

	delete z1;
}