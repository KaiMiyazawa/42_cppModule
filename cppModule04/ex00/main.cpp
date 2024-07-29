#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    std::cout << "i type :" << i->getType() << " " << std::endl;
    std::cout << "j type :" << j->getType() << " " << std::endl;
    meta->makeSound();
    i->makeSound(); //will output the cat sound!
    j->makeSound();

    delete meta;
    delete i;
    delete j;

    std::cout << "====================" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    wrongMeta->makeSound();
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}