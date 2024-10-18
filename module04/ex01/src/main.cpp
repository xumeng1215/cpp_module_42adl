#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	// int i;
	// const Animal *array[10];

	// std::cout << "set an array of cats and dogs" << std::endl;
	// for (i = 0; i < 10; i++)
	// {
	// 	if (i < 5)
	// 	{
	// 		array[i] = new Cat();
	// 		if (!array[i])
	// 		{
	// 			std::cerr << "New cat failed." << std::endl;
	// 			exit(1);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		array[i] = new Dog();
	// 		if (!array[i])
	// 		{
	// 			std::cerr << "New dog failed." << std::endl;
	// 			exit(1);
	// 		}
	// 	}
	// }

	// std::cout << "make sounds!!!!!!!!" << std::endl;
	// for (i = 0; i < 10; i++)
	// {
	// 	std::cout << "This is a " << array[i]->getType() << std::endl;
	// 	array[i]->makeSound();
	// }

	// std::cout << "delete cats and dogs" << std::endl;
	// for (i = 0; i < 10; i++)
	// 	delete array[i];

	Dog *mm = new Dog();
	if (mm == NULL)
	{
		std::cerr << "New cat pointer failed." << std::endl;
		exit(1);
	}
	mm->setIdea(0, "sleep");
	mm->setIdea(1, "sleep again");
	mm->setIdea(2, "poop");
	mm->setIdea(3, "weewee");

	mm->outputBrain();

	return 0;
}