#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <utility> // For std::pair
#include <ctime>   // For clock()

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();

	void merge(int ac, char **av);

private:
	template <typename Container>
	Container parseInputToContainer(int ac, char **av);

	template <typename Container>
	void fordJohnsonSort(Container &numbers);

	template <typename Container>
	void mergePairs(std::vector<std::pair<int, int> > &pairs, Container &result);

	template <typename Container>
	void outputContainer(const Container &result);
};