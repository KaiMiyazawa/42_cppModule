#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal constructor called with no parameter" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal constructor called with parameter" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
    std::cout << "Animal operator= called" << std::endl;
    this->_type = copy._type;
    return *this;
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}
