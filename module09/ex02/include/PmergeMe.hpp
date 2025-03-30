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
    std::vector<int> parseInputToVector(int ac, char **av);
    std::deque<int> parseInputToDeque(int ac, char **av);

    template <typename Container>
    void fordJohnsonSort(Container &numbers);

    template <typename Container>
    void mergePairs(std::vector<std::pair<int, int> > &pairs, Container &result);
};