#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
    std::cout << "AAnimal constructor called with no parameter" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
    std::cout << "AAnimal constructor called with parameter" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
    std::cout << "AAnimal operator= called" << std::endl;
    this->_type = copy._type;
    return *this;
}

std::string AAnimal::getType() const
{
    return this->_type;
}

//void AAnimal::makeSound() const
//{
//    std::cout << "AAnimal sound" << std::endl;
//}
