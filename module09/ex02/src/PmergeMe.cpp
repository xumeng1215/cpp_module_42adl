#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::merge(int ac, char **av)
{
	// Parse input into a vector and a deque
	std::vector<int> numbersVector = parseInputToContainer<std::vector<int> >(ac, av);
	std::deque<int> numbersDeque = parseInputToContainer<std::deque<int> >(ac, av);

	std::clock_t t1, t2;
	// Sort using std::vector and measure time
	t1 = std::clock();
	fordJohnsonSort(numbersVector);
	t2 = std::clock();
	double elapsedVector = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

	// Sort using std::deque and measure time
	t1 = std::clock();
	fordJohnsonSort(numbersDeque);
	t2 = std::clock();
	double elapsedDeque = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

	// Output the sorted numbers for std::vector
	std::cout << "Sorted numbers (vector): ";
	outputContainer(numbersVector);
	std::cout << "Time taken (vector): " << elapsedVector << " ms" << std::endl;

	// Output the sorted numbers for std::deque
	std::cout << "Sorted numbers (deque): ";
	outputContainer(numbersDeque);
	std::cout << "Time taken (deque): " << elapsedDeque << " ms" << std::endl;

}

template <typename Container>
Container PmergeMe::parseInputToContainer(int ac, char **av)
{
	Container numbers;

	for (int i = 1; i < ac; ++i)
	{
		std::string arg(av[i]);
		int num;

		std::istringstream iss(arg);
		if (!(iss >> num) || !iss.eof())
			throw std::invalid_argument("Invalid input: " + arg);
		numbers.push_back(num);
	}

	return numbers;
}

template <typename Container>
void PmergeMe::outputContainer(const Container &result)
{
	for (typename Container::const_iterator it = result.begin(); it != result.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 != result.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &numbers)
{
	bool unpaired_flag = false;
	int last_element = 0;

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
			// Handle the case where there is an odd number of elements
			unpaired_flag = true;
			last_element = first;
		}
	}

	// Step 2: Sort the larger elements of the pairs
	Container largerElements;
	for (typename std::vector<std::pair<int, int> >::iterator pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt)
		largerElements.push_back(pairIt->second);
	std::sort(largerElements.begin(), largerElements.end());

	// std::cout << "Larger elements: ";
	// outputContainer(largerElements);

	// Step 3: Merge the smaller elements into the sorted larger elements
	Container result;
	mergePairs(pairs, result);

	// std::cout << "Merged pairs: ";
	// outputContainer(result);

	// Step 3.5: If there was an unpaired element, insert it into the correct position
	if (unpaired_flag)
	{
		typename Container::iterator insertPos = std::lower_bound(result.begin(), result.end(), last_element);
		result.insert(insertPos, last_element);
	}

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
		// outputContainer(result);
	}

	// Insert the smaller elements into the correct positions
	for (typename std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		typename Container::iterator insertPos = std::lower_bound(result.begin(), result.end(), it->first);
		result.insert(insertPos, it->first);
		// outputContainer(result);
	}
}