#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <ctime> // For clock()
#include <list>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();

	void processInput(int ac, char **av);

	// template <typename Container>
	// void outputContainer(const Container &result);

	template <typename Container>
	Container parseInputToContainer(int ac, char **av);

private:
	void fjsort_deque(std::deque<int> &numbers);
	void fjsort_list(std::list<int> &numbers);
	void fjsort_deque_without_jacobsthal(std::deque<int> &numbers);
	void fjsort_list_without_jacobsthal(std::list<int> &numbers);

	template <typename Container>
	void binaryInsert(Container &mainChain, int value);
};
