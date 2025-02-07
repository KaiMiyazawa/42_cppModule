#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <chrono>
#include <sys/time.h>

template <typename T>
class PmergeMe {
private:
	T _sequence;
	long _time_start;
	long _time_elapsed;
	
public:
	PmergeMe();
	PmergeMe(std::string sequence);
	~PmergeMe();
	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	
	T getSequence() const;

	void printSequence();
	void sort();
	void benchmark();
};

#endif