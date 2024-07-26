#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

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

//virtual functions are functions in the base class.
//Animal単体ではmakeSound()は呼び出せないが、
//Animalの派生クラスであるDogやCatではmakeSound()を呼び出すことができる。

#endif