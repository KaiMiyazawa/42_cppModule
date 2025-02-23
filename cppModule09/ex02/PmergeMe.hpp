#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>
#include <sys/time.h>
#include <typeinfo>
#include <utility>
//#include "Integer.hpp"//for-test

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
	
	void swap(PmergeMe &other);
	
	T getSequence() const;

	void printSequence();
	void sort();
	void benchmark();
};

#endif