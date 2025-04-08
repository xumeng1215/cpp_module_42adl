#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

static void output_list(std::list<int> &result)
{
	std::cout << "List container: ";
	std::list<int>::iterator it = result.begin();
	while (it != result.end())
	{
		std::cout << *it;
		++it;
		if (it!= result.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

static void output_deque(std::deque<int> &result)
{
	std::cout << "Deque container: ";
	size_t i = 0;
	while (i < result.size())
	{
		std::cout << result[i];
		++i;
		if (i < result.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

static std::vector<size_t> getInsertSequence(size_t pendSize)
{
	std::vector<size_t> sequence;
	if (pendSize == 0)
		return sequence;

	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0); // J(0) is always 0
	if (pendSize >= 1)
		jacobsthal.push_back(1); // if pendSize >= 1, J(1) is 1

	// Continue generating Jacobsthal numbers until exceeding pendSize
	size_t next;
	while (true)
	{
		next = jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next > pendSize)
			break;
		jacobsthal.push_back(next);
	}

	// Generate sequence using Jacobsthal numbers (starting from J(2))
	for (size_t i = 1; i < jacobsthal.size(); ++i)
	{
		// Insert elements between J(i-1) and J(i) in reverse order as insertion indexes
		for (size_t j = jacobsthal[i]; j > jacobsthal[i - 1]; --j)
		{
			if (j - 1 < pendSize)
				sequence.push_back(j - 1);
		}
	}

	// Add any remaining elements not covered by Jacobsthal numbers
	for (size_t j = jacobsthal.back() + 1; j <= pendSize; ++j)
	{
		sequence.push_back(j - 1);
	}

	return sequence;
}

void PmergeMe::processInput(int ac, char **av)
{
	// Parse input into a deque and a list
	// deque have random access while list doesn't
	std::deque<int> d = parseInputToContainer<std::deque<int> >(ac, av);
	std::list<int> l = parseInputToContainer<std::list<int> >(ac, av);
	std::clock_t t1, t2;
	
	output_deque(d);
	output_list(l);

	// Sort using std::deque and measure time
	t1 = std::clock();
	fjsort_deque(d);
	t2 = std::clock();
	double elapsedDeque = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

	// Sort using std::list and measure time
	t1 = std::clock();
	fjsort_list(l);
	t2 = std::clock();
	double elapsedList = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

	output_deque(d);
	output_list(l);
	std::cout << "Time taken (deque): " << elapsedDeque << " ms" << std::endl;
	std::cout << "Time taken (list): " << elapsedList << " ms" << std::endl;
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

void PmergeMe::fjsort_deque(std::deque<int> &numbers)
{
	if (numbers.size() <= 1)
		return;
	
	// SPLIT THE NUMBERS INTO MAIN CHAIN AND PENDING ELEMENTS
	std::deque<int> mainChain, pend;
	bool isOdd = numbers.size() % 2 != 0;

	for (size_t i = 0; i < numbers.size() - isOdd; i += 2)
	{
		if (numbers[i] < numbers[i + 1])
		{
			mainChain.push_back(numbers[i + 1]);
			pend.push_back(numbers[i]);
		}
		else
		{
			mainChain.push_back(numbers[i]);
			pend.push_back(numbers[i + 1]);
		}
	}
	if (isOdd) // If the size is odd, add the last element to pend
		pend.push_back(numbers.back());

	// RECURSIVE SORTING THE MAIN CHAIN
	fjsort_deque(mainChain);

	// ADD PENDING ELEMENTS
	if (pend.empty())
		return;

	// Generate the insertion sequence using Jacobsthal numbers
	std::vector<size_t> insertSequence = getInsertSequence(pend.size());
	for (size_t i = 0; i < insertSequence.size(); ++i)
	{
		std::deque<int>::iterator insertPosition = std::lower_bound(mainChain.begin(), mainChain.end(), pend[insertSequence[i]]);
		mainChain.insert(insertPosition, pend[insertSequence[i]]);
	}
	numbers = mainChain;
}

void PmergeMe::fjsort_list(std::list<int> &numbers)
{
	if (numbers.size() <= 1)
		return;

	std::list<int> mainChain, pend;
	bool isOdd = numbers.size() % 2 != 0;

	// List doesn't have random access using operator []
	// So we need to use iterators to access elements
	std::list<int>::iterator it = numbers.begin();
	for (size_t i = 0; i < numbers.size() - isOdd; i += 2)
	{
		std::list<int>::iterator it1 = it++;
		std::list<int>::iterator it2 = it++;
		if (*it1 < *it2)
		{
			mainChain.push_back(*it2);
			pend.push_back(*it1);
		}
		else
		{
			mainChain.push_back(*it1);
			pend.push_back(*it2);
		}
	}
	if (isOdd)
		pend.push_back(numbers.back());

	fjsort_list(mainChain);

	if (pend.empty())
		return;
	std::vector<size_t> insertSequence = getInsertSequence(pend.size());
	for (size_t i = 0; i < insertSequence.size(); ++i)
	{
		std::list<int>::iterator it = pend.begin();
		std::advance(it, insertSequence[i]);

		std::list<int>::iterator insertPosition = std::lower_bound(mainChain.begin(), mainChain.end(), *it);
		mainChain.insert(insertPosition, *it);
	}
	numbers = mainChain;
}
