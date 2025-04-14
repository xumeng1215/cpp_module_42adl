#include "BitcoinExchange.hpp"
#include <string>

// load the exchange rates from the CSV file while constructing the object
BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("./data.csv");
	if (!file.is_open())
	{
		std::cerr << "Can't open data.csv." << std::endl;
		exit(1);
	}
	std::string line;
	std::getline(file, line); // Skip header line
	// std::cout << line << std::endl; // should be "date,exchange_rate"

	while (std::getline(file, line))
	{
		// std::cout << line << std::endl;
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Invalid line format." << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);

		double rate;
		try
		{
			rate = std::atof(line.substr(pos + 1).c_str());
		}
		catch (const std::exception &e)
		{
			// std::cerr << e.what() << std::endl;
			std::cerr << "Invalid exchange rate format." << std::endl;
			continue;
		}
		// std::cout << std::make_pair(date, rate).first << std::endl;
		// std::cout << std::make_pair(date, rate).second << std::endl;
		this->_exchangeRates.insert(std::make_pair(date, rate));
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_exchangeRates = other._exchangeRates;
	}
	return *this;
}

static bool isValidDate(const std::string &date)
{
	// Check basic format (yyyy-mm-dd)
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Invalid date format: " << date << std::endl;
		return false;
	}

	// Extract year, month, and day as integers
	int year, month, day;
	try
	{
		year = std::atoi(date.substr(0, 4).c_str());
		month = std::atoi(date.substr(5, 2).c_str());
		day = std::atoi(date.substr(8, 2).c_str());
	}
	catch (const std::exception &e)
	{
		std::cerr << "Invalid year month or day numbers: " << date << std::endl;
		return false;
	}

	if (month < 1 || month > 12)
	{
		std::cerr << "Invalid month in date: " << date << std::endl;
		return false;
	}

	if (day < 1 || day > 31)
	{
		std::cerr << "Invalid day in date: " << date << std::endl;
		return false;
	}

	// Check the number of days in the month
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDays = daysInMonth[month - 1];

	// Adjust for leap years in February
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		maxDays = 29;
	}

	if (day > maxDays)
	{
		std::cerr << "Invalid day in date: " << date << std::endl;
		return false;
	}

	return true;
}

static bool isValidValue(const std::string &value_str, double &value)
{
	try
	{
		value = std::atof(value_str.c_str());
	}
	catch (const std::exception &e)
	{
		std::cerr << "Invalid value format: " << value << std::endl;
		return false;
	}

	if (value < 0)
	{
		std::cerr << "Value must be a positive number: " << value << std::endl;
		return false;
	}

	if (value > 1000)
	{
		std::cerr << "Value number is too large: " << value << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::processInput(const std::string &inputfile)
{
	std::ifstream file(inputfile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: file not found" << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line);		// Skip header line
	std::cout << line << std::endl; // should be "date | value"

	while (std::getline(file, line))
	{

		size_t pos = line.find(" | ");
		if (pos == std::string::npos)
		{
			std::cerr << "Error: invalid line format: " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos);
		if (!isValidDate(date))
			continue;

		std::string value_str = line.substr(pos + 3);

		double value;
		if (!isValidValue(value_str, value))
			continue;

		std::map<std::string, double>::iterator it = this->_exchangeRates.lower_bound(date);
		if (it == this->_exchangeRates.end() || it->first != date)
		{
			if (it == this->_exchangeRates.begin())
			{
				std::cerr << "Error: no exchange rate for date " << date << std::endl;
				continue;
			}
			--it;
		}

		double rate = it->second;
		double result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	file.close();
}