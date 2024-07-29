#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called with no parameter" << std::endl;

	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		this->_brain->setIdea(i, "bark");
	}
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;

	delete this->_brain;
}

Dog::Dog(const Dog& copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog operator= called" << std::endl;
	this->_type = copy._type;
	/* shallow copy */
	//*this->_brain = *copy._brain;
	/* deep copy */
	this->_brain = new Brain(*copy._brain);

	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}