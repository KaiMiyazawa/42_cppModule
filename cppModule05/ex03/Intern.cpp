#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *makeShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &name, std::string const &target)
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	// 関数ポインタの配列
	AForm *(*createFunctions[3])(std::string const &target) = {
		&makeShrubberyCreationForm,
		&makeRobotomyRequestForm,
		&makePresidentialPardonForm
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return createFunctions[i](target);
		}
	}
	std::cout << "Intern cannot create " << name << std::endl;
	return NULL;
}

