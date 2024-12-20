#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	{
		Intern soneRandomIntern;
		AForm *rrf;
		
		rrf = soneRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	
	std::cout << std::endl;
	
	AForm *form;
	try {
		Intern someRandomIntern;
		Bureaucrat bureaucrat("Bureaucrat", 1);
		
		form = someRandomIntern.makeForm("shrubbery creation", "Bender");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
		
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
		
		form = someRandomIntern.makeForm("presidential pardon", "Bender");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		// form -> robotomyなら、deleteしないとリークする
		if (form)
			delete form;
		std::cerr << e.what() << std::endl;
	}

	return 0;
}