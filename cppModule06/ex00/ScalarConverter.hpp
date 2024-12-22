#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

typedef enum e_type
{
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	P_INF,
	N_INF,
	NANF
} t_type;

class ScalarConverter
{
private:
	static char _c;
	static int _i;
	static float _f;
	static double _d;
	
	ScalarConverter(); // must not be instancible
	//ScalarConverter(const std::string &str);
	
public:
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);
	
	static void convert(std::string str);
	
	class NonDisplayableException : public std::exception{
	public:
		virtual const char *what() const throw(){
			return "Non displayable";
		};
	}
}



#endif // SCALARCONVERTER_HPP