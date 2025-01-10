#include "ScalarConverter.hpp"

char ScalarConverter::_c = '\0';
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
		_c = src._c;
		_i = src._i;
		_f = src._f;
		_d = src._d;
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

bool checkOverflowInt(std::string str)
{
	std::istringstream iss(str);
	long long int trueValue;
	iss >> trueValue;
	if (trueValue > INT_MAX || trueValue < INT_MIN)
		return (true);
	return (false);
}

bool checkOverflowFloat(std::string str)
{
	std::istringstream iss(str);
	long double trueValue;
	iss >> trueValue;
	if (trueValue > FLT_MAX || trueValue < -FLT_MAX)
		return (true);
	return (false);
}

bool checkOverflowDouble(std::string str)
{
	std::istringstream iss(str);
	long double trueValue;
	iss >> trueValue;
	if (trueValue > DBL_MAX || trueValue < -DBL_MAX)
		return (true);
	return (false);
}

void ScalarConverter::convert(std::string str)
{
	if (isNonDisplayableStr(str))
	{
		throw (ScalarConverter::NonDisplayableException());
		return ;
	}
	
	t_type t = judgeType(str);
	
	bool isOverflowInt = false;
	bool isOverflowFloat = false;
	bool isOverflowDouble = false;
	
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
		checkOverflowInt(str) ? isOverflowInt = true : 0;
		_i = stringToInt(str);
		checkOverflowFloat(str) ? isOverflowFloat = true : 0;
		_f = static_cast<float>(stringToFloat(str));
		checkOverflowDouble(str) ? isOverflowDouble = true : 0;
		_d = static_cast<double>(stringToDouble(str));
	} else if (t == FLOAT){
		std::string str_f = str.substr(0, str.length() - 1);
		checkOverflowInt(str_f) ? isOverflowInt = true : 0;
		_c = static_cast<char>(stringToInt(str_f));
		_i = static_cast<int>(stringToInt(str_f));
		checkOverflowFloat(str_f) ? isOverflowFloat = true : 0;
		_f = stringToFloat(str_f);
		checkOverflowDouble(str_f) ? isOverflowDouble = true : 0;
		_d = static_cast<double>(stringToDouble(str_f));
	} else if (t == DOUBLE){
		checkOverflowInt(str) ? isOverflowInt = true : 0;
		_c = static_cast<char>(stringToInt(str));
		_i = static_cast<int>(stringToInt(str));
		checkOverflowFloat(str) ? isOverflowFloat = true : 0;
		_f = static_cast<float>(stringToFloat(str));
		checkOverflowDouble(str) ? isOverflowDouble = true : 0;
		_d = stringToDouble(str);
	}
	
	if (_c < 32 || _c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _c << "'" << std::endl;
		
	if (isOverflowInt)
		std::cout << "int: Overflow" << std::endl;
	else
		std::cout << "int: " << _i << std::endl;
		
	std::ostringstream oss;
	oss << _f;
	std::string s = oss.str();
		
	if (isOverflowFloat)
		std::cout << "float: Overflow" << std::endl;
	else if (s.find('.') == std::string::npos)
		std::cout << "float: " << _f << std::endl;
	else
		std::cout << "float: " << _f << "f" << std::endl;
		
	if (isOverflowDouble)
		std::cout << "double: Overflow" << std::endl;
	else
		std::cout << "double: "  << _d << std::endl;
}