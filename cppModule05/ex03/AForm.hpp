#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
	
	
public:
	AForm();
	AForm(const std::string &name, int signGrade, int execGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	
	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;
	
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade is too high";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Grade is too low";
		}
	};
	class AFormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "AForm is not signed";
		}
	};
	
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif // AFORM_HPP