#include "Span.hpp"

Span::Span() : _arr(), _size(0)
{
}

Span::Span(unsigned int n) : _arr(), _size(n)
{
}

Span::Span(const Span &span)
{
	*this = span;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &span)
{
	_size = span._size;
	_arr = span._arr;
	return *this;
}

void Span::addNumber(int n)
{
	if (_arr.size() >= _size)
		throw Span::maxSizeReached();
	_arr.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (_arr.size() == 0)
		throw Span::notFound();
	if (_arr.size() == 1)
		throw Span::onlyOneElement();
	std::sort(_arr.begin(), _arr.end());
	unsigned int min = UINT_MAX;
	for (unsigned int i = 1; i < _arr.size(); i++)
	{
		if (static_cast<unsigned int>(_arr[i] - _arr[i - 1]) < min)
			min = _arr[i] - _arr[i - 1];
	}
	return min;
}

unsigned int Span::longestSpan()
{
	if (_arr.size() == 0)
		throw Span::notFound();
	if (_arr.size() == 1)
		throw Span::onlyOneElement();
	std::sort(_arr.begin(), _arr.end());
	return _arr[_arr.size() - 1] - _arr[0];
}

