#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called with no parameter" << std::endl;

	this->_brain = new Brain();
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;

	delete this->_brain;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	std::cout << "WrongCat operator= called" << std::endl;
	this->_type = copy._type;
	/* shallow copy */
	*this->_brain = *copy._brain;
	/* deep copy */
	// this->_brain = new Brain(*copy._brain);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}