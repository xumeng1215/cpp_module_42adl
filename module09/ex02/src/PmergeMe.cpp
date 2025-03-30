#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge(int ac, char **av)
{
	// Parse input into a vector and a deque
	std::vector<int> numbersVector = parseInputToVector(ac, av);
	std::deque<int> numbersDeque = parseInputToDeque(ac, av);

	// Sort using std::vector and measure time
	std::clock_t startVector = std::clock();
	fordJohnsonSort(numbersVector);
	std::clock_t endVector = std::clock();
	double elapsedVector = 1000.0 * (endVector - startVector) / CLOCKS_PER_SEC;

	// Sort using std::deque and measure time
	std::clock_t startDeque = std::clock();
	fordJohnsonSort(numbersDeque);
	std::clock_t endDeque = std::clock();
	double elapsedDeque = 1000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

	// Output the sorted numbers for std::vector
	std::cout << "Sorted numbers (vector): ";
	for (std::vector<int>::size_type i = 0; i < numbersVector.size(); i++)
	{
		std::cout << numbersVector[i];
		if (i != numbersVector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	// Output the sorted numbers for std::deque
	std::cout << "Sorted numbers (deque): ";
	for (std::deque<int>::iterator it = numbersDeque.begin(); it != numbersDeque.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != numbersDeque.end())
			std::cout << " ";
	}
	std::cout << std::endl;

	// Output the time taken for sorting
	std::cout << "Time taken for sorting (vector): " << elapsedVector << " ms" << std::endl;
	std::cout << "Time taken for sorting (deque): " << elapsedDeque << " ms" << std::endl;
}

std::vector<int> PmergeMe::parseInputToVector(int ac, char **av)
{
	std::vector<int> numbers;

	for (int i = 1; i < ac; i++)
	{
		std::string arg(av[i]);
		int num;

		// Validate and convert input to integers
		std::istringstream iss(arg);
		if (!(iss >> num) || !iss.eof())
		{
			throw std::invalid_argument("Invalid input: " + arg);
		}

		numbers.push_back(num);
	}

	return numbers;
}

std::deque<int> PmergeMe::parseInputToDeque(int ac, char **av)
{
	std::deque<int> numbers;

	for (int i = 1; i < ac; i++)
	{
		std::string arg(av[i]);
		int num;

		// Validate and convert input to integers
		std::istringstream iss(arg);
		if (!(iss >> num) || !iss.eof())
			throw std::invalid_argument("Invalid input: " + arg);
		numbers.push_back(num);
	}

	return numbers;
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &numbers)
{
	if (numbers.size() <= 1)
		return;

	// Step 1: Pair the numbers
	std::vector<std::pair<int, int> > pairs;
	typename Container::iterator it = numbers.begin();
	while (it != numbers.end())
	{
		int first = *it;
		++it;
		if (it != numbers.end())
		{
			int second = *it;
			++it;
			if (first > second)
				pairs.push_back(std::make_pair(second, first));
			else
				pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			pairs.push_back(std::make_pair(first, first)); // Handle odd number of elements
		}
	}

	// Step 2: Sort the larger elements of the pairs
	Container largerElements;
	for (typename std::vector<std::pair<int, int> >::iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt)
	{
		largerElements.push_back(pairIt->second);
	}
	std::sort(largerElements.begin(), largerElements.end());

	// Step 3: Merge the smaller elements into the sorted larger elements
	Container result;
	mergePairs(pairs, result);

	// Step 4: Replace the original numbers with the sorted result
	numbers = result;
}

template <typename Container>
void PmergeMe::mergePairs(std::vector<std::pair<int, int> > &pairs, Container &result)
{
	// Extract the larger elements (already sorted)
	for (typename std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		result.push_back(it->second);
	}

	// Insert the smaller elements into the correct positions
	for (typename std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		typename Container::iterator insertPos = std::lower_bound(result.begin(), result.end(), it->first);
		result.insert(insertPos, it->first);
	}
}