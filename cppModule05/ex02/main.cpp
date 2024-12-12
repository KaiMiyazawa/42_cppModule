#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	ShrubberyCreationForm shrubberyCreationForm("ShrubberyCreationForm");
	RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm");
	PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm");

	std::cout << bureaucrat << std::endl;
	std::cout << shrubberyCreationForm << std::endl;
	std::cout << robotomyRequestForm << std::endl;
	std::cout << presidentialPardonForm << std::endl;

	try
	{
		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.signForm(presidentialPardonForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		bureaucrat.executeForm(shrubberyCreationForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(presidentialPardonForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}