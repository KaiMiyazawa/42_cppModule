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
	std::string const _name;
	bool _signed;
	int const _signGrade;
	int const _execGrade;
	
	
public:
	Form();
	Form(std::string const &name, int signGrade, int execGrade);
	Form(Form const &other);
	Form &operator=(Form const &other);
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

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif // FORM_HPP