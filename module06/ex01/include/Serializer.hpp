#pragma once

#include <iostream>
#include <string>

typedef struct Data
{
	std::string key;
	int value;
} Data;

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &rhs);

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};
