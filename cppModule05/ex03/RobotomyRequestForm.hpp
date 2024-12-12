#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;
	
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();
	
	void action() const;
	
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