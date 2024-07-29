#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    //const AAnimal* meta = new AAnimal();
    //meta->makeSound();
    //delete meta;

    const AAnimal* i = new Cat();
    const AAnimal* j = new Dog();
    std::cout << "i type :" << i->getType() << " " << std::endl;
    std::cout << "j type :" << j->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();

    delete i;
    delete j;

    std::cout << "====================" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    wrongMeta->makeSound();
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongCat;

    std::cout << "====================" << std::endl;

    Dog basic;
    std::cout << "--------------------" << std::endl;
    {
        Dog tmp = basic;
    }
    std::cout << "--------------------" << std::endl;
    const AAnimal* animals[2] = {new Dog(), new Cat()};
    for (int i = 0; i < 2; i++)
    {
        animals[i]->makeSound();
        delete animals[i];
    }
    std::cout << "--------------------" << std::endl;

    return 0;
}