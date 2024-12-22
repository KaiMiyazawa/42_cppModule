#include "ScalarConverter.hpp"

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
	
	if (point && str.back() == 'f')
		return (FLOAT);
	else if (point && str.back() != 'f')
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
	} else if (t == P_INF){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	} else if (t == N_INF){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	} else if (t == CHAR){
		_c = str[0];
		_i = static_cast<int>(str[0]);
		_f = static_cast<float>(str[0]);
		_d = static_cast<double>(str[0]);
	} else if (t == INT){
		_c = static_cast<char>(std::stoi(str));
		_i = std::stoi(str);
		_f = static_cast<float>(std::stoi(str));
		_d = static_cast<double>(std::stoi(str));
	} else if (t == FLOAT){
		_c = static_cast<char>(std::stof(str));
		_i = static_cast<int>(std::stof(str));
		_f = std::stof(str);
		_d = static_cast<double>(std::stof(str));
	} else if (t == DOUBLE){
		_c = static_cast<char>(std::stod(str));
		_i = static_cast<int>(std::stod(str));
		_f = static_cast<float>(std::stod(str));
		_d = std::stod(str);
	}
	
	if (_c < 32 || _c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _c << "'" << std::endl;
	std::cout << "int: " << _i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << _f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << _d << std::endl;
}