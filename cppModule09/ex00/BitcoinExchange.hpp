#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <exception>
#include <cmath>
#include <string>
#include <utility>

class BitcoinExchange
{
private:
	std::string _input_filename;
	std::map<std::string, float> _csv_data;
	
	float calcPrice(float value, const std::string &date);
public:
	BitcoinExchange();
	BitcoinExchange(const std::string &filename);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	
	void swap(BitcoinExchange &other);
	
	void setFilename(const std::string &filename);
	void display();
	
	class FileOpenException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error: could not open file";
		}
	};
	class FileFormatException : public std::exception
	{
	private:
		std::string _msg;
		
	public:
		FileFormatException(const std::string &line) : _msg("Error: bad input => " + line) {}
		
		virtual ~FileFormatException() throw() {}
		
		virtual const char *what() const throw()
		{
			return _msg.c_str();
		}
	};
	class FileInvalidDateException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error: not valid date.";
		}
	};
	class FileMinusValueException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error: not a positive number.";
		}
	};
	class FileTooLargeValueException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "Error: too large a number";
		}
	};
};

#endif // BITCOINEXCHANGE_HPP