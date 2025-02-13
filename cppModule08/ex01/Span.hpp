#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span
{
private:
	std::vector<int> _arr;
	unsigned int _size;
	
	Span();

public:
	Span(unsigned int n);
	Span(const Span &span);
	~Span();
	Span &operator=(const Span &span);
	
	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	
	class maxSizeReached: public std::exception
	{
	public:
		const char * what() const throw()
		{
			return "Vector is full";
		}
	};
	
	class notFound: public std::exception
	{
	public:
		const char * what() const throw()
		{
			return "Element is not found";
		}
	};
	
	class onlyOneElement: public std::exception
	{
	public:
		const char * what() const throw()
		{
			return "Only one element in the vector";
		}
	};
};

#endif