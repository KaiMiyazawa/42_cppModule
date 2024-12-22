#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;
	

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();
	
	void execute(const Bureaucrat &executor) const;
	
	class RobotomizationFailedException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Robotomization failed";
		}
	};
};

#endif // ROBOTOMYREQUESTFORM_HPP