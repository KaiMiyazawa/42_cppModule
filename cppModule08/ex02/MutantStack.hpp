#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
private:
public:
	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack &src) { *this = src; };
	MutantStack &operator=(const MutantStack &src)
	{
		if (this == &src)
			return *this;
		std::stack<T, Container>::operator=(src);
		return *this;
	}
	
	typedef typename Container::iterator iterator;
	iterator begin() { return std::stack<T, Container>::c.begin(); }
	iterator end() { return std::stack<T, Container>::c.end(); }
};

#endif