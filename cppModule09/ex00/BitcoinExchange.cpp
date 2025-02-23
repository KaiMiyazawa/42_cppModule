#include "BitcoinExchange.hpp"

std::string trimSpaces(const std::string &str)
{
	size_t start = 0;
	size_t end = str.size();
	while (str[start] == ' ')
		start++;
	while (str[end - 1] == ' ')
		end--;
	return str.substr(start, end - start);
}

bool dateFormatCheck(const std::string &date)
{
	if (date.size() != 10)
		return true;
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				return true;
		}
		else if (date[i] < '0' || date[i] > '9')
			return true;
	}
	return false;
}

bool dateValidCheck(const std::string &date)
{
	int year;
	std::istringstream(date.substr(0, 4)) >> year;
	int month;
	std::istringstream(date.substr(5, 2)) >> month;
	int day;
	std::istringstream(date.substr(8, 2)) >> day;

	if (year < 2000 || year > 2100)
		return true;
	if (month < 1 || month > 12)
		return true;
	if (day < 1 || day > 31)
		return true;
	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			if (day > 29)
				return true;
		} else {
			if (day > 28)
				return true;
		}
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return true;
	}
	return false;
}

bool valueValueCheck(const std::string &value)
{
	bool dot = false;
	size_t i = 0;
	if (value[0] == '-')
		i++;
	
	if (value.size() == 0)
		return true;
	for (; i < value.size(); i++)
	{
		if (value[i] == '.')
		{
			if (dot)
				return true;
			dot = true;
		}
		else if (value[i] < '0' || value[i] > '9')
			return true;
	}
	return false;
}

// ======
// MARK: - BitcoinExchange
// ======
 
BitcoinExchange::BitcoinExchange() : _input_filename("input.txt")
{
	std::ifstream file(_input_filename.c_str());
	if (!file.is_open())
		throw FileOpenException();
		
	
	std::ifstream data_file("data.csv");
	if (!data_file.is_open())
		throw FileOpenException();
		
	std::string line;
	while (std::getline(data_file, line))
	{
		if (line == "date,exchange_rate")
			continue;
		//format: date,exchange_rate
		//format: YYYY-MM-DD,float
		// float exchange_rate = std::stof(line.substr(line.find(',') + 1));
		float exchange_rate;
		std::istringstream(line.substr(line.find(',') + 1)) >> exchange_rate;
		_csv_data[line.substr(0, line.find(','))] = exchange_rate;
	}
}

BitcoinExchange::BitcoinExchange(const std::string &filename) : _input_filename(filename)
{
	std::ifstream file(_input_filename.c_str());
	if (!file.is_open())
		throw FileOpenException();
		
	
	std::ifstream data_file("data.csv");
	if (!data_file.is_open())
		throw FileOpenException();
	
	std::string line;
	while (std::getline(data_file, line))
	{
		if (line == "date,exchange_rate")
			continue;
		//format: date,exchange_rate
		//format: YYYY-MM-DD,float
		// float exchange_rate = std::stof(line.substr(line.find(',') + 1));
		float exchange_rate;
		std::istringstream(line.substr(line.find(',') + 1)) >> exchange_rate;
		_csv_data[line.substr(0, line.find(','))] = exchange_rate;
	}
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _input_filename(other._input_filename), _csv_data(other._csv_data)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other) {
		BitcoinExchange tmp(other);
		tmp.swap(*this);
	}
	return *this;
}

void BitcoinExchange::swap(BitcoinExchange &other)
{
	std::swap(this->_input_filename, other._input_filename);
	std::swap(this->_csv_data, other._csv_data);
}

void BitcoinExchange::setFilename(const std::string &filename)
{
	this->_input_filename = filename;
	
	std::ifstream file(_input_filename.c_str());
	if (!file.is_open())
		throw FileOpenException();
}

float BitcoinExchange::calcPrice(float value, const std::string &date)
{
	// _csv_dataにdateがある場合、そのexchange_rateを使う
	if (_csv_data.find(date) != _csv_data.end())
		return value * _csv_data[date];
	
	// _csv_dataにdateがない場合、dateと最も近い過去の日付のexchange_rateを使う
	std::map<std::string, float>::reverse_iterator it = _csv_data.rbegin();
	for (; it != _csv_data.rend(); ++it)
	{
		if (it->first < date)
			return value * it->second;
	}
	return value * _csv_data.begin()->second;
}

void BitcoinExchange::display()
{
	std::ifstream file(_input_filename.c_str());
	if (!file.is_open())
		throw FileOpenException();
		
	std::string line;
	while (std::getline(file, line))
	{
		try {
			// first line: "date | value" => skip
			if (line == "date | value")
				continue;
			// main lines: "YYYY-MM-DD | value"
			// formatcheck => throw FileFormatException
			if (line.size() < 11 || line.find('|') == std::string::npos)
				throw FileFormatException(line);
			if (line[0] == '|' || line[line.size() - 1] == '|')
				throw FileFormatException(line);
			// '|' is only once
			if (line.find('|') != line.rfind('|'))
				throw FileFormatException(line);
			
			std::string date = line.substr(0, line.find('|'));
			std::string value_str = line.substr(line.find('|') + 1);
			// trim spaces
			date = trimSpaces(date);
			value_str = trimSpaces(value_str);
			// formatcheck
			if (dateFormatCheck(date) || dateValidCheck(date))
				throw FileInvalidDateException();
				
			if (valueValueCheck(value_str))
				throw FileFormatException(line);
			
			// convert value_str to float
			// float value = std::stof(value_str);
			// c++98
			float value;
			std::istringstream(value_str) >> value;
			
			// validcheck
			if (value <= 0)
				throw FileMinusValueException();
			if (value > 1000)
				throw FileTooLargeValueException();
				
			float price = this->calcPrice(value, date);
				
			std::cout << date << " => " << value << " = " << price << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
