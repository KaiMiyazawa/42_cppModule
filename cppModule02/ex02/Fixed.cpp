#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedPointValue(value << Fixed::_fractionalBits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << Fixed::_fractionalBits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPointValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedPointValue) / (1 << Fixed::_fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> Fixed::_fractionalBits;
}

//============ Comparison operators ============

bool Fixed::operator>(const Fixed &fixed) const
{
	return this->_fixedPointValue > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return this->_fixedPointValue < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return this->_fixedPointValue >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return this->_fixedPointValue <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return this->_fixedPointValue == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return this->_fixedPointValue != fixed.getRawBits();
}

//============ Arithmetic operators ============

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

//============ Increment/Decrement operators ============

Fixed &Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

//============ Min/Max functions ============

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

//============ Output stream operator ============

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}