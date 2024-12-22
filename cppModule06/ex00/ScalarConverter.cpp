#include "ScalarConverter.hpp"

char ScalarConverter::_c = 0;
int ScalarConverter::_i = 0;
float ScalarConverter::_f = 0.0f;
double ScalarConverter::_d = 0.0;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

int stringToInt(const std::string& str) {
    std::istringstream iss(str);
    int result;
    iss >> result;
    return result;
}

float stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    float result;
    iss >> result;
    return result;
}

double stringToDouble(const std::string& str) {
    std::istringstream iss(str);
    double result;
    iss >> result;
    return result;
}


int isNonDisplayableStr(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < 32 || str[i] > 126)
			return (1);
	}
	return (0);
}

t_type judgeType(std::string str)
{
	if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		return (NANF);
	else if (str.compare("+inf") == 0 || str.compare("+inff") == 0)
		return (P_INF);
	else if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
		return (N_INF);
		
	size_t i = 0;
	bool point = false;
	bool isChar = false;

	if (str[i] == '-')
		i++;
	
	for (; i < str.length(); i++)
	{
		if (!point && str[i] == '.')
			point = true;
		else if (str[i] >= '0' && str[i] <= '9')
			;
		else
			isChar = true;
	}
	
	if (point && str[str.length() - 1] == 'f')
		return (FLOAT);
	else if (point && str[str.length() - 1] != 'f')
		return (DOUBLE);
	else if (isChar)
		return (CHAR);
	else
		return (INT);
}

void ScalarConverter::convert(std::string str)
{
	if (isNonDisplayableStr(str))
	{
		throw (ScalarConverter::NonDisplayableException());
		return ;
	}
	
	t_type t = judgeType(str);
	
	if (t == NANF){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	} else if (t == P_INF){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return ;
	} else if (t == N_INF){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	} else if (t == CHAR){
		_c = str[0];
		_i = static_cast<int>(str[0]);
		_f = static_cast<float>(str[0]);
		_d = static_cast<double>(str[0]);
	} else if (t == INT){
		_c = static_cast<char>(stringToInt(str));
		_i = stringToInt(str);
		_f = static_cast<float>(stringToInt(str));
		_d = static_cast<double>(stringToInt(str));
	} else if (t == FLOAT){
		_c = static_cast<char>(stringToFloat(str));
		_i = static_cast<int>(stringToFloat(str));
		_f = stringToFloat(str);
		_d = static_cast<double>(stringToFloat(str));
	} else if (t == DOUBLE){
		_c = static_cast<char>(stringToDouble(str));
		_i = static_cast<int>(stringToDouble(str));
		_f = static_cast<float>(stringToDouble(str));
		_d = stringToDouble(str);
	}
	
	if (_c < 32 || _c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _c << "'" << std::endl;
	std::cout << "int: " << _i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << _f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << _d << std::endl;
}