#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
	
	
public:
	Form();
	Form(const std::string &name, int signGrade, int execGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	
	std::string getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	
	void beSigned(const Bureaucrat &bureaucrat);
	
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
	
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif // FORM_HPP