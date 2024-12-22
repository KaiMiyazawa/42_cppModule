#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(1), _execGrade(1)
{
}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
	return out;
}