#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

class notFound : public std::exception
{
public:
	const char *what() const throw()
	{
		return "Value not found";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw notFound();
	return it;
}

#endif