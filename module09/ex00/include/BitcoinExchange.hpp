#ifndef BTC_EXCHANGE_HPP
#define BTC_EXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>


class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void readFile(const std::string &fileName);

private:
	std::map<std::string, double> _exchangeRates;
};

#endif // BTC_EXCHANGE_HPP