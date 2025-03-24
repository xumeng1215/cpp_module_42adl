#include "ScalarConverter.hpp"

static bool isChar(const std::string &input)
{
	// Check if the input is a single non-digit character
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;

	// Check if the input is a character enclosed in single quotes (e.g., 'a')
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return true;

	// If neither condition is met, the input is not a character
	return false;
}

static bool isInt(const std::string &input)
{
	size_t i = 0;

	// Check for empty input
	if (input.empty())
		return false;

	// Check for optional '+' or '-' sign
	if (input[i] == '+' || input[i] == '-')
		i++;

	if (i == input.length()) // No digits after the sign
		return false;

	// Iterate through the string
	while (i < input.length())
	{
		// Ensure all characters are digits
		if (!std::isdigit(input[i]))
			return false;
		i++;
	}

	// Check for overflow: input length should not exceed 11 characters
	// (10 digits for INT_MAX/INT_MIN and 1 for optional sign)
	if (input.length() > 11 ||
		(input.length() == 11 && (input[0] != '-' && input[0] != '+')))
		return false;

	return true;
}

static bool isDouble(const std::string &input)
{
	size_t i = 0;
	int dot = 0;
	int exp = 0;

	// Check for empty input
	if (input.empty())
		return false;

	// Check for optional '+' or '-' sign
	if (input[i] == '+' || input[i] == '-')
		i++;

	// Ensure at least one digit is present before 'e' or 'E'
	bool hasDigits = false;

	// Iterate through the string
	while (i < input.length())
	{
		if (input[i] == '.')
		{
			// Increment dot counter for each '.'
			if (exp > 0) // '.' cannot appear after 'e' or 'E'
				return false;
			dot++;
		}
		else if (input[i] == 'e' || input[i] == 'E')
		{
			// Increment exp counter for each 'e' or 'E'
			if (exp > 0 || !hasDigits) // Multiple 'e' or no digits before 'e'
				return false;
			exp++;
			hasDigits = false; // Reset digit check for the exponent part

			// Check for optional '+' or '-' after 'e' or 'E'
			if (i + 1 < input.length() && (input[i + 1] == '+' || input[i + 1] == '-'))
				i++;
		}
		else if (std::isdigit(input[i]))
		{
			// Mark encountered a digit
			hasDigits = true;
		}
		else
		{
			// Invalid character found
			return false;
		}
		i++;
	}

	// Ensure there is at most one dot, at most one 'e', and at least one digit
	if (dot > 1 || exp > 1 || !hasDigits)
		return false;

	return true;
}

static bool isFloat(const std::string &input)
{
	size_t i = 0;
	int dot = 0;
	int exp = 0;

	// Check for empty input
	if (input.empty())
		return false;

	// Check for optional '+' or '-' sign
	if (input[i] == '+' || input[i] == '-')
		i++;

	// Ensure at least one digit is present before 'e' or 'E'
	bool hasDigits = false;

	// Iterate through the string
	while (i < input.length() - 1) // Exclude the last character ('f')
	{
		if (input[i] == '.')
		{
			// Increment dot counter for each '.'
			if (exp > 0) // '.' cannot appear after 'e' or 'E'
				return false;
			dot++;
		}
		else if (input[i] == 'e' || input[i] == 'E')
		{
			// Increment exp counter for each 'e' or 'E'
			if (exp > 0 || !hasDigits) // Multiple 'e' or no digits before 'e'
				return false;
			exp++;
			hasDigits = false; // Reset digit check for the exponent part

			// Check for optional '+' or '-' after 'e' or 'E'
			if (i + 1 < input.length() - 1 && (input[i + 1] == '+' || input[i + 1] == '-'))
				i++;
		}
		else if (std::isdigit(input[i]))
		{
			// Mark that we have encountered a digit
			hasDigits = true;
		}
		else
		{
			// Invalid character found
			return false;
		}
		i++;
	}

	// Ensure the last character is 'f'
	if (input[i] != 'f')
		return false;

	// Ensure there is at most one dot, at most one 'e', and at least one digit
	if (dot > 1 || exp > 1 || !hasDigits)
		return false;

	return true;
}

scalarType getType(const std::string &str)
{
	if (str == "nan" || str == "nanf")
		return NAN_;
	if (str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff")
		return INF;
	else if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isDouble(str))
		return DOUBLE;
	else if (isFloat(str))
		return FLOAT;
	else
		return INVALID;
}