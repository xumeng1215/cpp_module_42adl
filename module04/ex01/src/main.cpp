#include "Animal.hpp"
#include "../include/Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *meta[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << "This is a " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		delete meta[i];
	}

	Cat cat1;
	cat1.setBrainIdea(0, "sleeeeeep");
	std::cout << "Cat1 idea 0 is " << cat1.getBrainIdea(0) << std::endl;

	Cat cat2 = cat1;
	std::cout << "Cat2 idea 0 is " << cat2.getBrainIdea(0) << std::endl;

	cat2.setBrainIdea(0, "making biscuits");
	std::cout << "Cat2 idea 0 is " << cat2.getBrainIdea(0) << std::endl;
	std::cout << "Cat1 idea 0 is " << cat1.getBrainIdea(0) << std::endl;
}