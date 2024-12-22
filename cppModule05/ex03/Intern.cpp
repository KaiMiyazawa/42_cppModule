#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	// 関数ポインタの配列
	AForm *(*createFunctions[3])(const std::string &target) = {
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

