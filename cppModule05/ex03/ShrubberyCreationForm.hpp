#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
	
	
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm();
	
	void execute(Bureaucrat const &executor) const;
	
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