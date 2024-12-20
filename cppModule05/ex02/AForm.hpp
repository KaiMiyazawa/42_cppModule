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
	std::string const _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;
	
	
public:
	AForm();
	AForm(std::string const &name, int signGrade, int execGrade);
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	virtual ~AForm();
	
	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
	
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

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif // AFORM_HPP