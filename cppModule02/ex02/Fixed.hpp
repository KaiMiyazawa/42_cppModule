
#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();

		int		getRawBits(void) const;
		void 	setRawBits(int const raw);

		float 	toFloat(void) const;
		int 	toInt(void) const;

		bool operator>(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;

		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;

		Fixed&	operator++(); //pre-increment
		Fixed	operator++(int); //post-increment
		Fixed&	operator--(); //pre-decrement
		Fixed	operator--(int); //post-decrement

		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif


// Add public member functions to your class to overload the following operators:
// • The 6 comparison operators: >, <, >=, <=, == and !=.
// • The 4 arithmetic operators: +, -, *, and /.
// • The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
// post-decrement) operators, that will increase or decrease the fixed-point value from
// the smallest representable ε such as 1 + ε > 1.

// Add these four public overloaded member functions to your class:
// • A static member function min that takes as parameters two references on fixed-point
// numbers, and returns a reference to the smallest one.
// • A static member function min that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the smallest one.
// • A static member function max that takes as parameters two references on fixed-point
// numbers, and returns a reference to the greatest one.
// • A static member function max that takes as parameters two references to constant
// fixed-point numbers, and returns a reference to the greatest one.