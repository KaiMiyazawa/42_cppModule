#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(1), _execGrade(1)
{
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
	return out;
}
