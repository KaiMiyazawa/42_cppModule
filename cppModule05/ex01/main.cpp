#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try {
		Bureaucrat b1("b1", 1);
		Form f1("f1", 1, 1);
		
		b1.signForm(f1);
		
		std::cout << f1 << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}