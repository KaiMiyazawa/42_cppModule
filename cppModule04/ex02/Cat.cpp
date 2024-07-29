#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Cat constructor called with no parameter" << std::endl;

	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		this->_brain->setIdea(i, "sleep");
	}
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;

	delete this->_brain;
}

Cat::Cat(const Cat& copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat operator= called" << std::endl;
	this->_type = copy._type;
	/* shallow copy */
	//*this->_brain = *copy._brain;
	/* deep copy */
	this->_brain = new Brain(*copy._brain);

	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}