#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
	
	ShrubberyCreationForm();
	
public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm();
	
	void action() const;
	
	class FileNotOpenedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "File not opened";
		}
	};
};

#endif // SHRUBBERYCREATIONFORM_HPP