#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T* _array;
	unsigned int _size;
	
public:
	Array() : _array( new T[0] ), _size(0) {}
	Array(unsigned int n) : _array( new T[n] ), _size(n) {}
	Array(const Array &src) : _array( new T[src.size()] ), _size( src.size() )
	{
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	~Array() { delete [] _array; }
	Array &operator=(const Array &src)
	{
		if (this != &src)
		{
			delete [] _array;
			_array = new T[src.size()];
			_size = src.size();
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		return *this;
	}
	T &operator[](unsigned int i) const
	{
		if (i >= _size)
			throw OutOfBoundsException();
		return _array[i];
	}
	
	unsigned int size() const { return _size; }
	
	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw() { return "Index is out of bounds";}
	};
};



#endif