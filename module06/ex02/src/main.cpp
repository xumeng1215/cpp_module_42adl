#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

static Base *generate()
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		perror("Something went wrong.");
		return (NULL);
	}
}

// identify from pointer
static void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Unknown Class" << std::endl;
}

// identify from reference
static void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Class A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		std::cerr << bc.what() << "NOT A" << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Class B" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		std::cerr << bc.what() << "NOT B" << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Class C" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		std::cerr << bc.what() << "NOT C" << std::endl;
	}
}

int main()
{
	srand(time(NULL));

	Base *base = generate();
	std::cout << "-----------Identify from pointer:" << std::endl;
	identify(base);
	std::cout << "-----------Identify from reference:" << std::endl;
	identify(*base);

	delete base;

	return 0;
}