#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal& copy);
        Animal& operator=(const Animal& copy);
        std::string getType() const;
        virtual void makeSound() const;
};

#endif