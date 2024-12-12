#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat b1("b1", 1);
		//Bureaucrat b2("b2", 150);
		
		std::cout << b1 << std::endl;
		//std::cout << b2 << std::endl;
		
		b1.incrementGrade();
		//b2.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}