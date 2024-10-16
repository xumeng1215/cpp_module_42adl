#include <iostream>
#include <string>
#include <fstream>

void ft_replace_string(const std::string &filename,
					   const std::string &s1, const std::string &s2)
{
	// open the input file
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error when open file " << filename << std::endl;
		return;
	}

	// create the output file
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error when create output file " << outputFilename << std::endl;
		inputFile.close();
		return;
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::string newLine;
		size_t position = 0;
		while (true)
		{
			// find s1 position, copy the content before, add s2
			// loop through the whole line
			size_t found = line.find(s1, position);
			if (found == std::string::npos)
				break;

			newLine.append(line, position, found - position);
			newLine.append(s2);
			position = found + s1.length();
		}
		// copy rest of the line
		newLine.append(line, position, line.length() - position);
		outputFile << newLine << std::endl;
	}
	inputFile.close();
	outputFile.close();
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "a program that takes three parameters in the following order: a filename and two strings, s1 and s2." << std::endl;
		return 1;
	}
	ft_replace_string(av[1], av[2], av[3]);
	return 0;
}