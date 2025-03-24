#include "Serializer.hpp"


int main()
{

	Data *data = new Data;
	data->key = "key";
	data->value = 123;

	std::cout << "Key: " << data->key << std::endl;
	std::cout << "Value: " << data->value << std::endl;

	uintptr_t serialized = Serializer::serialize(data);
	std::cout << "Serialized to uintptr_t: " << serialized << std::endl;


	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Key: " << deserialized->key << std::endl;
	std::cout << "Value: " << deserialized->value << std::endl;

	delete data;

	return 0;
}