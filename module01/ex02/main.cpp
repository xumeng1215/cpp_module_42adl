#include <string>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "str variable address:" << &str << std::endl;
	std::cout << "strPTR variable address:" << &strPTR << std::endl;
	std::cout << "strREF variable address:" << &strREF << std::endl;

	std::cout << "str variable value:" << str << std::endl;
	std::cout << "strPTR variable value:" << strPTR << std::endl;
	std::cout << "strREF variable value:" << strREF << std::endl;
}