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
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
	
	void execute(const Bureaucrat &executor) const;
	
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